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
#define endl "\n"
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define em emplace

using ll=long long;
using ull=unsigned long long;
using ld=long double;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;
constexpr int N=400010, K=21;

int n, m;
int a[N], s[N];
int f[N][K];

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>a[i], a[i+n]=a[i];
    for(int i=1; i<=2*n; i++) s[i]=s[i-1]+a[i];
    ll l=1, r=2e9, ans=l;
    auto check=[&](int mid)
    {
    	for(int l=1, r=1; l<=2*n; l++)
    	{
    		while(r+1<=2*n && s[r]-s[l-1]<mid) r++;
    		if(s[r]-s[l-1]>=mid) f[l][0]=r+1;
			else f[l][0]=2*n+1;
		}
		f[2*n+1][0]=2*n+1;
		for(int k=1; k<K; k++)
			for(int i=1; i<=2*n+1; i++)
				f[i][k]=f[f[i][k-1]][k-1];
		int res=0;
		for(int i=1; i<=n; i++)
		{
			int p=i, cnt=0;
			for(int k=K-1; k>=0; k--)
			{
				if(f[p][k]<=i+n)
					p=f[p][k], cnt+=(1<<k);
			}
			if(cnt>=m) res++;
		}
		return res;
	};
	while(l<=r)
    {
    	ll mid=(l+r)/2;
    	if(check(mid)) l=mid+1, ans=mid;
    	else r=mid-1;
	}
	cout<<ans<<" "<<n-check(ans)<<endl;
	return 0;
}
