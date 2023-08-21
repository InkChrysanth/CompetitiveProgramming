/*
858Prim算法求最小生成树 
4 5
1 2 1
1 3 2
1 4 3
2 3 2
3 4 4
*/
#include<bits/stdc++.h>
using namespace std;
const int N=510,M=100010,INF=0x3f3f3f3f;
int dist[N],n,m;
int d[N][N];
bool st[N];
int prim(){
    memset(dist,0x3f,sizeof dist);
    int res=0;
    for(int i=0;i<n;i++){
    	int t=-1;
    	for(int j=1;j<=n;j++)
    	    if(!st[j] && (t==-1 ||dist[t]>dist[j]))
    	         t=j;
    	if(i && dist[t]==INF)  return INF;
		if(i)   res+=dist[t]  ;
		st[t]=true;
		for(int j=1;j<=n;j++)
		   dist[j]=min(dist[j],d[t][j]);
	}
	return res;
}
int main(){
	cin.tie(0);	
	cin>>n>>m;
	memset(d,0x3f,sizeof d);
	while(m--){
		int a,b,c;
		cin>>a>>b>>c;
		d[a][b]=d[b][a]=min(d[a][b],c);
	}
	int x=prim();
	cout<<x<<endl;
	return 0;
}
