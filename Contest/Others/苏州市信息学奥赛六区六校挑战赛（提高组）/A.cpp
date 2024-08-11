//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
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
struct Edge{ int u, v, w; };
struct Node{ int v, k, id; };

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin>>n>>m;
    vector<Edge> E(n+1);
    for(int i=1; i<=n-1; i++)
        cin>>E[i].u>>E[i].v>>E[i].w;
	vector<Node> Q(m+1);
    for(int i=1; i<=m; i++)
    {
        cin>>Q[i].k>>Q[i].v;
        Q[i].id=i;
    }
    sort(Q.begin()+1, Q.begin()+m+1, [](Node x, Node y){ return x.k>y.k; });
    sort(E.begin()+1, E.begin()+n+1, [](Edge x, Edge y){ return x.w>y.w; });
    vector<int> ans(m+1), p(n+1), sz(n+1, 1);
    for(int i=1; i<=n; i++) p[i]=i;
    function<int(int)> find=[&](int x){ return x==p[x] ? x : p[x]=find(p[x]); };
    int cur=1;
    for(int i=1; i<=m; i++)
    {
        int &v=Q[i].v, &k=Q[i].k, &id=Q[i].id;
        while(cur<=n && k<=E[cur].w)
        {
            int fu=find(E[cur].u), fv=find(E[cur].v);
            if(fu!=fv)
            {
                p[fu]=fv;
                sz[fv]+=sz[fu];
            }
            cur++;
        }
        ans[Q[i].id]=sz[find(Q[i].v)]-1;
    }
    for(int i=1; i<=m; i++)
        cout<<ans[i]<<endl;
    return 0;
}
