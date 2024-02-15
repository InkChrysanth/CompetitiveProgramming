#include <bits/stdc++.h>
using namespace std;
const int C=110, N=1010, M=20010;
struct Node
{
    int d, u, c;// d 到这个点所花费的油钱 u 编号 c 剩多少油
    bool operator <(const Node &T)const
    {
        return d>T.d;
    }
};
int n, m;
int h[N], e[M], ne[M], w[M], idx;
int dist[N][C], price[N];
bool st[N][C];
void add(int a, int b, int c)
{
    e[idx]=b, w[idx]=c, ne[idx]=h[a], h[a]=idx++;
}
int dijkstra(int c, int start, int end)
{
    priority_queue<Node> heap;
    memset(st, false, sizeof st);
    memset(dist, 0x3f, sizeof dist);
    dist[start][0]=0;
    heap.push({0, start, 0});
    while(heap.size())
    {
        auto t=heap.top(); heap.pop();
        if(t.u==end) return t.d;
        if(st[t.u][t.c]) continue;
        st[t.u][t.c]=true;
        if(t.c<c)
        {
            if(dist[t.u][t.c+1]>t.d+price[t.u])
            {
                dist[t.u][t.c+1]=t.d+price[t.u];
                heap.push({dist[t.u][t.c+1], t.u, t.c+1});
            }
        }
        for(int i=h[t.u]; ~i; i=ne[i])
        {
            int j=e[i];
            if(t.c<w[i]) continue;
            if(dist[j][t.c-w[i]]>t.d)
            {
                dist[j][t.c-w[i]]=t.d;
                heap.push({t.d, j, t.c-w[i]});
            }
        }
    }
    return -1;
}
int main()
{
    memset(h, -1, sizeof h);
    cin>>n>>m;
    for(int i=0; i<n; i++)
        cin>>price[i];
    for(int i=0; i<m; i++)
    {
        int a, b, c; cin>>a>>b>>c;
        add(a, b, c), add(b, a, c);
    }
    int T; cin>>T;
    while(T--)
    {
        int c, s, e; cin>>c>>s>>e;
        int res=dijkstra(c, s, e);
        if(res!=-1) cout<<res<<endl;
        else puts("impossible");
    }
    return 0;
}