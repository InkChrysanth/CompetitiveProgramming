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
constexpr int N=12;

int num[N];
ll f[N][N][2];

//len: amount of "6"
int dp(int pos, int len, bool op, bool flag)
{
	if(!pos) return flag;
	if(!op && ~f[pos][len][flag]) return f[pos][len][flag];
	ll res=0;
	int n=op ? num[pos] : 9;
	for(int i=0; i<=n; i++)
	{
		if(i==6)
		{
			if(len>=2) res+=dp(pos-1, len+1, op && i==num[pos], 1);
			else res+=dp(pos-1, len+1, op && i==num[pos], flag);
		}
		else res+=dp(pos-1, 0, op && i==num[pos], flag);
	}
	return op ? res : f[pos][len][flag]=res;
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin>>T;
	memset(f, -1, sizeof f);
	auto calc=[](ll x)
	{
		int tot=0;
		while(x) num[++tot]=x%10, x/=10;
		return dp(tot, 0, 1, 0);
	};
	while(T--)
	{
		int x;
		cin>>x;
		ll l=666, r=1e11, ans=1e11;
		while(l<=r)
		{
			ll mid=(l+r)>>1;
			if(calc(mid)>=x) r=mid-1, ans=mid;
			else l=mid+1;
		}
		cout<<ans<<endl;
	}
	return 0;
}
