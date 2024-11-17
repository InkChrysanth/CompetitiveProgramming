//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

#define int long long
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

struct Node
{
	int s, t, id;
	Node(int s, int t, int id): s(s), t(t), id(id){}
};
signed main()
{
	setIO();
	int n, m; cin>>n>>m;
	pq<int, vector<int>, greater<int>> q1/*spare*/;
	pq<pii, vector<pii>, greater<pii>> q2/*non-spare*/; 
	for(int i=1; i<=m; i++)
		q1.push(i);
	
	vector<Node> qry;
	for(int i=1; i<=n; i++)
	{
		int s, t; cin>>s>>t;
		qry.eb(s, t, i);
	}
	sort(all(qry), [](Node x, Node y){ return x.t<y.t; });
	
	vector<vector<int>> ans(m+1);
	each(x, qry)
	{
		int t=x.t, s=x.s, id=x.id;
//		cerr<<t<<" "<<s<<" "<<id<<endl;
		while(q2.size() && q2.top().fi<=t)
		{
			q1.push(q2.top().se);
			q2.pop();
		}
		if(q1.size())
		{
			int p=q1.top(); q1.pop();
			ans[p].eb(id);
			q2.push(mp(t+s, p));
//			debug(t+s), debug(p);
		}
		else
		{
			pii p=q2.top(); q2.pop();
			ans[p.se].eb(id);
//			debug(p.se);
			q2.push(mp(p.fi+s, p.se));
		}
	}
	
	for(int i=1; i<=m; i++)
	{
		cout<<ans[i].size()<<" ";
		sort(all(ans[i]));
		each(x, ans[i]) cout<<x<<" ";
		cout<<endl;
	}
	return 0;
}
// greedy, implementation