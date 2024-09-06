//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
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

random_device seed;
mt19937_64 rnd(seed());

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    int n, m, q;
    cin>>n>>m;
    vector<ull> w(n+1);
	ull tar=0;
    for(int i=1; i<=n; i++) w[i]=rnd(), tar+=w[i];
	vector<ull> a(n+1, 0), b(n+1, 0);
	ull cur=0;
	for(int i=1, u, v; i<=m; i++)
	{
		cin>>u>>v;
		b[v]+=w[u];
		a[v]+=w[u];
		cur+=w[u];
	}
    cin>>q;
	for(int opt, u, v; q--;)
    {
        cin>>opt>>u;
        if(opt==1) cin>>v, cur-=w[u], a[v]-=w[u];
		else if(opt==2) cur-=a[u], a[u]=0;
		else if(opt==3) cin>>v, cur+=w[u], a[v]+=w[u];
		else cur+=(b[u]-a[u]), a[u]=b[u];
		cout<<(cur==tar ? "YES" : "NO")<<endl;
    }
    return 0;
}
