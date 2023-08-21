/*
849Dijkstra求最短路1 
*/
#include<bits/stdc++.h>
using namespace std;
const int N=510;
int n,m;
int dist[N],g[N][N];
bool st[N];
int dijkstra(){
	memset(dist,0x3f,sizeof dist);
	dist[1]=0; //起点 

	for(int i=0;i<n;i++){
		int t=-1;
		for(int j=1;j<=n;j++)
			if(!st[j] && (t==-1 ||dist[t]>dist[j]))
			   t=j; //t==-1 ||dist[t]>dist[j])保证第一个入点是1 
//		if(t==-1)	 return -1;   
		for(int j=1;j<=n;j++)	   
	        dist[j]=min(dist[j],dist[t]+g[t][j]);
	    st[t]=true;
	}
	if(dist[n]==0x3f3f3f3f) return -1;
	return dist[n];
}
int main(){
	cin>>n>>m;
	memset(g,0x3f,sizeof g);
	int a,b,c;
	while(m--){
		cin>>a>>b>>c;
		g[a][b]=min(g[a][b],c);
	}
	int t=dijkstra();
	cout<<t<<endl;
	return 0;
}
