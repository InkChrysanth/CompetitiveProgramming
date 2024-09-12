//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

#define int long long
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
    int T;
    cin>>T;
    while(T--)
    {
    	int n;
    	cin>>n;
    	vector<int> a(n+1);
    	map<int, int> cnt;
    	for(int i=1; i<=n; i++)
			cin>>a[i], cnt[a[i]]++;
		int mex=0;
		while(cnt[mex]) mex++;
		vector<int> f(mex+1, inf);
		f[mex]=0;
		for(int i=mex; i>=1; i--)
			for(int j=0; j<i; j++)
				cmin(f[j], f[i]+(cnt[j]-1)*i+j);
		cout<<f[0]<<endl;
	}
	return 0;
}
