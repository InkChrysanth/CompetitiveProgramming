/*
3
3
0 1
1 2
2 0
3
2
0 1
0 2
*/
#include<bits/stdc++.h>
using namespace std;
const int N=505;
int m,n;
int color[N];
vector<int>node[N];
bool dfs(int v,int c){
	color[v]=c;
	//为当前顶点上色 
	for(int i=0;i<node[v].size();i++){
		//遍历所有与之连接的顶点，即相邻顶点 
		if(color[node[v][i]]==c)
		//如果相邻的顶点同色，就返回false 
		     return false;
		if(color[node[v][i]]==0 && !dfs(node[v][i],-c)) 
		//如果相邻顶点未染色，就将其染为相反颜色即-c,并继续dfs 
		     return false;
	}
	return true;
	//直到所有顶点都被染色，且没出现相邻同色顶点，就返回true 
}
void solve(){
	for(int i=0;i<n;i++){
	//遍历所有顶点	
		if(color[i]==0){
	    //如果未染色，就进入深搜		
			if(!dfs(i,1)){ //只要有一点不满足就退出 
				printf("NOT BICOLORABLE.\n");
				//如果返回false值，就不是二分图 
				return ; //结束深搜 
			}
		}
	}
	printf("BICOLORABLE.\n");
	//未出现相邻同色，就是二分图 
}
int main(){
	int u,v;
	while(scanf("%d%d",&n,&m)){
		memset(node,0,sizeof(node));
		memset(color,0,sizeof(color));
		for(int i=0;i<m;i++){
			cin>>u>>v; //因为是无向图，所以要双向插入顶点 
			node[u].push_back(v); //在u点后插入v顶点 
			node[v].push_back(u); //在v点后插入u顶点 
		}
		solve();
	}
	return 0;
}
