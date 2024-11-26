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

signed main()
{
	setIO();
	int T; cin>>T;
    while(T--)
    {
        int n, w; cin>>n>>w;
        bool flag=false;
        vector<pii> segs(n+1);
        for(int i=1; i<=n; i++)
        {
            cin>>segs[i].fi>>segs[i].se;
            if(segs[i].se-segs[i].fi+1<w) flag=true;
        }
        if(!w){ cout<<1<<endl; continue; }
        if(flag){ cout<<"No"<<endl; continue; }
        sort(segs.begin()+1, segs.end(), [](pii x, pii y){ return x.se<y.se; });
        int ans=1, lst=segs[1].se;
        for(int i=2; i<=n; i++) if(lst-segs[i].fi+1<w)
            ans++, lst=segs[i].se;
        cout<<ans<<endl;
    }
	return 0;
}
// greedy