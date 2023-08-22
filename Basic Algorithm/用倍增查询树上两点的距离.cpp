/*
给定一棵树n个点，q个询问，每次询问点x到点y两点之间的距离。1<=q,n<=10^5
6
1 2
1 3
2 4
2 5
3 6
2
2 6
5 6
输出
3
4 
*/
#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n,m,tot,dep[N],f[N][22],dis[N],head[N];
struct node{ //手工链表 
	int to,nxt,w;
}e[2*N];
void add(int x,int y){ //建树 
	e[++tot].to=y;e[tot].nxt=head[x];head[x]=tot;
}
void dfs(int u,int fa){ //预处理倍增数组 
	dep[u]=dep[fa]+1;
	f[u][0]=fa;
	for(int i=1;i<=20;i++)
	   f[u][i]=f[f[u][i-1]][i-1];
	for(int i=head[u];i>0;i=e[i].nxt)   { //用递归函数处理每一个分支 
		int v=e[i].to;
		if(v==fa) continue;
		dfs(v,u);
	}
}
int lca(int x,int y){ //找公共祖先 
	if(dep[x]<dep[y]) swap(x,y);
    for(int i=20;i>=0;i--){ //达到相同高度 
    	if(dep[f[x][i]]>=dep[y])
    	   x=f[x][i];
	}
	if(x==y) return x;
	for(int i=20;i>=0;i--){ //到达相同高度后开始一起起跳 
		if(f[x][i]!=f[y][i]){
			x=f[x][i];y=f[y][i];
		}
	}
	return f[x][0];
}
int query(int u,int v){ //查询结果 
	return dep[u]+dep[v]-2*dep[lca(u,v)];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){ //初始化树 
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y); 
		add(y,x); //双向  
	}
	dfs(1,0); //预处理倍增数组 
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",query(x,y)); //输出询问结果 
	}
	return 0;
}
}
