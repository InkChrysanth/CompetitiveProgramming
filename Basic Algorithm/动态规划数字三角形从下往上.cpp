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
	for(i=1;i<=n;i++)f[n][i]=a[n][i] ; //初始边界值 
	for(i=n-1;i>=1;i--){		
		for(j=1;j<=i;j++)  //从下往上 
	   	    f[i][j]=max(f[i+1][j],f[i+1][j+1])+a[i][j]; 
	}	   
	cout<<f[1][1]<<endl;
	return 0;
}
