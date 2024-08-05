// Problem: 蒲公英
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/description/251/
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
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
constexpr int N=40010, T=210;

int n, m, block;
int a[N], pos[N], f[N];
int d[T][T], g[T][N];
int cnt[N], num[N], tmp[N];
void build()
{
    block=sqrt(n);
    for(int i=1; i<=n; i++)
        pos[i]=(i-1)/block+1;
}
void pre(int x)
{
    int top=0;
    int mx=-1, ans=0;
    for(int i=(x-1)*block+1; i<=n; i++)
    {
        g[x][a[i]]++, cnt[a[i]]++;
        if(cnt[a[i]]==1) tmp[++top]=a[i];
        if(cnt[a[i]]>mx || (cnt[a[i]]==mx && a[i]<ans))
            ans=a[i], mx=cnt[a[i]];
        d[x][pos[i]]=ans;
    }
    while(top) cnt[tmp[top--]]=0;   
}
int query(int l, int r)
{
    int L=pos[l], R=pos[r];
    int ans=0, cnt1=0, top=0;
    if(R-L<2)
    {
        for(int i=l; i<=r; i++)
        {
            cnt[a[i]]++;
            if(cnt[a[i]]==1) tmp[++top]=a[i];
        }
        while(top)
        {
            int x=tmp[top--];
            if(cnt1<cnt[x] || (cnt1==cnt[x] && x<ans))
                ans=x, cnt1=cnt[x];
            cnt[x]=0;
        }
        return ans;
    }
    for(int i=l; i<=pos[l]*block; i++)
    {
        cnt[a[i]]++;
        if(cnt[a[i]]==1)
        {
            tmp[++top]=a[i];
            num[a[i]]=g[L+1][a[i]]-g[R][a[i]];
        }
    }
    for(int i=(R-1)*block+1; i<=r; i++)
    {
        cnt[a[i]]++;
        if(cnt[a[i]]==1)
        {
            tmp[++top]=a[i];
            num[a[i]]=g[L+1][a[i]]-g[R][a[i]];
        }
    }
    ans=d[L+1][R-1];
    num[ans]=g[L+1][ans]-g[R][ans];
    cnt1=cnt[ans]+num[ans];
    while(top)
    {
        int x=tmp[top--];
        cnt[x]=cnt[x]+num[x];
        if(cnt1<cnt[x] || (cnt1==cnt[x] && x<ans))
            ans=x, cnt1=cnt[x];
        cnt[x]=0, num[x]=0;
    }
    return ans;
}
signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>a[i], f[i]=a[i];
    build();
    sort(f+1, f+n+1);
    int _n=unique(f+1, f+n+1)-f-1;
    for(int i=1; i<=n; i++)
        a[i]=lower_bound(f+1, f+_n+1, a[i])-f;
    for(int i=1; i<=pos[n]; i++)
        pre(i);
    int ans=0;
    while(m--)
    {
        int l, r; cin>>l>>r;
        l=(l+ans-1)%n+1, r=(r+ans-1)%n+1;
        if(l>r) swap(l, r);
        ans=f[query(l, r)];
        cout<<ans<<endl;
    }
    return 0;
}
