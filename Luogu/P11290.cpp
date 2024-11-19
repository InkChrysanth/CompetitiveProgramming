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
    cout<<setprecision(20);
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
	int n, q; cin>>n>>q;
    vector<ll> p(n+1);
    vector<ll> cand;
    map<ll, int> id;
    for(ll i=1; i<=1e9; i*=2)
        for(ll j=i; j<=1e9; j*=3)
        {
            cand.eb(j);
            id[j]=cand.size()-1;// use 0-indexed
        }
    vector<vector<ld>> f(n+1, vector<ld>(cand.size(), 1e20));
    f[0][id[1]]=0;
    for(int i=1; i<=n; i++)
    {
        ll t, x; cin>>p[i]>>t>>x;
        f[i][id[1]]=p[i];
        for(int j=0; j<cand.size(); j++)
        {
            ld w=1.0*(p[i]-p[i-1])/cand[j];
            cmin(f[i][j], f[i-1][j]+w);
            if(x>1 && f[i-1][j]!=inf && cand[j]*t<=1e9)
            {
                int k=id[cand[j]*x];
                cmin(f[i][k], f[i-1][j]+t+w);
            }
        }
    }
    while(q--)
    {
        int y; cin>>y;
        int k=prev(upper_bound(p.begin()+1, p.begin()+n+1, y))-p.begin();
        if(k==0)
        {
            cout<<y<<endl;
            continue;
        }
        ld ans=1e20;
        for(int i=0; i<cand.size(); i++)
            cmin(ans, f[k][i]+1.0*(y-p[k])/cand[i]);
        cout<<ans<<endl;
    }
	return 0;
}
// dp, binary search