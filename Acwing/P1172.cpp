// Problem: 祖孙询问
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1174/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
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

const int N=50010, K=21;

int n, m, root;
vector<int> g[N];
int dep[N];
int fa[N][K];

void dfs(int u, int pre)
{
    fa[u][0]=pre;
    dep[u]=dep[pre]+1;
    for(int k=1; k<=20; k++)
        fa[u][k]=fa[fa[u][k-1]][k-1];
    for(auto v: g[u])
    {
        if(v==pre) continue;
        dfs(v, u);
    }
}

int lca(int a, int b)
{
    if(dep[a]<dep[b]) swap(a, b);
    for(int k=20; k>=0; k--)
        if(dep[fa[a][k]]>=dep[b])
            a=fa[a][k];
    if(a==b) return b;
    for(int k=20; k>=0; k--)
    {
        if(fa[a][k]!=fa[b][k])
        {
            a=fa[a][k];
            b=fa[b][k];
        }
    }
    return fa[a][0];
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	for(int i=1, a, b; i<=n; i++)
	{
		cin>>a>>b;
		if(b==-1) root=a;
		else
		{
			g[a].eb(b);
			g[b].eb(a);	
		}
	}
	dfs(root, 0);
	cin>>m;
	for(int i=1, a, b; i<=m; i++)
	{
		cin>>a>>b;
		int res=lca(a, b);
		// debug(res);
		cout<<((res==a)?1:((res==b)?2:0))<<endl;
	}
	return 0;
}
