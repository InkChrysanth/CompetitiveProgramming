// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
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
#define fi first
#define se second
#define endl "\n"
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define em emplace

using ll=long long;
using ull=unsigned long long;
using ld=long double;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;
constexpr int N=410, M=200010;

int n, m, q;
struct Edge{ int u, v, w; } e[M];
ll d[N][N];

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
	memset(d, 0x3f, sizeof d);
	for(int i=1, u, v, w; i<=m; i++)
    {
    	cin>>u>>v>>w;
		d[u][v]=min(d[u][v], (ll)w);
        d[v][u]=min(d[v][u], (ll)w);
        e[i]={u, v, w};
	}
    for(int i=1; i<=n; i++)
		d[i][i]=0;
	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				cmin(d[i][j], d[i][k]+d[k][j]);
	cin>>q;
	while(q--)
	{
		int k;
		cin>>k;
		vector<int> ord(k);
		for(int i=0; i<k; i++)
            cin>>ord[i];
		ll ans=llinf;
		do
		{
            for(int t=0; t<(1<<k); t++)
            {
                int cur=1; ll res=0;
                for(int i=0; i<k; i++)
                {
                    int u=e[ord[i]].u, v=e[ord[i]].v, w=e[ord[i]].w;
                    if((t>>i)&1) swap(u, v);
                    res+=(d[cur][u]+w);
                    cur=v;
                }
                cmin(ans, res+d[cur][n]);
            }
		}while(next_permutation(all(ord)));
		cout<<ans<<endl;
	}
	return 0;
}