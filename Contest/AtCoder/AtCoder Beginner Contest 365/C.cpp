// Problem: C - Minimum Glutton
// Contest: AtCoder - Japan Registry Services (JPRS) Programming Contest 2024#2 (AtCoder Beginner Contest 364)
// URL: https://atcoder.jp/contests/abc364/tasks/abc364_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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


using lll=__int128;
using ll=long long;
using ld=long double;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n;
	ll ta, tb;
	cin>>n>>ta>>tb;
	vector<ll> a(n+1), b(n+1);
	for(int i=1; i<=n; i++)
		cin>>a[i];
	for(int i=1; i<=n; i++)
		cin>>b[i];
	sort(a.begin()+1, a.end(), greater<int>());
	sort(b.begin()+1, b.end(), greater<int>());
	int cnta=n, cntb=n;
	ll suma=0, sumb=0;
	for(int i=1; i<=n; i++)
	{
		if(suma+a[i]<=ta) suma+=a[i];
		else
		{
			cnta=i;
			break;
		}
	}
	for(int i=1; i<=n; i++)
	{
		if(sumb+b[i]<=tb) sumb+=b[i];
		else
		{
			cntb=i;
			break;
		}
	}
	cout<<min(cnta, cntb)<<endl;
	return 0;
}
