// Problem: 加分二叉树
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/481/
// Memory Limit: 128 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N=40;
int n;
int w[N], f[N][N];
void dfs(int l, int r)
{
	if(l==r){cout<<l<<' '; return;}
	else if(l<r)
	{
		for(int k=l; k<=r; k++)
			if(f[l][r]==w[k]+f[l][k-1]*f[k+1][r])
			{
				cout<<k<<' ';
				dfs(l, k-1);
				dfs(k+1, r);
				break;
			}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin>>n;
	for(int i=0; i<=n; i++)
		f[i+1][i]=1;
	for(int i=1; i<=n; i++)
		cin>>w[i];
	for(int len=1; len<=n; len++)
		for(int i=1; i+len-1<=n; i++)
		{
			int j=i+len-1;
			if(len==1) f[i][i]=w[i];
			else for(int k=i; k<=j; k++)
				f[i][j]=max(f[i][j], w[k]+f[i][k-1]*f[k+1][j]);
 		}
 	cout<<f[1][n]<<endl;
 	dfs(1, n);
	return 0;
}