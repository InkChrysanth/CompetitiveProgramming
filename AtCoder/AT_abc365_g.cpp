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
constexpr int N=200010, M=450;

int n, m, q;
int t[N], p[N], sum[N];
int id[N], tot=0;
vector<int> v[N];
int ans[M][N];

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        cin>>t[i]>>p[i];
        v[p[i]].eb(i);
    }
    for(int i=1; i<=n; i++)
    {
        if(v[i].size()>=M)
        {
            int u=0;
            id[i]=++tot;
            for(int j=1; j<=m; j++)
            {
                sum[j]=sum[j-1];
                if(u) sum[j]+=t[j]-t[j-1];
                if(p[j]==i) u^=1;
            }
            for(int j=1; j<=n; j++)
            {
                for(int k=1; k<v[j].size(); k+=2)
                {
                    ans[tot][j]+=sum[v[j][k]]-sum[v[j][k-1]];
                }
            }
        }
    }
    cin>>q;
    for(int x, y; q>0; q--)
    {
        cin>>x>>y;
        if(!id[x]) swap(x, y);
        if(id[x]){ cout<<ans[id[x]][y]<<endl; continue;}
        int res=0;
        for(int i=1, j=1; i<v[x].size(); i+=2)
        {
            while(j<v[y].size() && t[v[y][j]]<t[v[x][i]])
            {
                res+=max(0, t[v[y][j]]-max(t[v[y][j-1]], t[v[x][i-1]]));
                j+=2;
            }
            if(j<v[y].size()) res+=max(0, t[v[x][i]]-max(t[v[y][j-1]], t[v[x][i-1]]));
        }
        cout<<res<<endl;
    }
	return 0;
}
