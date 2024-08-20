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
constexpr int N=25;

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    int T;
    cin>>T;
    for(int n; T>=1; T--)
    {
        vector<int> lm(N, 0), a(N, 0);
        for(int i=0; i<24; i++) cin>>lm[i];
        cin>>n;
        for(int i=1, x; i<=n; i++)
        {
            cin>>x;
            a[x]++;
        }
        auto check=[&](int mid)
        {
            vector<vector<pii>> adj(N, vector<pii>());
            vector<bool> ins(N, false);
            vector<int> cnt(N, 0), dist(N, -inf);
            
            adj[24].eb(mp(0, 0));
            adj[23].eb(mp(24, -mid)), adj[24].eb(mp(23, mid));
            for(int i=1; i<=23; i++) adj[i-1].eb(mp(i, 0));
            adj[0].eb(mp(24, -a[0]));
            for(int i=1; i<=23; i++) adj[i].eb(mp(i-1, -a[i]));
            adj[24].eb(mp(7, lm[7]));
            for(int i=0; i<=6; i++) adj[i+16].eb(mp(i, lm[i]-mid));
            for(int i=8; i<=23; i++) adj[i-8].eb(mp(i, lm[i]));

            queue<int> q;
            q.push(24); dist[24]=0; ins[24]=true;
            while(q.size())
            {
                int u=q.front(); q.pop();
                ins[u]=false;
                each(t, adj[u])
                {
                    int v=t.fi, w=t.se;
                    if(dist[v]<dist[u]+w)
                    {
                        dist[v]=dist[u]+w;
                        cnt[v]=cnt[u]+1;
                        if(cnt[v]>=25) return false;
                        if(!ins[v]) q.push(v), ins[v]=true;
                    }
                }
            }
            return true;
        };
        int l=0, r=n, ans=r;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(check(mid)) r=mid-1, ans=mid;
            else l=mid+1;
        }
        // debug(ans);
        cout<<(ans==r ? "No Solution" : to_string(ans))<<endl;
    }
	return 0;
}
