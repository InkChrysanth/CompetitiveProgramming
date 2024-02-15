/*
5 20
7 72
2 2
9 67
5 26
8 70
*/
#include<bits/stdc++.h>
using namespace std;
int w[100],p[100],f[500],n,m;
int main(){
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>w[i]>>p[i];
	memset(f,0,sizeof(f));
	for(i=1;i<=n;i++){
		for(j=m;j>=w[i];j--)
	       f[j]=max(f[j],f[j-w[i]]+p[i]);
	}	   
	cout<<f[m];       
}
