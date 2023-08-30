// Problem: B3624 猫粮规划
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/B3624
// Memory Limit: 128 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N=42;
int n, l, r, cnt=0;
int w[N], b[N];
void dfs(int u, int sum)
{
	if(sum+b[n]-b[u-1]<l || sum>r) return;
	if(u==n+1)
	{
		if(sum>=l && sum<=r) cnt++;
		return;
	}
	dfs(u+1, sum+w[u]);
	dfs(u+1, sum);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>l>>r;
	for(int i=1; i<=n; i++) cin>>w[i];
	for(int i=1; i<=n; i++) b[i]=b[i-1]+w[i];
	dfs(1, 0);
	cout<<cnt<<endl;
	return 0;
}