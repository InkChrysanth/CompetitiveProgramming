/*
动态规划从n个数中取k个数的和最大 
动态规划5个要素

阶段：
状态：
决策
策略
状态转移方程： 
*/ 
#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int a[maxn],f[maxn][maxn],n,k;
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)f[i][1]=a[i];
	for(int i=1;i<=n;i++)
	   for(int j=1;j<=k;j++)
	      f[i][j]=max(f[i-1][j],f[i-1][j-1]+a[i]);//到第i个数时有两种情况，取与不取i 
	cout<<f[n][k]<<endl;
}
