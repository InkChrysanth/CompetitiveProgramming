/*
树额直径——马拉松 
7 6
1 6 13 E
6 3 9 E
3 5 7 W
4 1 3 S
2 4 20 R
4 7 2 S
输出52 
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN=10010;
struct edge{
	int to,w,nxt;
}e[MAXN<<1];
int i,n,m,u,v,w,ans,tot;
char t[10];
int head[MAXN],dp[MAXN];
void addedge(int u,int v,int w){
	e[++tot].to =v;e[tot].nxt=head[u];head[u]=tot;e[tot].w=w;
}
void dfs(int u,int fa){
	int i,v,w;
	for(i=head[u];i;i=e[i].nxt){
		v=e[i].to;w=e[i].w;
		if(v==fa) continue;
		dfs(v,u); //dp[u]是之前最长链dp[v]是v子树的最长链 
		ans=max(ans,dp[u]+dp[v]+w);
		dp[u]=max(dp[u],dp[v]+w); //更新当前点u的最长链 
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d%d%s",&u,&v,&w,&t);
		addedge(u,v,w);
		addedge(v,u,w);		
	}
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}
