//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define cmin(i,j) (i)=min((i),(j))
#define cmax(i,j) (i)=max((i),(j))
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define Fi(s) freopen(s,"r",stdin)
#define Fo(s) freopen(s,"w",stdout)
#define Fre(s) Fi(s".in"),Fo(s".out")
#define all(x) x.begin(), x.end()
#define each(i,x) for(auto &i:(x))
#define sz(x) int((x).size())
#define fi first
#define se second
#define endl '\n'
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define eb emplace_back

using ll=long long;
using ld=long double;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;
constexpr int N=1010, M=100010;

int dx[5]={0, -1, 1, 0, 0};
int dy[5]={0, 0, 0, -1, 1};

struct Node
{
    int x, y, h;
    bool operator<(const Node &T)const
    {
        return h>T.h;
    }
};

int n, m, h;
int g[N][N], ans[M];
bool vis[N][N];

bool check(int x, int y)
{
    return x>0 && x<=n && y>0 && y<=m && !vis[x][y];
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m>>h;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin>>g[i][j];
    pq<Node> heap;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(i==1 || i==n || j==1 || j==m)
                heap.push({i, j, g[i][j]}), vis[i][j]=1;
    int cur=0;
    while(heap.size())
    {
        auto t=heap.top();
        heap.pop();
        // debug(t.h);
        if(t.h>cur) cur=t.h;
        ans[cur]++;
        for(int i=1; i<=4; i++)
        {
            int cx=t.x+dx[i], cy=t.y+dy[i];
            if(check(cx, cy))
            {
                vis[cx][cy]=1;
                heap.push({cx, cy, g[cx][cy]});
            }
        }
    }
    for(int i=1; i<=h; i++) ans[i]+=ans[i-1];
    for(int i=1; i<=h; i++) cout<<n*m-ans[i]<<endl;
    return 0;
}
