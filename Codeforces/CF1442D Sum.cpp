#include <bits/stdc++.h>
#define int_rd (int)read()
#define ll_rd read()
#define endl '\n'
#define mp make_pair
#define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

inline ll read()
{
	ll a=0; int f=0; char p=getchar();
	while(!isdigit(p)){f|=p=='-'; p=getchar();}
	while(isdigit(p)){a=(a<<3)+(a<<1)+(p^48); p=getchar();}
	return f?-a:a;
}

const int N=3010, M=1000010;
int n, k, ans;
vector<int> a[N];
int sz[N], sum[N], f[N];

void dfs(int l, int r)
{
    int mid=(l+r)>>1;
    if(l==r)
    {
        int cur=0;
        for(int i=0; i<=min(k, sz[l]); i++)
        {
            ans=max(ans, cur+f[k-i]);
            cur+=a[l][i];
        }
        return;
    }
    int backup[N];
    memcpy(backup, f, sizeof backup);
    for(int i=l; i<=mid; i++)
    {
        for(int j=k; j>=sz[i]; j--)
            f[j]=max(f[j], f[j-sz[i]]+sum[i]);
    }
    dfs(mid+1, r);
    memcpy(f, backup, sizeof f);
    for(int i=mid+1; i<=r; i++)
    {
        for(int j=k; j>=sz[i]; j--)
            f[j]=max(f[j], f[j-sz[i]]+sum[i]);
    }
    dfs(l, mid);
}

signed main()
{
	n=ll_rd, k=ll_rd;
    for(int i=1; i<=n; i++)
    {
        sz[i]=ll_rd;
        for(int j=1; j<=sz[i]; j++)
        {
            int x=ll_rd;
            a[i].emplace_back(x);
            sum[i]+=x;
        }
    }
    dfs(1, n);
    cout<<ans<<endl;
	return 0;
}