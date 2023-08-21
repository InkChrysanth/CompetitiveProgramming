#include<bits/stdc++.h> 
using namespace std;
#define MAX 101
int d[MAX][MAX];
int maxSum[MAX][MAX];
int n;
int Maxsum(int i,int j)
{
	if(maxSum[i][j]!=-1) return maxSum[i][j]; //已经有答案的不需要计算 
	if(i==n) maxSum[i][j]=d[i][j];
	else{
		int x=Maxsum(i+1,j);
	    int y=Maxsum(i+1,j+1);
	    maxSum[i][j]=max(x,y)+d[i][j];
	}	
	return maxSum[i][j];
}
int main()
{
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	  for(j=1;j<=i;j++){
	  	 cin>>d[i][j];
	  	 maxSum[i][j]=-1;
	  }	      
	cout<<Maxsum(1,1)<<endl; 
	return 0;  
}
