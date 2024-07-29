// Problem: P5517 [MtOI2019] 幻想乡数学竞赛
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P5517
// Memory Limit: 128 MB
// Time Limit: 1000 ms
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
#define fi first
#define se second
#define endl '\n'
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define eb emplace_back

using ll=long long;
using ull=unsigned long long;
using ld=long double;
using pii=pair<int, int>;
using pli=pair<ll, int>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;
constexpr int _32=281250002, MOD=1e9+7, P=31623;

namespace Mker
{
//  Powered By Kawashiro_Nitori
//  Made In Gensokyo, Nihon
	#include<climits>
	#define ull unsigned long long
	#define uint unsigned int
	ull sd;int op;
	inline void init() {scanf("%llu %d", &sd, &op);}
	inline ull ull_rand()
	{
		sd ^= sd << 43;
		sd ^= sd >> 29;
		sd ^= sd << 34;
		return sd;
	}
	inline ull rand()
	{
		if (op == 0) return ull_rand() % USHRT_MAX + 1;
		if (op == 1) return ull_rand() % UINT_MAX + 1; 
		if (op == 2) return ull_rand();
	}
}

ull pow1[P+10], pow2[P+10];
ull gsm(ull x){ return pow2[x/P]*pow1[x%P]%MOD; }

signed main()
{
	// cin.tie(0)->sync_with_stdio(0);
	int T;
	cin>>T;
	Mker::init();
	pow1[0]=pow2[0]=1;
	for(int i=1; i<=P; i++) pow1[i]=pow1[i-1]*3%MOD;
	for(int i=1; i<=P; i++) pow2[i]=pow2[i-1]*pow1[P]%MOD;
	ull ans=0;
	while(T--)
	{
		ull n=Mker::rand();
		int add=(n&1)?51:21;
		// n+2 可能爆 ull
		ans^=(1llu*_32*(((1llu*36%MOD*(n%MOD)-117+MOD)%MOD*gsm(n%(MOD-1)))%MOD+add)%MOD);
	}
	cout<<ans<<endl;
	return 0;
}
