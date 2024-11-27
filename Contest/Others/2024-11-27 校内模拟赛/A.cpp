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

signed main()
{
    setIO();
    int n, k; cin>>n>>k;
    vector<int> a(n);
    unordered_map<int, vector<int>> p;
    for(int i=0; i<(int)a.size(); i++)
        cin>>a[i], p[a[i]].eb(i+1);
    sort(a.begin(), a.end());
    a.erase(unique(all(a)), a.end());
    unordered_map<int, bool> st;
    int nn=(int)a.size()-1;
    ll sum=0, lat=0;
    for(int i=nn; i>=0; i--)
    {
        if(a[i]+k*lat>=0)
        {
            st[a[i]]=true;
            sum+=1ll*(a[i]+k*lat)*(ll)p[a[i]].size();
        }
        lat+=(int)p[a[i]].size();
    }
    vector<int> ans;
    each(x, a) if(st[x])
        each(pos, p[x])
            ans.eb(pos);
    cout<<sum<<" "<<ans.size()<<endl;
    each(x, ans) cout<<x<<" ";
    return 0;
}
// implementation, greedy