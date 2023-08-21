/*
848.有向图的拓扑系列 
*/
#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int d[N],pre[N],q[N],vis[N];
int e[N],ne[N],h[N],idx;
int n,m;
void add(int a,int b){
	e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
bool bfs(){
	int hh=0,rr=0;
	for(int i=1;i<=n;i++){
		if(d[i]==0) q[rr++]=i;
	}
	while(hh<=rr){
		int t=q[hh++];
		for(int i=h[t];i!=-1;i=ne[i]){
			int j=e[i];
			d[j]--; //度为0则入列 
			if(d[j]==0) q[rr++]=j;
//			pre[j]=i;
		}
	}
	return rr==n; //队列中的点数是不是等于总点数 
}
int main(){
	cin.tie(0);
	cin>>n>>m;
	memset(h,-1,sizeof h);
	int a,b;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		add(a,b);
		d[b]++;
	}
	if(!bfs()) puts("-1");
	else{
		for(int i=0;i<n;i++) cout<<q[i]<<" ";
		cout<<endl;
	}
	return 0;
}
