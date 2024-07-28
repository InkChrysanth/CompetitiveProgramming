#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
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
constexpr int N=510;

int n, k;
pii pts[N];
bool vis[N];
double g[N][N], dist[N];
vector<double> ans;
double get(int i, int j)
{ return sqrt(1.0*(pts[i].fi-pts[j].fi)*(pts[i].fi-pts[j].fi)+(pts[i].se-pts[j].se)*(pts[i].se-pts[j].se)); }

void prim()
{
    fill(dist+1, dist+n+1, 1e9);
    dist[1]=0.0;
    for(int i=1; i<=n; i++)
    {
        int t=-1;
        for(int j=1; j<=n; j++)
        {
            if(!vis[j] && (t==-1 || dist[j]<dist[t]))
                t=j;
        }
        vis[t]=1;
        ans.eb(dist[t]);
        
		for(int j=1; j<=n; j++)
        {
            if(dist[j]>g[t][j] && !vis[j])
            {
                dist[j]=g[t][j];
            }
        }
    }
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	cout<<fixed<<setprecision(2);
	cin>>n>>k;
	for(int i=1; i<=n; i++) cin>>pts[i].fi>>pts[i].se;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			g[i][j]=get(i, j);
	prim();
	sort(all(ans));
	// each(x, ans) debug(x);
	if(k==0) cout<<(*ans.rbegin())<<endl;
	else cout<<(*next(ans.rbegin(), k-1))<<endl;
	return 0;
}
