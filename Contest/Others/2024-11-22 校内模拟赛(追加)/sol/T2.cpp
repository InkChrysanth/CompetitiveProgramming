#include<cstdio>
#include<algorithm>
#define fo(i,a,b) for(i=a;i<=b;i++)
using namespace std;
typedef long long ll;
const int maxn=100000+10,maxtot=3500000+10,maxd=1e9;
ll left[maxtot],right[maxtot];
ll tree[maxtot];
ll T[maxn],b[maxn],c[maxn],e[maxn];
ll f[maxn];
ll i,j,k,l,t,n,m,tot,root,A,D;
ll read(){
    int x=0,f=1;
    char ch=getchar();
    while (ch<'0'||ch>'9'){
        if (ch=='-') f=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
void change(ll &x,ll l,ll r,ll a,ll b){
    if (!x) x=++tot,tree[x]=1e18;
    if (l==r){
        tree[x]=min(tree[x],b);
        return;
    }
    ll mid=(l+r)/2;
    if (a<=mid) change(left[x],l,mid,a,b);else change(right[x],mid+1,r,a,b);
    tree[x]=min(tree[left[x]],tree[right[x]]);
}
ll query(ll x,ll l,ll r,ll a,ll b){
    if (!x||a>b) return 1e18;
    if (l==a&&r==b) return tree[x];
    ll mid=(l+r)/2;
    if (b<=mid) return query(left[x],l,mid,a,b);
    else if (a>mid) return query(right[x],mid+1,r,a,b);
    else return min(query(left[x],l,mid,a,mid),query(right[x],mid+1,r,mid+1,b));
}
int main(){
    k=read();m=read();D=read();A=read();n=read();
    fo(i,1,n) T[i]=read(),b[i]=read();
    T[0]=k;T[++n]=m;
    fo(i,0,n){
        c[i]=T[i]/D;
        e[i]=T[i]%D;
    }
    tree[0]=1e18;
    change(root,0,D-1,e[0],-c[0]*A);
    fo(i,1,n){
        f[i]=1e18;
        j=query(root,0,D-1,0,e[i]-1);
        f[i]=min(f[i],j+A+c[i]*A-b[i]);
        j=query(root,0,D-1,e[i],D-1);
        f[i]=min(f[i],j+c[i]*A-b[i]);
        change(root,0,D-1,e[i],f[i]-c[i]*A);
    }
    printf("%lld\n",-f[n]);
    return 0;
}
