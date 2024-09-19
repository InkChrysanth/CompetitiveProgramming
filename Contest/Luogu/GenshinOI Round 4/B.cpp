//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
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
constexpr int N=500010, M=120*N;

vector<bool> vis(N), f(M);
//bitset<N> vis;
//bitset<M> f;

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    int T, n;
    cin>>T>>n;
    for(int i=0; i<=n*120; i++)
    {
    	if(vis[i%n]){ f[i]=true; continue; }
    	if(!f[i])
    	{
    		for(int j=1; j*j<n && i+j*j<=n*120; j++)
    			f[i+j*j]=true;
    		vis[i%n]=true;
		}
	}
	while(T--)
	{
		int x; cin>>x;
		cout<<((x>n*120) ? "F" : (f[x] ? "F" : "B"));
	}
	return 0;
}
