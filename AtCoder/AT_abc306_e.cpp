//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define cmin(i,j) (i)=min((i),(j))
#define cmax(i,j) (i)=max((i),(j))
#define debug(val) cerr<<#val<<": "<<(val)<<endl
#define Fi(s) freopen(s,"r",stdin)
#define Fo(s) freopen(s,"w",stdout)
#define Fre(s) Fi(s".in"),Fo(s".out")
#define all(val) val.begin(), val.end()
#define each(i,val) for(auto &i:(val))
#define sz(val) int((val).size())
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

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n, k, q;
	cin>>n>>k>>q;
	multiset<int> s1, s2;
	for(int i=1; i<=k; i++) s1.insert(0);
	for(int i=1; i<=n-k; i++) s2.insert(0);
	vector<int> a(n+1, 0);
	ll ans=0;
	for(int i=1; i<=q; i++)
	{
		int pos, val;
		cin>>pos>>val;
		if(s1.find(a[pos])!=s1.end()) s1.erase(s1.find(a[pos])), ans-=a[pos];
		else s2.erase(s2.find(a[pos]));
		a[pos]=val;
		if(s2.size() && val>=*s2.rbegin()) s1.insert(val), ans+=val;
		else s2.insert(val);
		if(s1.size()>k)
		{
			s2.insert(*s1.begin());
			ans-=*s1.begin();
			s1.erase(s1.begin());
		}
		if(s1.size()<k)
		{
			s1.insert(*s2.rbegin());
			ans+=*s2.rbegin();
			s2.erase(next(s2.rbegin()).base());
		}
		cout<<ans<<endl;
	}
	return 0;
}
