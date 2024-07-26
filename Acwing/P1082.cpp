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
constexpr int N=11;

int l, r;
int num[N], f[N][N];

int dp(int pos, int pre, bool op)
{
	if(!pos) return 1;
	if(!op && ~f[pos][pre]) return f[pos][pre];
	int n=op ? num[pos] : 9, res=0;
	for(int i=pre; i<=n; i++) res+=dp(pos-1, i, op && i==num[pos]);
	return op ? res : f[pos][pre]=res;
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	auto calc=[&](int x)
	{
		memset(f, -1, sizeof f);
		int tot=0;
		while(x) num[++tot]=x%10, x/=10;
		return dp(tot, 0, 1);
	};
	while(cin>>l>>r) cout<<calc(r)-calc(l-1)<<endl;
	return 0;
}
