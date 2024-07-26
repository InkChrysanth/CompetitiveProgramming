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
constexpr int N=11, M=100;

int num[N];
int f[N][M][M];

int dp(int pos, int sum, int mod, int val, bool op)
{
	if(!pos) return sum==mod && !val;
	if(!op && ~f[pos][sum][val]) return f[pos][sum][val];
	int n=op ? num[pos] : 9, res=0;
	for(int i=0; i<=n; i++) res+=dp(pos-1, sum+i, mod, (val*10+i)%mod, op && num[pos]==i);
	return op ? res : f[pos][sum][val]=res;
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int l, r;
	cin>>l>>r;
	auto calc=[](int x)
	{
		int tot=0;
		while(x) num[++tot]=x%10, x/=10;
		int res=0;
		for(int i=1; i<=10*9; i++)
		{
			memset(f, -1, sizeof f);
			res+=dp(tot, 0, i, 0, 1);
		}
		return res;
	};
	cout<<calc(r)-calc(l-1)<<endl;
	return 0;
}
