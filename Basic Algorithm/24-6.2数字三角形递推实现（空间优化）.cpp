/*
空间优化 
*/
#include<bits/stdc++.h>
using namespace std;
#define Max 10005
int *maxSum;
int d[Max][Max];
int n;
int main(){
	cin>>n;
	int i,j;
	for(i=1;i<=n;i++)
	   for(j=1;j<=i;j++)
	   {
	   	   cin>>d[i][j];
	   }
	maxSum=d[n]; //maxSum指向第n行 
	for(i=n-1;i>=1;i--) //从底往上推 
	   for(j=1;j<=i;j++)
	   {
	   maxSum[j]=max(maxSum[j],maxSum[j+1])+d[i][j];//把值都存在最后一行 一直下沉 
	   }
	cout<<maxSum[1]<<endl;
	return 0;  
}
