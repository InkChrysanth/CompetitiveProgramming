/*
给定一棵树n个点，带边权，q个询问，每次询问点x到点y两点之间的距离。1<=q,n<=10^4
6 2
1 2 100
1 3 50
2 4 40
2 5 60
3 6 30
2 6
5 6
输出
180
240 
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
	int t,d;
	node(int _t,int _d){t=_t;d=_d;}
};
vector<node>e[2*N];
int n,m;
int dep[N],f[N][22],dis[N];
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	f[u][0]=fa;
	for(int i=1;i<=20;i++)
	    f[u][i]=f[f[u][i-1]][i-1];
	int k=e[u].size()  ;  
	for(int i=0;i<k;i++) {
		int v=e[u][i].t,d=e[u][i].d;
		if(v==fa) continue;
		dis[v]=dis[u]+d; // 处理权值 
		dfs(v,u);
	}   
}
int swim(int x,int h){ //位处理 
	for(int i=0;h>0;i++){
		if(h%2==1) x=f[x][i];
		h>>1;
	}
	return x;
}
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	x=swim(x,dep[x]-dep[y]);
	if(x==y) return x; 
	for(int i=20;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];y=f[y][i];
		}
	}
	return f[x][0];
}
int query(int x,int y){
	return dis[x]+dis[y]-2*dis[lca(x,y)];
}
int main(){
	int i,j,k;
	cin>>n>>m;
	for(i=1;i<n;i++){
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back(node(y,z));
		e[y].push_back(node(x,z));
	}
	dfs(1,0);
	for(i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		cout<<query(x,y)<<endl;
	}
	return 0;
}
