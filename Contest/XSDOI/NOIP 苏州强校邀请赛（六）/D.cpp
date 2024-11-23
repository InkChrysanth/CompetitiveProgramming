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
constexpr int mod=1e9+7;

signed main()
{
	setIO("experiment");
    int T; cin>>T;
    while(T--)
    {
        int n; cin>>n;
        string s; cin>>s; s="%"+s;
        vector<int> b(n+1);
        vector<int> st(n+1);
        for(int i=1; i<=n; i++) cin>>b[i];
        int ans=0;
        function<void(int)> dfs=[&](int p)
        {
            if(p==n+1)
            {
                vector<int> t=st;
                // each(x, t) cerr<<x;
                // cerr<<endl;
                for(int i=1; i<=n; i++) if(t[i] && !t[b[i]])
                    t[i]=0, t[b[i]]=1;
                // each(x, t) cerr<<x;
                // cerr<<endl;
                (ans+=t[n])%=mod;
                return;
            }
            if(s[p]=='C')
            {
                st[p]=1;
                dfs(p+1);
            }
            if(s[p]=='.')
            {
                st[p]=0;
                dfs(p+1);
            }
            if(s[p]=='?')
            {
                st[p]=1;
                dfs(p+1);
                st[p]=0;
                dfs(p+1);
            }
        };
        dfs(1);
        cout<<ans<<endl;
    }
	return 0;
}