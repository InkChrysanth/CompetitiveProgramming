#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=200010, M=2*N;
int n;
LL dist[N];
int h[N], e[M], ne[M], w[M], idx;
int pre[N];
vector<int> path;
bool st[N];

void add(int a, int b, int c)
{
	e[idx]=b, w[idx]=c, ne[idx]=h[a], h[a]=idx++;
}

int bfs(int u)
{
    queue<int> q;
    q.push(u);
    memset(dist, -1, sizeof dist);
    memset(pre, -1, sizeof pre);
    dist[u]=0;
    while(!q.empty())
    {
        auto t=q.front();
        q.pop();
        for(int i=h[t]; ~i; i=ne[i])
        {
            int j=e[i];
            if(dist[j]!=-1) continue;
            dist[j]=dist[t]+w[i];
            pre[j]=i;
            q.push(j);
        }
    }
    int res=0;
    for(int i=1; i<=n; i++)
        if(dist[i]>dist[res])
            res=i;
    return res;
}
void dfs(int u)
{
    st[u]=true;
    for(int i=h[u]; ~i; i=ne[i])
    {
        int j=e[i];
        if(st[j]) continue;
        dfs(j);
        dist[u]=max(dist[u], dist[j]+w[i]);
    }
}
int main()
{
    cin.tie(0); cin>>n;
    memset(h, -1, sizeof h);
    for(int i=1; i<=n-1; i++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        add(a, b, c), add(b, a, c);
    }
    int p=bfs(1);
    int q=bfs(p);
    cout<<dist[q]<<endl;
    path.push_back(q);
    while(p!=q)
    {
        q=e[pre[q]^1];
        path.push_back(q);
    }
    reverse(path.begin(), path.end());
    memset(dist, 0, sizeof dist);
    for(auto pth: path) st[pth]=true;
    for(auto pth: path) dfs(pth);
    int l=0, r=path.size()-1;
    LL cur=0;
    for(int i=0; i<path.size(); i++)
    {
        if(cur==dist[path[i]]) l=i;
        if(i<path.size()-1) cur+=w[pre[path[i+1]]];
    }
    cur=0;
    for(int i=path.size()-1; i>=0; i--)
    {
        if(cur==dist[path[i]]) r=i;
        if(i>0) cur+=w[pre[path[i]]];
    }
    cout<<max(0, r-l)<<endl;
    return 0;
}