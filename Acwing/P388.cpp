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
using pli=pair<ll, int>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;

struct Edge
{
	int u, v, w;
	bool operator<(const Edge &T)const{ return w<T.w; }
};

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin>>n>>m;

	vector<int> a(n), s(1<<n, 0);
	vector<Edge> E(m);

	for(int i=0; i<n; i++) cin>>a[i];
	for(int i=1; i<1<<n; i++)
		for(int j=0; j<n; j++)
			if((i>>j)&1)
				s[i]+=a[j];
	for(int i=0, u, v, w; i<m; i++)
	{
		cin>>u>>v>>w;
		E[i]={u, v, w};
	}
	sort(all(E));

	auto kruskal=[&](int st)
	{
		vector<int> p(n);
		function<int(int)> find=[&](int x)
		{
			if(x==p[x]) return x;
			return p[x]=find(p[x]);
		};
		for(int i=0; i<n; i++)
			if((st>>i)&1)
				p[i]=i;
		int res=0;
		each(e, E)
		{
			if((st>>e.u)&1 && (st>>e.v)&1)
			{
				int fu=find(e.u), fv=find(e.v);
				if(fu!=fv)
				{
					p[fv]=fu;
					res+=e.w;
				}
			}
		}
		int pid=-1;
		for(int i=0; i<n; i++)
			if((st>>i)&1)
			{
				if(pid==-1) pid=find(i);
				else if(pid!=find(i)) return inf;
			}
		return res;
	};
	vector<int> d(1<<n, inf);
	for(int i=1; i<(1<<n); i++)
		if(!s[i])
			d[i]=kruskal(i);
	vector<int> f(1<<n, inf);
	f[0]=0;
	for(int i=1; i<1<<n; i++)
		for(int j=i; j>=1; j=(j-1)&i)
			cmin(f[i], f[i^j]+d[j]);
	if(f[(1<<n)-1]==inf) cout<<"Impossible"<<endl;
	else cout<<f[(1<<n)-1]<<endl;
	return 0;
}
