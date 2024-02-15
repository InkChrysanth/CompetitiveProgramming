/*
5 20
7 72 2
2 2 1
9 67 1
5 26 1
8 70 1
数组b[i]存放物品i最多能被选的次数 
*/
/*
#include<bits/stdc++.h>
using namespace std;
int w[100],b[100],p[100],f[500],n,m;
int main(){
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>w[i]>>p[i]>>b[i];
	memset(f,0,sizeof(f));
	for(i=1;i<=n;i++){
		for(j=m;j>=w[i];j--) 
		   for(int k=0;k<=b[i];k++)
	       f[j]=max(f[j],f[j-w[i]*k]+p[i]*k);
	}	   
	cout<<f[m];       
}
*/
