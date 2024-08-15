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
constexpr int N=65;

int n, m;
int a[N][N];
int ans[N];

bool gauss()
{
    for(int i=1; i<=n; i++)
    {
        int r=i;
        for(int j=i+1; j<=n; j++)
            if(abs(a[r][i])<abs(a[j][i])) r=j;
        swap(a[r], a[i]);
        for(int j=i+1; j<=n; j++)
            if(a[j][i])
                for(int k=i; k<=n+1; k++) a[j][k]^=a[i][k];
    }
    int tot=0;
    for(int i=n; i>=1; i--)
    {
        ans[i]=a[i][n+1];
        for(int j=i+1; j<=n; j++) ans[i]^=(a[i][j]*ans[j]);
        if((ans[i] && !a[i][i]) || (!ans[i] && a[i][i])) return false;
        if(!ans[i]) ans[i]=1<<(tot++); 
    }
    return true;
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1, u, v; i<=m; i++)
    {
        cin>>u>>v;
        a[u][v]=a[v][u]=1;
    }
    if(!gauss()) return cout<<"No"<<endl, 0;
    cout<<"Yes"<<endl;
    for(int i=1; i<=n; i++)
        cout<<ans[i]<<" ";
	return 0;
}
