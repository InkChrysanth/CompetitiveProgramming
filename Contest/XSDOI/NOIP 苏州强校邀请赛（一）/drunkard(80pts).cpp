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
	setIO("drunkard");
	int n, m; cin>>n>>m;
    set<pii> S;// dat: [q, p]
    int lst=-1, pos=inf, mx=inf;
    bool flag=false;// conflicting
    while(m--)
    {
        string opt; cin>>opt;
        if(flag) cout<<"bad"<<endl;
        else if(opt=="clue")
        {
            int p, q; cin>>p>>q;
            if(q-p+1<0){ flag=true; continue; }
            if(p>1) cmin(pos, q), cmin(mx, q-p+1);
            auto ptr=S.ins(mp(q, p)).fi;
            if(ptr!=S.begin() && next(ptr)!=S.end() && lst==(*next(ptr)).fi)
                lst=-1;
            if(ptr!=S.begin())
            {
                pii pre=*prev(ptr);
                if(abs(pre.se-p)>abs(pre.fi-q)){ flag=true; continue; }
                if((pre.fi+pre.se)%2!=(p+q)%2) cmax(lst, q);
            }
            if(next(ptr)!=S.end())
            {
                pii nxt=*next(ptr);
                if(abs(nxt.se-p)>abs(nxt.fi-q)){ flag=true; continue; }
                if((nxt.fi+nxt.se)%2!=(p+q)%2) cmax(lst, nxt.fi);
            }
            if(lst>pos){ flag=true; continue; }
        }
        else if(opt=="min")
        {
            int res;
            if(lst==-1)
            {
                if(S.empty()) res=0;
                else res=((*S.begin()).fi+(*S.begin()).se+1)%2;
            }
            else
            {
                auto ptr=S.lower_bound(mp(lst, 0));
                pii pre=*prev(ptr);
                res=pre.fi+1;
            }
            cout<<res<<endl;
        }
        else
        {
            if(mx==inf) cout<<"inf"<<endl;
            else cout<<mx<<endl;
        }
    }
	return 0;
}
// implementation