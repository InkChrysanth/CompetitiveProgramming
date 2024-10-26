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

struct Node{ int u, v, type; };
signed main()
{
	setIO();
	int T; cin>>T;
    while(T--)
    {
        int n; cin>>n;
        vector<Node> qry(n+1);
        vector<int> tmp;
        for(int i=1; i<=n; i++)
        {
            cin>>qry[i].u>>qry[i].v>>qry[i].type;
            tmp.eb(qry[i].u);
            tmp.eb(qry[i].v);
        }
        sort(all(tmp));
        tmp.erase(unique(all(tmp)), tmp.end());
        for(int i=1; i<=n; i++)
        {
            qry[i].u=lower_bound(all(tmp), qry[i].u)-tmp.begin();
            qry[i].v=lower_bound(all(tmp), qry[i].v)-tmp.begin();
        }
        sort(qry.begin()+1, qry.begin()+n+1, 
        [](const auto &x, const auto &y){ return x.type>y.type; });
        vector<int> p(tmp.size()+1);
        for(int i=1; i<=tmp.size(); i++) p[i]=i;
        function<int(int)> find=[&](int x)
        { return x==p[x] ? x : p[x]=find(p[x]); };
        for(int i=1; i<=n; i++)
        {
            int fu=find(qry[i].u);
            int fv=find(qry[i].v);
            // debug(fu), debug(fv);
            if(qry[i].type)
            {
                if(fu!=fv) p[fv]=fu;
            }
            else if(fu==fv)
            {
                cout<<"NO"<<endl;
                goto label;
            }
        }
        cout<<"YES"<<endl;
        label: ;
    }
	return 0;
}
