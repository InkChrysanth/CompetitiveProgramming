#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

#define cmin(i,j) (i)=min((i),(j))
#define cmax(i,j) (i)=max((i),(j))
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define Fi(s) freopen(s,"r",stdin)
#define Fo(s) freopen(s,"w",stdout)
#define Fre(s) Fi(s".in"),Fo(s".out")
#define all(x) x.begin(), x.end()
#define each(i,x) for(auto &i:(x))
#define fi first
#define se second
#define endl '\n'
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define eb emplace_back

using ll=long long;
using ld=long double;
using pii=pair<int, int>;
using pli=pair<ll, int>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;
constexpr int mod=1e9+7;
constexpr int N=100010;

int n, m;
int a[N];

struct Node
{
    int l, r;
    int add, mul;
    int sum, sum2;
}tr[N<<2];

void solve(int u, int add, int mul)
{
    int len=tr[u].r-tr[u].l+1;
    tr[u].mul=1ll*tr[u].mul*mul%mod;
    tr[u].add=1ll*tr[u].add*mul%mod;
    tr[u].add=((tr[u].add+add)%mod+mod)%mod;
    if(mul!=1)
    {
        tr[u].sum=1ll*tr[u].sum*mul%mod;
        tr[u].sum2=(1ll*tr[u].sum2*mul%mod)*mul%mod;
    }
    if(add!=0)
    {
        int a2=1ll*add*add%mod;
        tr[u].sum2=((tr[u].sum2+2ll*(ll)tr[u].sum%mod*add%mod)+mod)%mod;
        tr[u].sum2=((tr[u].sum2+(ll)len*a2%mod)+mod)%mod;
        tr[u].sum=((tr[u].sum+(ll)len*add%mod)+mod)%mod;
    }
}

void pushup(int u)
{
    tr[u].sum=(tr[u<<1].sum+tr[u<<1|1].sum)%mod;
    tr[u].sum2=(tr[u<<1].sum2+tr[u<<1|1].sum2)%mod;
}

void build(int u, int l, int r)
{
    tr[u].l=l, tr[u].r=r;
    tr[u].add=0, tr[u].mul=1;
    if(l==r)
    {
        tr[u].sum=a[l];
        tr[u].sum2=(1ll*a[l]*a[l])%mod;
        return;
    }
    int mid=(l+r)>>1;
    build(u<<1, l, mid);
    build(u<<1|1, mid+1, r);
    pushup(u);
}

void pushdown(int u)
{
    solve(u<<1, tr[u].add, tr[u].mul);
    solve(u<<1|1, tr[u].add, tr[u].mul);
    tr[u].add=0, tr[u].mul=1;
}

void modify(int u, int l, int r, int add, int mul)
{
    if(l<=tr[u].l && tr[u].r<=r)
    {
        solve(u, add, mul);
        return;
    }
    pushdown(u);
    int mid=(tr[u].l+tr[u].r)>>1;
    if(l<=mid) modify(u<<1, l, r, add, mul);
    if(r>mid) modify(u<<1|1, l, r, add, mul);
    pushup(u);
}

int query(int u, int l, int r, int k)
{
    if(l<=tr[u].l && tr[u].r<=r)
        return (k==1 ? tr[u].sum : tr[u].sum2);
    pushdown(u);
    int res=0;
    int mid=(tr[u].l+tr[u].r)>>1;
    if(l<=mid) (res+=query(u<<1, l, r, k))%=mod;
    if(r>mid) (res+=query(u<<1|1, l, r, k))%=mod;
    return res; 
}

signed main()
{
    Fre("sequence");
	cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    build(1, 1, n);
    for(int opt, l, r, p; m>=1; m--)
    {
        cin>>opt>>l>>r;
        switch(opt)
        {
            case 1:
                cout<<query(1, l, r, opt)<<endl;
                break;
            case 2:
                cout<<query(1, l, r, opt)<<endl;
                break;
            case 3:
                cin>>p;
                for(int i=1; i<=r; i++)
                {
                    int x=a[i]/p;
                    modify(1, i, i, x, 0);
                }
                break;
            case 4:
                a[l]=r;
                modify(1, l, l, r, 0);
                break;
            default: break;
        }
    }
	return 0;
}
