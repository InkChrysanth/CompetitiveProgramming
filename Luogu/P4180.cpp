#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=200010, M=600010, INF=0x3f3f3f3f;
int n, m;
struct Edge
{
    int a, b, w;
    bool used;
    bool operator <(const Edge &T)const
    {
        return w<T.w;
    }
}edge[M];
int p[M];
int h[N], e[M], ne[M], w[M], idx;
int depth[N], d1[M][30], d2[M][30], fa[N][30];

void add(int a, int b, int c)
{
    e[idx]=b, w[idx]=c, ne[idx]=h[a], h[a]=idx++;
}
int find(int x)
{
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
int kruskal()
{
    for(int i=1; i<=n; i++)
        p[i]=i;
    sort(edge, edge+m);
    int res=0;
    for(int i=0; i<m; i++)
    {
        int a=find(edge[i].a), b=find(edge[i].b), w=edge[i].w;
        if(a!=b)
        {
            p[a]=b;
            res+=w;
            edge[i].used=true;
        }
    }
    return res;
}

void build()
{
    memset(h, -1, sizeof h);
    for(int i=0; i<m; i++)
        if(edge[i].used)
        {
            int a=edge[i].a, b=edge[i].b, w=edge[i].w;
            add(a, b, w), add(b, a, w);
        }
}
void bfs()
{
    queue<int> q; q.push(1);
    memset(depth, 0x3f, sizeof depth);
    depth[0]=0, depth[1]=1;
    while(q.size())
    {
        auto t=q.front(); q.pop();
        for(int i=h[t]; ~i; i=ne[i])
        {
            int j=e[i];
            if(depth[j]>depth[t]+1)
            {
                depth[j]=depth[t]+1;
                q.push(j);
                fa[j][0]=t;
                d1[j][0]=w[i], d2[j][0]=-INF;
                for(int k=1; k<=18; k++)
                {
                    int anc=fa[j][k-1];
                    fa[j][k]=fa[anc][k-1];
                    int distance[4]={d1[j][k-1], d2[j][k-1], d1[anc][k-1], d2[anc][k-1]};
                    d1[j][k]=d2[j][k]=-INF;
                    for(int u=0; u<4; u++)
                    {
                        int d=distance[u];
                        if(d>d1[j][k]) d2[j][k]=d1[j][k], d1[j][k]=d;
                        else if(d!=d1[j][k] && d>d2[j][k]) d2[j][k]=d;
                    }
                }
            }
        }
    }
}
int lca(int a, int b, int w)
{
    if(depth[a]<depth[b]) swap(a, b);
    int distance[1000];
    int cnt=0;
    for(int k=18; k>=0; k--)
    {
        if(depth[fa[a][k]]>=depth[b])
        {
            distance[cnt++]=d1[a][k];
            distance[cnt++]=d2[a][k];
            a=fa[a][k];
        }
    }
    if(a!=b)
    {
        for(int k=18; k>=0; k--)
            if(fa[a][k]!=fa[b][k])
            {
                distance[cnt++]=d1[a][k];
                distance[cnt++]=d2[a][k];
                distance[cnt++]=d1[b][k];
                distance[cnt++]=d2[b][k];
                a=fa[a][k], b=fa[b][k];
            }
        distance[cnt++]=d1[a][0];
        distance[cnt++]=d1[b][0];
    }
    int dist1=-INF, dist2=-INF;
    for(int i=0; i<cnt; i++)
    {
        if(distance[i]>dist1) dist2=dist1, dist1=distance[i];
        else if(distance[i]!=dist1 && distance[i]>dist2) dist2=distance[i];
    }
    if(w>dist1) return w-dist1;
    else if(w>dist2) return w-dist2;
    else return INF;
}
signed main()
{
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        edge[i]={a, b, c};
    }
    int sum=kruskal();
    build();
    bfs();
    int res=1e18;
    for(int i=0; i<m; i++)
        if(!edge[i].used)
        {
            int a=edge[i].a, b=edge[i].b, w=edge[i].w;
            res=min(res, sum+lca(a, b, w));
        }
    cout<<res<<endl;
    return 0;
}