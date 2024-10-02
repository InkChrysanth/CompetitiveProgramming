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

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    int n, q;
    cin>>n>>q;
    vector<int> p(n+1);
    vector<set<int>> g(n+1);
	for(int i=1; i<=n; i++)
		p[i]=i, g[i].em(i);
    function<int(int)> find=[&](int x)
	{ return x==p[x] ? x : p[x]=find(p[x]); };
	while(q--)
	{
		int opt, u, v;
		cin>>opt>>u>>v;
		if(opt==1)
		{
			int fu=find(u), fv=find(v);
			if(fu!=fv)
			{
				if(g[fu].size()<g[fv].size())
					swap(fu, fv);
				p[fv]=fu;
				g[fu].insert(g[fv].begin(), g[fv].end());
			}
		}
		else
		{
			int fu=find(u);
			if(v>g[fu].size()){ cout<<-1<<endl; continue; }
			auto ptr=g[fu].end();
			cout<<*prev(ptr, v)<<endl;
		}
	}
	return 0;
}
