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
using pll=pair<ll, ll>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;

struct Node
{
	int u, v, w;
	bool operator<(const Node &T)const
	{ return w<T.w; }
};

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		vector<Node> e(n);
		vector<int> p(n+1), sz(n+1);
		for(int i=1, u, v, w; i<=n-1; i++)
		{
			cin>>u>>v>>w;
			e[i]={u, v, w};	
		}
		for(int i=1; i<=n; i++) p[i]=i, sz[i]=1;
		// auto find =
		// [
			// f=[&](auto &&self, int x)
			// {
				// if(x==p[x]) return x;
				// return p[x]=self(self, p[x]);
			// }
		// ](int x){ return f(f, x); };
		function<int(int)> find=[&](int x)
		{
			if(x==p[x]) return x;
			return p[x]=find(p[x]);
		};
		sort(e.begin()+1, e.end());
		int res=0;
		for(int i=1; i<=n-1; i++)
		{
			int fu=find(e[i].u), fv=find(e[i].v);
			if(fu!=fv)
			{
				res+=(sz[fu]*sz[fv]-1)*(e[i].w+1);
				p[fv]=fu;
				sz[fu]+=sz[fv];
			}
		}
		cout<<res<<endl;
	}
	return 0;
}
