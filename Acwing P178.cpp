#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

const int N=1010, M=200010;

typedef pair<int, int> PII;
typedef pair<int, pair<int, int>> PIII;

int n, m;
int S, T, K;
int h[N], rh[N], w[M], e[M], ne[M], cnt[N], idx;
int dist[N];
bool st[N];

void add(int h[], int a, int b, int c)
{
    e[idx]=b, w[idx]=c, ne[idx]=h[a], h[a]=idx++;
}

void dijkstra()
{
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, T});
    memset(dist, 0x3f, sizeof dist);
    dist[T]=0;
    while(heap.size())
    {
        auto t=heap.top();
        heap.pop();
        int u=t.y;
        if(st[u]) continue;
        st[u]=true;
        for(int i=rh[u]; ~i; i=ne[i])
        {
            int j=e[i];
            if(dist[j]>dist[u]+w[i])
            {
                dist[j]=dist[u]+w[i];
                heap.push({dist[j], j});
            }
        }
    }
}

int Astar()
{
    priority_queue<PIII, vector<PIII>, greater<PIII>> heap;
    heap.push({dist[S], {0, S}});
    while(heap.size())
    {
        auto t=heap.top();
        heap.pop();
        int u=t.y.y, u_dist=t.y.x;
        cnt[u]++;
        if(cnt[T]==K) return u_dist;
        for(int i=h[u]; ~i; i=ne[i])
        {
            int j=e[i];
            if(K>cnt[j])
                heap.push({u_dist+dist[j]+w[i], {u_dist+w[i], j}});
        }
    }
    return -1;
}

int main()
{
    memset(h, -1, sizeof h);
    memset(rh, -1, sizeof rh);
    cin.tie(0); cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        add(h, a, b, c);
        add(rh, b, a, c);
    }
    cin>>S>>T>>K;
    if(S==T) K++;
    dijkstra();
    cout<<Astar()<<endl;
    return 0;
}
