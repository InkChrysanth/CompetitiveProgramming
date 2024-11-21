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
        int n, k, q; cin>>n>>k>>q;
        vector<int> a(n+1), f(n+1);
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
            a[i]-=i;
        }
        multiset<int> S;
        map<int, int> cnt;
        for(int i=1; i<=n; i++)
        {
            int v=cnt[a[i]]++;
            auto ptr=S.find(v);
            if(ptr!=S.end()) S.erase(ptr);
            S.ins(v+1);
            if(i>=k)
            {
                f[i]=*S.rbegin();
                int w=cnt[a[i-k+1]]--;
                auto ptr=S.find(w);
                if(ptr!=S.end()) S.erase(ptr);
                S.ins(w-1);
            }
        }
        while(q--)
        {
            int l, r; cin>>l>>r;
            cout<<k-f[r]<<endl;
        }
    }
	return 0;
}
// data structures