#include <bits/stdc++.h>
using namespace std;
const int N=100010, M=2*N;
int n, m;
struct Node
{
    int a, b, c, s, res;
    bool operator <(const Node &T)const
    {
        if(a!=T.a) return a<T.a;
        if(b!=T.b) return b<T.b;
        return c<T.c;
    }
    bool operator ==(const Node &T)const
    {
        return a==T.a && b==T.b && c==T.c;
    }
}q[N], w[N];
int tr[M], ans[N];
int lowbit(int x)
{
    return x&-x;
}
void add(int x, int v)
{
    for(int i=x; i<M; i+=lowbit(i))
        tr[i]+=v;
}
int query(int x)
{
    int res=0;
    for(int i=x; i; i-=lowbit(i))
        res+=tr[i];
    return res;
}
void merge_sort(int l, int r)
{
    if(l==r) return;
    int mid=l+r>>1;
    merge_sort(l, mid);
    merge_sort(mid+1, r);
    int k=0, i=l, j=mid+1;
    while(i<=mid && j<=r)
        if(q[i].b<=q[j].b) add(q[i].c, q[i].s), w[k++]=q[i++];
        else q[j].res+=query(q[j].c), w[k++]=q[j++];
    while(i<=mid) add(q[i].c, q[i].s), w[k++]=q[i++];
    while(j<=r) q[j].res+=query(q[j].c), w[k++]=q[j++];
    for(int i=l; i<=mid; i++) add(q[i].c, -q[i].s);
    for(int i=l, j=0; j<k; i++, j++) q[i]=w[j];
}
int main()
{
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        q[i]={a, b, c, 1};
    }
    stable_sort(q, q+n);
    int k=1;
    for(int i=1; i<n; i++)
    {
        if(q[i]==q[k-1]) q[k-1].s++;
        else q[k++]=q[i];
    }
    merge_sort(0, k-1);
    for(int i=0; i<k; i++)
        ans[q[i].res+q[i].s-1]+=q[i].s;
    for(int i=0; i<n; i++)
        cout<<ans[i]<<endl;
    return 0;
}
