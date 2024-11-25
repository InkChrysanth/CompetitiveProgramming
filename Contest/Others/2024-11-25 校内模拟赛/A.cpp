// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

#define cmin(i,n) (i)=min((i),(n))
#define cmax(i,n) (i)=max((i),(n))
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
constexpr int N=2010;

bool f[N][N];

signed main()
{
    setIO();
    int T; cin>>T;
    while(T--)
    {
        string s, t; cin>>s>>t;
        // int ans=0;
        // regex m(t);
        // for(int i=1; i<=s.size(); i++)
        //     ans+=regex_match(s.substr(0, i), m), debug(s.substr(0, i));
        s="%"+s; t="%"+t;
        int n=s.size()-1, m=t.size()-1;
        memset(f, false, sizeof f);
        f[0][0]=true;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
            {
                if(s[i]==t[j] || t[j]=='.')
                    f[i][j]=f[i-1][j-1];
                if(t[j]=='*')
                    f[i][j]=f[i][j-1] || (f[i-1][j] && s[i]==s[i-1]);
            }
        // for(int i=1; i<=n; i++, cerr<<endl) for(int j=1; j<=m; j++) cerr<<f[i][j]<<" ";
        int res=0;
        for(int i=1; i<=n; i++) res+=f[i][m];
        cout<<res<<endl;
    }
    return 0;
}
// dp, strings