#include <bits/stdc++.h>
#define int_rd (int)read()
#define endl '\n'
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

inline ll read()
{
	ll a=0; int f=0; char p=getchar();
	while(!isdigit(p)){f|=p=='-'; p=getchar();}
	while(isdigit(p)){a=(a<<3)+(a<<1)+(p^48); p=getchar();}
	return f?-a:a;
}

const int N=500010, K=31;

int n, m, root;
vector<int> g[N];
int depth[N];
int fa[N][K];

void bfs(int root)
{
   queue<int> q;
   q.push(root); depth[root]=1;
   while(q.size())
   {
       auto t=q.front(); q.pop();
       for(auto j: g[t])
       {
           if(depth[j]) continue;
           depth[j]=depth[t]+1;
           fa[j][0]=t;
           q.push(j);
           for(int k=1; k<=30; k++)
               fa[j][k]=fa[fa[j][k-1]][k-1];
       }
   }
}

void dfs(int u, int pre)
{
	fa[u][0]=pre;
	depth[u]=depth[pre]+1;
	for(int k=1; k<=30; k++)
		fa[u][k]=fa[fa[u][k-1]][k-1];
	for(auto v: g[u])
	{
		if(v==pre) continue;
		dfs(v, u);
	}
}

int lca(int a, int b)
{
    if(depth[a]<depth[b]) swap(a, b);
    for(int k=30; k>=0; k--)
        if(depth[fa[a][k]]>=depth[b])
            a=fa[a][k];
    if(a==b) return a;
    for(int k=30; k>=0; k--)
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
    n=int_rd, m=int_rd, root=int_rd;
    for(int i=1; i<=n-1; i++)
    {
        int u=int_rd, v=int_rd;
        g[u].emplace_back(v); g[v].emplace_back(u);
    }
//    bfs(root);
    dfs(root, 0);
    while(m--)
    {
        int a=int_rd, b=int_rd;
        cout<<lca(a, b)<<endl;
    }
    return 0;
}
