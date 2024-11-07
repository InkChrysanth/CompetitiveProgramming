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
	int n; cin>>n;
	vector<int> a(n+1), b(n+1), c(n+1);
	pq<pii> ha, hb, hc;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i]>>b[i]>>c[i];
		ha.push(mp(a[i], i));
		hb.push(mp(b[i], i));
		hc.push(mp(c[i], i));
	}
    vector<bool> vis(n+1);
	while(ha.size() && hb.size() && hc.size())
    {
        auto ta=ha.top(), tb=hb.top(), tc=hc.top();
        if(vis[ta.se])
        {
            ha.pop();
            continue;
        }
        if(vis[tb.se])
        {
            hb.pop();
            continue;
        }
        if(vis[tc.se])
        {
            hc.pop();
            continue;
        }
        if(a[tb.se]==ta.fi)
        {
            vis[tb.se]=true;
            hb.pop();
            continue;
        }
        if(a[tc.se]==ta.fi)
        {
            vis[tc.se]=true;
            hc.pop();
            continue;
        }
        if(b[ta.se]==tb.fi)
        {
            vis[ta.se]=true;
            ha.pop();
            continue;
        }
        if(b[tc.se]==tb.fi)
        {
            vis[tc.se]=true;
            hc.pop();
            continue;
        }
        if(c[ta.se]==tc.fi)
        {
            vis[ta.se]=true;
            ha.pop();
            continue;
        }
        if(c[tb.se]==tc.fi)
        {
            vis[tb.se]=true;
            hb.pop();
            continue;
        }
        cout<<ta.fi+tb.fi+tc.fi<<endl;
        return 0;
    }
	cout<<-1<<endl;	
	return 0;
}
// greedy