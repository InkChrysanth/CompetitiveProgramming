//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

#define cmin(i,j) (i)=min((i),(j))
#define cmax(i,j) (i)=max((i),(j))
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define Fi(s) freopen(s,"r",stdin)
#define Fo(s) freopen(s,"w",stdout)
#define Fre(s) Fi(s".in"),Fo(s".ans")
#define all(x) x.begin(), x.end()
#define each(i,x) for(auto &i:(x))
#define fi first
#define se second
#define endl '\n'
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define eb emplace_back

using ll=long long;
using ld=long double;
using pii=pair<int, int>;
using pli=pair<ll, int>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin>>n>>m;
    vector<int> u(m+1), v(m+1), w(m+1);
    for(int i=1, a, b; i<=m; i++)
    {
        cin>>a>>b;
        char c;
        cin>>c;
        u[i]=a, v[i]=b;
        w[i]=(c=='(' ? -1 : 1);
    }
    auto check=[&]()
    {
        vector<int> dist(n+1, inf);
        for(int i=1; i<=n; i++) for(int k=1; k<=m; k++)
        {
            if(dist[v[k]]>dist[u[k]]+w[k])
            {
                dist[v[k]]=dist[u[k]]+w[k];
                if(i==n) return 1;
            }
        }
        return 0;
    };
    bool flag1=check();
    for(int i=1; i<=m; i++) w[i]=-w[i];
    bool flag2=check();
    cout<<((flag1==flag2) ? "Yes" : "No")<<endl;
	return 0;
}
