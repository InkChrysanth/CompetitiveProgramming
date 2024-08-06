// Problem: Med-imize
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1993D
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
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

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin>>T;
	for(; T>=1; T--)
	{
		int n, m;
		cin>>n>>m;
		vector<int> a(n+1), b(n+1);
		// floor((n-1)/m) times
		for(int i=1; i<=n; i++)
			cin>>a[i];
		vector<array<int, 2>> f(n+1);
		vector<array<bool, 2>> vis(n+1);
		function<int(int, int)> dfs=[&](int k, int cnt)
		{
			if(k<0 || cnt<0 || m*cnt>k) return -inf;
			if(k==0) return 0;
			int t=cnt-(k-1)/m; //debug(t);
			if(vis[k][t]) return f[k][t];
			vis[k][t]=1;
			return f[k][t]=max(dfs(k-1, cnt)+b[k], dfs(k-m, cnt-1));
		};
		auto check=[&](int mid)
		{
			for(int i=1; i<=n; i++) b[i]=(a[i]>=mid ? 1 : -1);
			for(int i=1; i<=n; i++) vis[i][0]=vis[i][1]=0;
			return dfs(n, (n-1)/m)>0;
		};
		int l=1, r=1e9, ans=r;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(check(mid)) l=mid+1, ans=mid;
			else r=mid-1;
		}
		cout<<ans<<endl;
	}
	return 0;
}
