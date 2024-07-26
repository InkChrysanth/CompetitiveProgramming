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
constexpr int N=32;

int num[N];
int f[N][N][N];

int dp(int pos, int cnt0, int cnt1, bool lead, bool op)
{
	if(!pos) return cnt0>=cnt1;
	if(!op && !lead && ~f[pos][cnt0][cnt1]) return f[pos][cnt0][cnt1];
	int n=op ? num[pos] : 1, res=0;
	for(int i=0; i<=n; i++)
	{
		if(!i && !lead) res+=dp(pos-1, cnt0+1, cnt1, lead, op && num[pos]==i);
		else if(!i) res+=dp(pos-1, cnt0, cnt1, 1, op && num[pos]==i);
		else res+=dp(pos-1, cnt0, cnt1+1, 0, op && num[pos]==i);
	}
	return lead ? res : (op ? res : f[pos][cnt0][cnt1]=res);
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int l, r;
	cin>>l>>r;
	auto calc=[](int x)
	{
		memset(f, -1, sizeof f);
		int tot=0;
		while(x) num[++tot]=x&1, x>>=1;
		return dp(tot, 0, 0, 1, 1);
	};
	cout<<calc(r)-calc(l-1)<<endl;
	return 0;
}
