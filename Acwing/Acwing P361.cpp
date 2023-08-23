#include <bits/stdc++.h>
using namespace std;
const int N=1010, M=5010;
int n, m;
int wf[N];
int h[N], e[M], ne[M], wt[M], idx;
int cnt[N], q[N];
double dist[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx]=b, wt[idx]=c, ne[idx]=h[a], h[a]=idx++;
}

bool check(double mid)
{
    memset(dist, 0, sizeof dist);
    memset(st, false, sizeof st);
    memset(cnt, 0, sizeof cnt);
    int hh=0, tt=0;
    for(int i=1; i<=n; i++)
    {
        q[tt++]=i;
        st[i]=true;
    }
    while(hh!=tt)
    {
        int t=q[hh++];
        if(hh==N) hh=0;
        st[t]=false;
        for(int i=h[t]; ~i; i=ne[i])
        {
            int j=e[i];
            if(dist[j]<dist[t]+wf[t]-mid*wt[i])
            {
                dist[j]=dist[t]+wf[t]-mid*wt[i];
                cnt[j]=cnt[t]+1;
                if(cnt[j]>=n) return true;
                if(!st[j])
                {
                    st[j]=true;
                    q[tt++]=j;
                    if(tt==N) tt=0;
                }
            }
        }
    }
    return false;
}

int main()
{
    memset(h, -1, sizeof h);
    cin.tie(0); cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>wf[i];
    for(int i=1; i<=m; i++)
    {
        int a, b, c; cin>>a>>b>>c;
        add(a, b, c);
    }
    double l=0, r=100010, mid;
    while(r-l>1e-4)
    {
        mid=(l+r)/2;
        if(check(mid)) l=mid;
        else r=mid;
    }
    printf("%.2lf", mid);
    return 0;
}
