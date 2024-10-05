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
constexpr int mod=998244353;

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    Fre("aspect");//あなた達、Roseliaにすべてを賭ける覚悟はある?
    int n; string s;
    cin>>n>>s;
    vector<ll> f(n+1); f[n]=1;
    for(int i=0; i<n; i++)
    {
        vector<ll> _f(n+1);
        if(s[i]=='0')
        {
            ll sum=0;
            for(int j=n-i; j>=1; j--)
            {
                (sum+=f[j])%=mod;
                _f[j-1]=sum;
            }
            for(int j=n-i-1; j>=0; j--)
                (_f[j]+=f[j]*(n-i-j))%=mod;
        }
        else
        {
            for(int j=n-i; j>=1; j--)
                _f[j-1]=(f[j]*j)%mod;
        }
        swap(f, _f);
    }
    cout<<f[0]%mod<<endl;
    return 0;
}
// dp