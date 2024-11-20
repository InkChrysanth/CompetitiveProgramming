//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

#define int long long
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


signed main()
{
    setIO();
	string s; cin>>s;
    int tar; cin>>tar;
    if(s==to_string(tar)) return cout<<0<<endl, 0;

    s="%"+s;
    int ans;
    function<void(int, int, int, int)> dfs=[&](int p, int sum, int q, int res)
    {
        if((double)clock()/CLOCKS_PER_SEC>=0.9)
        {
		    cout<<-1<<endl;
		    exit(0);
	    }
        // debug(p);
        if(sum>tar) return;
        if(p==s.size())
        {
            if(sum==tar)
            {
                cout<<ans<<endl;
                exit(0);
            }
            return;
        }
        if(q>0) dfs(p+1, sum+s[p]-'0', q-1, s[p]-'0');
        dfs(p+1, sum+res*10+s[p]-'0'-res, q, res*10+s[p]-'0');
    };
    for(ans=0; ans<(int)s.size(); ans++)
        dfs(1, 0, ans, 0);
    cout<<-1<<endl;
	return 0;
}
// dfs and similar