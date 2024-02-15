#include <bits/stdc++.h>
using namespace std;
const int N=1000010, INF=0x3f3f3f3f;
int n, m;
int tr[N], maxy;
int res[N];
struct Node
{
    int x, y, z;
    bool operator<(const Node &T)const
    {
        return x<T.x;
    }
}a[N], b[N];
int lowbit(int x)
{
    return x&-x;
}
void insert(int x, int w)
{
    for(int i=x; i<=maxy; i+=lowbit(i))
        tr[i]=max(tr[i], w);
}
int query(int x)
{
    int res=-INF;
    for(int i=x; i; i-=lowbit(i))
        res=max(res, tr[i]);
    return res;
}
void work(int st, int ed, int t, int dx, int dy)
{
    for(int i=st; i!=ed; i+=t)
    {
        int y;
        if(dy==1) y=b[i].y;
        else y=maxy-b[i].y+1;
        int dist=dx*b[i].x+dy*b[i].y;
        if(a[b[i].z].z==1) insert(y, dist);
        else res[b[i].z]=min(res[b[i].z], abs(dist-query(y)));
    }
    for(int i=st; i!=ed; i+=t)
    {
        int y;
        if(dy==1) y=b[i].y;
        else y=maxy-b[i].y+1;
        if(a[b[i].z].z==1)
            for(int j=y; j<=maxy; j+=lowbit(j))
            {
                if(tr[j]==-INF) break;
                tr[j]=-INF;
            }
    }
}
void cdq(int l, int r)
{
    if(l==r) return;
    int mid=l+r>>1;
    if(l<=mid) cdq(l, mid);
    if(r>mid) cdq(mid+1, r);
    if(r>n)
    {
        int cnt=0;
        for(int i=l; i<=r; i++)
            if((i<=mid && a[i].z==1) || (i>mid && a[i].z==2))
                b[++cnt]=a[i], b[cnt].z=i;
        sort(b+1, b+cnt+1);
        work(1, cnt+1, 1, 1, 1), work(1, cnt+1, 1, 1, -1);
        work(cnt, 0, -1, -1, 1), work(cnt, 0, -1, -1, -1);
    }
}
int main()
{
    cin>>n>>m;
    m+=n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i].x>>a[i].y;
        a[i].y++, a[i].z=1;
    }
    for(int i=n+1; i<=m; i++)
    {
        cin>>a[i].z>>a[i].x>>a[i].y;
        a[i].y++;
    }
    for(int i=1; i<=m; i++)
        maxy=max(maxy, a[i].y);
    memset(tr, 0xcf, sizeof tr);
    memset(res, 0x3f, sizeof res);
    cdq(1, m);
    for(int i=1; i<=m; i++)
        if(a[i].z==2)
            cout<<res[i]<<endl;
    return 0;
}
