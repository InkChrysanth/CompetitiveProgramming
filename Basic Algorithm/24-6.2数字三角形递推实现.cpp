#include<bits/stdc++.h>
using namespace std;
#define Max 10005
int maxSum[Max][Max];
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
	for(j=1;j<=n;j++) maxSum[n][j] =d[n][j];
	for(i=n-1;i>=1;i--) //╢с╣вмЫиомф 
	   for(j=1;j<=i;j++)
	   {
	   	maxSum[i][j]=max(maxSum[i+1][j],maxSum[i+1][j+1])+d[i][j];
	   }
	cout<<maxSum[1][1]<<endl;
	return 0;  
}
