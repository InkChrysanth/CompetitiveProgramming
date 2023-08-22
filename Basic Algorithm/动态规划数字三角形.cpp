/*
动态规划之数字三角形 
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=100;
int a[maxn][maxn],f[maxn][maxn],n;
int main(){
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	   for(j=1;j<=i;j++)
	       cin>>a[i][j];
	f[1][1]=a[1][1] ;
	for(i=2;i<=n;i++){
		f[i][1]=f[i-1][1]+a[i][1];//左边界情况处理 
		for(j=2;j<i;j++)  //中间情况处理 j范围2-(i-1) ;
	   	    f[i][j]=max(f[i-1][j],f[i-1][j-1])+a[i][j]; 
		f[i][i]=f[i-1][i-1]+a[i][i];//右边界情况处理 
	}	   
	int ans=f[n][1]      ;
	for(i=2;i<=n;i++)  ans=max(ans,f[n][i]);
	cout<<ans<<endl;
	return 0;
}
