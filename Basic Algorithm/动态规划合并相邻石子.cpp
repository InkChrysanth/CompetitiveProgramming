/*
7
13 7 8 16 21 4 18
最后一次归并：必然是先将1-k堆沙子归并成一堆，将（k+1）~n堆 
沙子归并成一堆，然后再将这两堆沙子归并
K:1~(n-1)
f[i][j]:将i~j堆沙子归并成一堆时的最小归并总代价
目标：F[1][n]
f[i][j]= 0 1<=i<=n,j=i
f[i][j]=min(f[i][k]+f[k+1][j]+s[j]-s[i-1]) 1<=i<=n,i<j<=n 
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
int a[maxn],s[maxn],f[maxn][maxn],n;
int main(){
	int i,j,k,p,m;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];f[i][i]=0;
		s[i]=s[i-1]+a[i]; //前缀和 
	}
	for(p=2;p<=n;p++) { //区间长度,阶段（已经合并在一起的有几堆了） 
		for(i=1;i<=n-p+1;i++)// 枚举区间起点 
		{
			j=i+p-1;//区间终点（区间大小决定j的边界，已经合并几堆了剩下的从哪一堆开始） 			
			m=INT_MAX;
			for(k=i;k<j;k++)
				m=min(m,f[i][k]+f[k+1][j]); //可能的决策，枚举中间点 
			f[i][j]=m+s[j] -s[i-1] ; //需要预处理前缀和s 			
		}
	}
	cout<<f[1][n];
	return 0;
}
