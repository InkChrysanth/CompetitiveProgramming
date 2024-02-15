#include<bits/stdc++.h>
using namespace std;
#define MAX 101
int d[MAX][MAX];
int n;
int Maxsum(int i,int j)
{
	if(i==n) return d[i][j];
	int x=Maxsum(i+1,j);
	int y=Maxsum(i+1,j+1);
	return max(x,y)+d[i][j];
}
int main()
{
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	  for(j=1;j<=i;j++)
	      cin>>d[i][j];
	cout<<Maxsum(1,1)<<endl; 
	return 0;  
}
