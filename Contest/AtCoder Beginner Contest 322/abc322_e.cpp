// Problem: E - Product Development
// Contest: AtCoder - AtCoder Beginner Contest 322
// URL: https://atcoder.jp/contests/abc322/tasks/abc322_e
// Memory Limit: 1024 MB
// Time Limit: 4000 ms

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N=110, M=10;
int n, m, p, ans=0x3f3f3f3f;
int a[N], w[N][M], vis[N], s[N];
void dfs(int u, int co)
{
	if(u==m && s[u]>=p){ ans=min(ans, co); return;}
	if(s[u]>=p) dfs(u+1, co);
	for(int i=1; i<=n; i++)
	{
		if(vis[i]) continue;
		for(int j=1; j<=m; j++)
			s[j]+=w[i][j];
		vis[i]=true;
		dfs(u, co+a[i]);
		vis[i]=false;
		for(int j=1; j<=m; j++)
			s[j]-=w[i][j];
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin>>n>>m>>p;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m+1; j++)
			if(j==1) cin>>a[i];
			else cin>>w[i][j-1];
	dfs(1, 0);
	if(ans==0x3f3f3f3f) cout<<"-1"<<endl;
	else cout<<ans<<endl;
	return 0;
}