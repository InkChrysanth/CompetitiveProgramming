#include<bits/stdc++.h>
using namespace std;
const int N=210;
#define INF 1e9 
int n,m,Q;
int d[N][N];
void floyed(){
	for(int k=1;k<=n;k++)
	   for(int i=1;i<=n;i++)
	      for(int j=1;j<=n;j++){
	      	d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		  }
}
int main(){
	cin.tie(0);
	cin>>n>>m>>Q;
	for(int i=1;i<=n;i++)
	   for(int j=1;j<=n;j++){
	   	if(i==j) d[i][j]=0; //自环 
	   	else d[i][j]=INF;
	   }
	while(m--)   {
		int a,b,c;
		cin>>a>>b>>c;
		d[a][b]=min(d[a][b],c); //去重边保存最小边 
	}
	floyed();
	while(Q--){
		int x,y;
		cin>>x>>y;
		if(d[x][y]>INF/2) cout<<"impossible"<<endl;
		else cout<<d[x][y];
	}
	return 0;
}
