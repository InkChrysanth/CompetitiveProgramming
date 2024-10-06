#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

#define cmin(i,j) (i)=min((i),(j))
#define cmax(i,j) (i)=max((i),(j))
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define Fi(s) freopen(s,"r",stdin)
#define Fo(s) freopen(s,"w",stdout)
#define Fre(s) Fi(s".in"),Fo(s".out")
#define all(x) x.begin(), x.end()
#define each(i,x) for(auto &i:(x))
#define fi first
#define se second
#define endl "\n"
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define em emplace

using ll=long long;
using ull=unsigned long long;
using ld=long double;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;

signed main()
{
    Fre("tree");
	cin.tie(0)->sync_with_stdio(0);
    int n, q; cin>>n>>q;
    vector<vector<int>> ch(n+1);
    vector<int> val(n+1);
    for(int i=1; i<=n; i++)
    {
        int fa; cin>>fa>>val[i];
        if(fa) ch[fa].eb(i);
    }
    function<int(int)> query=[&](int u)
    {
        int res=val[u];
        each(v, ch[u]) cmin(res, query(v));
        return res;
    };
    while(q--)
    {
        char opt; cin>>opt;
        if(opt=='V')
        {
            int x, y;
            cin>>x>>y;
            val[x]=y;
        }
        else if(opt=='E')
        {
            int x;
            cin>>x;
        }
        else if(opt=='Q')
        {
            int x;
            cin>>x;
            cout<<query(x)<<endl;
        }
    }
    return 0;
}