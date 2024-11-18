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
    int n, m; cin>>n>>m;
    vector<pii> a(n), v(m);
    each(x, a) cin>>x.fi>>x.se;
    each(x, v) cin>>x.fi>>x.se;
    sort(all(a));
    sort(all(v));
    pq<int> heap;
    ll sum=0; int ptr=0;
    for(int i=0; i<n; i++)
    {
        while(ptr<m && a[i].fi>=v[ptr].fi) heap.push(v[ptr].se), ptr++;
        if(heap.empty() || a[i].fi-a[i].se>=heap.top())
            sum+=a[i].se;
        else
        {
            sum+=a[i].fi-heap.top();
            heap.pop();
            heap.push(a[i].fi-a[i].se);
        }
    }
    cout<<sum<<endl;
	return 0;
}
// greedy