#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
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

signed main()
{
    setIO();
    string s; cin>>s;
    int T; cin>>T;
    auto match=[](string s, string _s)
    {
        for(int i=0; i<min(s.size(), _s.size()); i++)
            if(s[i]!=_s[i])
                return i-1+1;
        return (int)min(s.size(), _s.size());
    };
    while(T--)
    {
        int k, l, r; cin>>k>>l>>r;
        if(k>=l && k<=r)
        {
            cout<<s.size()-k+1<<" "<<k<<endl;
            continue;
        }
        k--, l--, r--;// use 0-indexed
        string sub=s.substr(k);
        int res=0, pos; string ts="";
        for(int i=l; i<=r; i++)
        {
            string subi=s.substr(i);
            int t=match(sub, subi);
            if(res<t) res=t, pos=i+1, ts=subi;
            else if(res==t && (subi<ts || ts=="")) pos=i+1, ts=subi;
        }
        cout<<res<<" "<<pos<<endl;
    }
    return 0;
}