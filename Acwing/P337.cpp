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
using ull=unsigned long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;

ull f[14][14][14][14][4];

ull dp(int a, int b, int c, int d, int lst)
{
	if(a==0 && b==0 && c==0 && d==0) return 1;
	ull &v=f[a][b][c][d][lst];
	if(v!=-1llu) return v;
	v=0;
	if(a>0) v+=(ull)1*(a-(lst==1))*dp(a-1, b, c, d, 0);
	if(b>0) v+=(ull)2*(b-(lst==2))*dp(a+1, b-1, c, d, 1);
	if(c>0) v+=(ull)3*(c-(lst==3))*dp(a, b+1, c-1, d, 2);
	if(d>0) v+=(ull)4*(d-(lst==4))*dp(a, b, c+1, d-1, 3);
	return v;
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin>>T;
	auto get=[](char c)
	{
		if(c=='A') return 1;
		if(c=='T') return 10;
		if(c=='J') return 11;
		if(c=='Q') return 12;
		if(c=='K') return 13;
		return c-'0';
	};
	memset(f, -1, sizeof f);
	for(int i=1; i<=T; i++)
	{
	    cout<<"Case #"<<i<<": " ;
		map<int, int> hs;
		int n;
		cin>>n;
		string s;
		for(int i=1; i<=n; i++) cin>>s, hs[get(s[0])]++;
		map<int, int> cnt;
		for(int i=1; i<=13; i++) cnt[hs[i]]++;
// 		for(int i=1; i<=4; i++) debug(cnt[i]);
// 		cerr<<endl;
		cout<<dp(cnt[1], cnt[2], cnt[3], cnt[4], 0)<<endl;
	}
	return 0;
}
