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
        int n, m, L, V; cin>>n>>m>>L>>V;
        vector<pii> segs;
        for(int i=0; i<n; i++)
        {
            int d, v, a; cin>>d>>v>>a;
            if(a==0)
            {
                if(v<=V) continue;
                segs.eb(d, L);
            }
            else if(a>0)
            {
                if(v>V) segs.eb(d, L);
                else if(v==V) segs.eb(d+1, L);
                else
                {
                    if(v*v+2*a*(L-d)<=V*V) continue;
                    int l=d, r=L, res=r;
                    while(l<=r)
                    {
                        int mid=(l+r)>>1;
                        if(v*v+2*a*(mid-d)>V*V) res=mid, r=mid-1;
                        else l=mid+1;
                    }
                    segs.eb(res, L);
                }
            }
            else
            {
                if(v<=V) continue;
                int l=d, r=L, res=l;
                while(l<=r)
                {
                    int mid=(l+r)>>1;
                    if(v*v+2*a*(mid-d)>V*V) res=mid, l=mid+1;
                    else r=mid-1;
                }
                segs.eb(d, res);
            }
        }
        // each(seg, segs) cerr<<seg.fi<<" "<<seg.se<<endl;
        vector<int> mo(m);
        for(int i=0; i<m; i++) cin>>mo[i];
        int cnt=0;
        vector<pii> cand;
        each(seg, segs)
        {
            int l=seg.fi, r=seg.se;
            auto ptr=lower_bound(all(mo), l);
            if(ptr!=mo.end() && *ptr<=r) cnt++, cand.eb(seg);
        }
        sort(all(cand), [](pii x, pii y){ return x.se<y.se; });
        // cerr<<cand.size()<<endl;
        // each(seg, cand) cerr<<seg.fi<<" "<<seg.se<<endl;
        vector<int> ch;
        each(seg, cand)
        {
            int l=seg.fi, r=seg.se;
            auto ptr=lower_bound(all(ch), l);
            if(ptr!=ch.end() && *ptr<=r) continue;
            ch.eb(*prev(upper_bound(all(mo), r)));
        }
        // each(p, ch) cerr<<p<<" ";
        cout<<cnt<<" "<<m-ch.size()<<endl;
    }
	return 0;
}
// binary search, implementation, greedy