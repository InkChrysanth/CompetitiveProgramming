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
constexpr ld eps=1e-8;

signed main()
{
	setIO();
	int T; cin>>T;
    // vector<int> p2(20); p2[0]=1;
    // for(int i=1; i<20; i++) p2[i]=p2[i-1]*2;
    while(T--)
    {
        ll a, b, c; cin>>a>>b>>c;
        if(a+1!=c){ cout<<-1<<endl; continue; }
        if(a==0){ cout<<b<<endl; continue; }
        // int h=upper_bound(all(p2), a)-p2.begin();
        ll h=ceil(log2(a)+eps);
        ll num=(1ll<<h)-((1ll<<h)-1-a);
        b-=((1ll<<h)-1-a);
        cout<<h+((b+num-1)/num)<<endl;
    }
	return 0;
}
// math