/*
开心的金明
 10 5
 8 2
 4 5
 3 5
 4 3
 2 2
 输出39 
*/ 
#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int n,m,v[maxn],w[maxn],p[maxn],f[maxn][maxn];
int main(){
	cin>>m>>n;
	for(int i=1;i<=5;i++){
		cin>>v[i]>>w[i];
		p[i]=v[i]*w[i];
	}
	for(int i=1;i<=n;i++) f[i][0]=0;
	for(int i=1;i<=m;i++) f[0][i]=0;
	for(int i=1;i<=n;i++)
	   for(int j=1;j<=m;j++){
	   	if(j<v[i]) f[i][j]=f[i-1][j];
	   	if(j>=v[i]) f[i][j]=max(f[i-1][j],f[i-1][j-v[i]]+p[i]);
	   }
	cout<<f[n][m] <<endl;  
	return 0; 
}
