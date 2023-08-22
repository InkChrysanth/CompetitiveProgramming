#include <bits/stdc++.h>
using namespace std;
const int N=300010, M=N*2, DIFF=300010;

int n, m;
int h[N], e[M], ne[M], idx;
int fa[N][20], d[N], c1[M], c2[M];
int w[N], ans[N];
bool st[N];
queue<int> q;
vector<int> ap1[N], dap1[N], ap2[N], dap2[N];

void add(int a, int b)
{
    e[idx]=b, ne[idx]=h[a], h[a]=idx++;
}

void bfs()
{
    q.push(1); d[1]=1;
    while(!q.empty())
    {
        auto t=q.front();
        q.pop();
        for(int i=h[t]; ~i; i=ne[i])
        {
            int j=e[i];
            if(d[j]) continue;
            d[j]=d[t]+1;
            fa[j][0]=t;
            for(int k=1; k<=18; k++)
                fa[j][k]=fa[fa[j][k-1]][k-1];
            q.push(j);
        }
    }
}

int lca(int a, int b)
{
    if(d[a]<d[b]) swap(a, b);
    for(int k=18; k>=0; k--)
        if(d[fa[a][k]]>=d[b])
            a=fa[a][k];
    if(a==b) return a;
    for(int k=18; k>=0; k--)
    {
        if(fa[a][k]!=fa[b][k])
        {
            a=fa[a][k];
            b=fa[b][k];
        }
    }
    return fa[a][0];
}

void dfs(int u)
{
    st[u]=true;
    int cnt1=c1[w[u]+d[u]], cnt2=c2[w[u]-d[u]+DIFF];
    for(int i=0; i<ap1[u].size(); i++) c1[ap1[u][i]]++;
    for(int i=0; i<dap1[u].size(); i++) c1[dap1[u][i]]--;
    for(int i=0; i<ap2[u].size(); i++) c2[ap2[u][i]+DIFF]++;
    for(int i=0; i<dap2[u].size(); i++) c2[dap2[u][i]+DIFF]--;
    for(int i=h[u]; ~i; i=ne[i])
    {
        int j=e[i];
        if(st[j]) continue;
        dfs(j);
    }
    ans[u]=c1[w[u]+d[u]]-cnt1+c2[w[u]-d[u]+DIFF]-cnt2;
}

int main()
{
    memset(h, -1, sizeof h);
    cin.tie(0); cin>>n>>m;
    for(int i=1; i<=n-1; i++)
    {
        int a, b; cin>>a>>b;
        add(a, b), add(b, a);
    }
    bfs();
    for(int i=1; i<=n; i++)
        cin>>w[i];
    for(int i=1; i<=m; i++)
    {
        int s, t; cin>>s>>t;
        int res=lca(s, t);
        ap1[s].push_back(d[s]);
        dap1[fa[res][0]].push_back(d[s]);
        ap2[t].push_back(d[s]-2*d[res]);
        dap2[res].push_back(d[s]-2*d[res]);
    }
    dfs(1);
    for(int i=1; i<=n; i++)
        printf("%d ", ans[i]);
    return 0;
}
