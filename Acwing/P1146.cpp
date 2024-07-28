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
constexpr int N=310;

int n;
int w[N];
int g[N][N], dist[N];
bool vis[N];

int prim()
{
	int res=0;
    fill(dist+1, dist+n+1, inf);
    for(int i=1; i<=n+1; i++)
    {
        int t=-1;
        for(int j=0; j<=n; j++)
        {
            if(!vis[j] && (t==-1 || dist[j]<dist[t]))
                t=j;
        }
        vis[t]=1;
        res+=dist[t];
        
		for(int j=0; j<=n; j++)
        {
            if(dist[j]>g[t][j] && !vis[j])
            {
                dist[j]=g[t][j];
            }
        }
    }
    return res;
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	for(int i=1; i<=n; i++)
	    cin>>w[i];
	for(int i=1; i<=n; i++)
	{
	    g[0][i]=g[i][0]=w[i];
		for(int j=1; j<=n; j++)
		{
		    cin>>g[i][j];
		}
	}
	cout<<prim()<<endl;
	return 0;
}
