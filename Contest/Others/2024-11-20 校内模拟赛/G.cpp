//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

#define cmin(i,j) (i)=min((i),(j))
#define cmax(i,j) (i)=max((i),(j))
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define all(x) x.begin(), x.end()
#define each(i,x) for(auto &i:(x))
#define fi first
#define se second
#define endl "\n"
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ins insert

using ll=long long;
using ull=unsigned long long;
using db=double;
using ld=long double;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

inline namespace FileIO{
void setIn(string s) { freopen(s.c_str(), "r", stdin); }
void setOut(string s) { freopen(s.c_str(), "w", stdout); }
void setIO(string s="")
{	
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	#ifndef LOCAL
        if(s.size()) setIn(s+".in"), setOut(s+".out");
	#else
        setIn("inkorange.in"), setOut("inkorange.out");
    #endif
}
}

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;
constexpr int dx[]={0, -1, 0, 1}, dy[]={1, 0, -1, 0};

struct Node
{
    int x, y, s;
    Node(int x, int y, int s): x(x), y(y), s(s){}    
};

signed main()
{
    setIO();
	int T; cin>>T;
    while(T--)
    {
        int n, m; cin>>n>>m;
        vector<vector<int>> h(n+1, vector<int>(m+1)),
                            cnt(n+1, vector<int>(m+1, -1));// -1: non-existent
        for(int i=1; i<=n; i++) for(int j=1; j<=m; j++)
            cin>>h[i][j];
        int ans=0;
        auto inbound=[&](int x, int y)
        { return x>=1 && x<=n && y>=1 && y<=m; };
        auto bfs=[&](int x, int y)
        {
            queue<Node> q;
            q.push(Node(x, y, 0));
            while(q.size())
            {
                auto t=q.front(); q.pop();
                // debug(t.x); debug(t.y);
                cmax(ans, t.s);
                if(t.s<=cnt[t.x][t.y]) continue;
                cnt[t.x][t.y]=t.s;
                for(int i=0; i<4; i++)
                {
                    int nx=t.x+dx[i], ny=t.y+dy[i];
                    if(inbound(nx, ny) && h[nx][ny]<=h[t.x][t.y])
                        q.push(Node(nx, ny, t.s+(h[nx][ny]!=h[t.x][t.y])));
                }
            }
        };
        for(int i=1; i<=n; i++) for(int j=1; j<=m; j++)
            bfs(i, j);
        cout<<ans<<endl;
    }
	return 0;
}
// bfs and similar