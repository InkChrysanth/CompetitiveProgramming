/*
859Kruskal求最小生成树 
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=2*N;
int f[N];
int find(int x){
	if(x!=f[x]) f[x]=find(f[x]);
	return f[x];
}
struct node{
	int u,v,w;
	bool operator <(const node &p) const{
		return w<p.w;
	}
}edge[M];
int main(){
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		edge[i]={u,v,w};
	}
	sort(edge+1,edge+1+m);
	for(int i=1;i<=n;i++) f[i]=i;
	int res=0,count=0;
	for(int i=1;i<=m;i++){
		int u=edge[i].u,v=edge[i].v,w=edge[i].w;
		int x=find(u),y=find(v);
		if(x!=y) {
			f[x]=y; //不能忘 
			res+=w;
			count++;
			if(count==n-1) break;
		}		
	}
	if(count<n-1) cout<<"impossible"<<endl;
	else
	   cout<<res<<endl;
}
