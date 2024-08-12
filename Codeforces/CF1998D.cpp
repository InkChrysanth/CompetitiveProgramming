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

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--)
    {
        int n, m;
        cin>>n>>m;
        vector<vector<int>> adj(n+1);
        for(int i=1; i<n; i++)
            adj[i].eb(i+1);
        for(int i=1, u, v; i<=m; i++)
        {
            cin>>u>>v;
            adj[u].eb(v);
        }
        vector<int> dist(n+1, inf);
        queue<int> q;
        q.push(1); dist[1]=1;
        while(q.size())
        {
            int u=q.front();
            q.pop();
            each(v, adj[u])
            {
                if(dist[v]>dist[u]+1)
                    dist[v]=dist[u]+1, q.push(v);
            }
        }
        // for(int i=1; i<=n; i++) cerr<<dist[i]<<" \n"[i==n];
        vector<int> s(n+1, 0);
        for(int i=1; i<n; i++)
        {
            each(j, adj[i])
            {
                if(i+1>j-dist[i]) continue;
                s[i+1]++; s[j-dist[i]]--;
            }
        }
        for(int i=1; i<n; i++)
        {
            s[i]+=s[i-1];
            cout<<(s[i]==0);
        }
        cout<<endl;
    }
	return 0;
}
