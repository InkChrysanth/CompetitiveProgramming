#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10, M=2*N, S=1e6+10, INF=0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
int h[N], e[M], w[M], ne[M], idx;
bool st[N];
PII p[N], q[N];
int f[S], res=INF;
void add(int a, int b, int c)
{
    e[idx]=b, w[idx]=c, ne[idx]=h[a], h[a]=idx++;
}
int get_size(int u, int fa)
{
    if(st[u]) return 0;
    int res=1;
    for(int i=h[u]; ~i; i=ne[i])
    {
        int j=e[i];
        if(j==fa) continue;
        res+=get_size(j, u);
    }
    return res;
}
int get_wc(int u, int fa, int tot, int &wc)
{
    if(st[u]) return 0;
    int sum=1, ms=0;
    for(int i=h[u]; ~i; i=ne[i])
    {
        int j=e[i];
        if(j==fa) continue;
        int t=get_wc(j, u, tot, wc);
        ms=max(ms, t);
        sum+=t;
    }
    ms=max(ms, tot-sum);
    if(ms<=tot/2) wc=u;
    return sum;
}
void get_dist(int u, int fa, int dist, int cnt, int &qt)
{
    if(st[u] || dist>m) return;
    q[qt++]={dist, cnt};
    for(int i=h[u]; ~i; i=ne[i])
    {
        int j=e[i];
        if(j==fa) continue;
        get_dist(j, u, dist+w[i], cnt+1, qt);
    }
}
void calc(int u)
{
    if(st[u]) return;
    get_wc(u, -1, get_size(u, -1), u);
    st[u]=true;
    int pt=0;
    for(int i=h[u]; ~i; i=ne[i])
    {
        int j=e[i];
        int qt=0;
        get_dist(j, -1, w[i], 1, qt);
        for(int k=0; k<qt; k++)
        {
            auto &t=q[k];
            if(t.first==m) res=min(res, t.second);
            res=min(res, f[m-t.first]+t.second);
            p[pt++]=t;
        }
        for(int k=0; k<qt; k++)
        {
            auto &t=q[k];
            f[t.first]=min(f[t.first], t.second);
        }
    }
    for(int i=0; i<pt; i++)
        f[p[i].first]=INF;
    for(int i=h[u]; ~i; i=ne[i])
        calc(e[i]);
}
int main()
{
    cin>>n>>m;
    memset(h, -1, sizeof h);
    for(int i=0; i<n; i++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        add(a, b, c), add(b, a, c);
    }
    memset(f, 0x3f, sizeof f);
    calc(0);
    if(res!=INF) cout<<res<<endl;
    else puts("-1");
    return 0;
}