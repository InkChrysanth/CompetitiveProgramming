//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

#define cmin(i,j) (i)=min((i),(j))
#define cmax(i,j) (i)=max((i),(j))
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define all(x) x.begin(), x.end()
#define each(i,x) for(auto &i:(x))
#define fi first
#define se second
#define endl "\n"
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ins insert

using ll=long long;
using ull=unsigned long long;
using db=double;
using ld=long double;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

inline namespace FileIO{
void setIn(string s) { freopen(s.c_str(), "r", stdin); }
void setOut(string s) { freopen(s.c_str(), "w", stdout); }
void setIO(string s="")
{	
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	#ifndef LOCAL
        if(s.size()) setIn(s+".in"), setOut(s+".out");
	#else
        setIn("inkorange.in"), setOut("inkorange.out");
    #endif
}
}

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;
constexpr int mod=998244853;

signed main()
{
	setIO();
	int n, m;
    cin>>n>>m;
    string s; cin>>s; s="%"+s;
    ll ans=0;
    while(m--)
    {
        string t; cin>>t; t="%"+t;
        int len=t.size()-1;
        vector<ll> f(len+1, 0);
        for(int i=1; i<=n; i++)
        {
            f[0]++;
            if(s[i]=='*')
            {
                for(int j=1; j<=len; j++)
                    f[j]=(f[j]+f[j-1])%mod;
            }
            else
            {
                for(int j=len; j>=1; j--)
                {
                    if(t[j]==s[i]) f[j]=f[j-1];
                    else f[j]=0;
                }
                f[0]=0;
            }
            ans=(ans+f[len])%mod;
        }
    }
    cout<<ans<<endl;
	return 0;
}
