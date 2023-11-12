// Problem: C - Festival
// Contest: AtCoder - AtCoder Beginner Contest 322
// URL: https://atcoder.jp/contests/abc322/tasks/abc322_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N=200010;
int a[N], ans[N], vis[N];
int n, m;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1; i<=m; i++)
		{int x; cin>>x;vis[x]=true;}
	int res=0;
	for(int i=n; i; i--)
	{
		if(vis[i]) ans[i]=0, res=0;
		else ans[i]=++res;
	}
	for(int i=1; i<=n; i++)
		cout<<ans[i]<<endl;
	return 0;
}