#include<bits/stdc++.h>
using namespace std;
int a[105],w[105][105];
int main(){
	int n,m,i,j;
	cin>>n>>m;
	memset(w,0,sizeof(w));
	for(i=1;i<=m;i++){
		cin>>a[i];
		w[0][i]=1;
	}
	w[0][0]=1;
	for(i=1;i<=n;i++)
	    for(j=1;j<=m;j++){
	    	w[i][j]=w[i][j-1];
	    	if(i-a[j]>=0) w[i][j]+=w[i-a[j]][j-1];
		}
	cout<<w[n][m]<<endl;
	return 0;	
}
