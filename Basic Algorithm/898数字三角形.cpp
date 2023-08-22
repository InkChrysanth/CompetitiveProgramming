#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int INF= 1e9+7;
int a[N][N],f[N][N];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	   for(int j=1;j<=i;j++)
	      cin>>a[i][j];
	for(int i=0;i<=n;i++)      
	    for(int j=0;j<=i+1;j++)
	       f[i][j]=-INF;
	f[1][1]=a[1][1];
	for(int i=2;i<=n;i++)  //记住一定要从2开始 
	   for(int j=1;j<=i;j++)  
	      f[i][j]=max(f[i-1][j-1],f[i-1][j])+a[i][j];
	int ans=-INF;      
	for(int i=1;i<=n;i++)  
	    ans=max(ans,f[n][i])  ;  
	cout<<ans<<endl;
	return 0;    
}
