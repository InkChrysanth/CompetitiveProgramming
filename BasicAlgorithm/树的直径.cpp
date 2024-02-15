/*
树的直径 
7 6
1 6 13 E
6 3 9 E
3 5 7 S
4 1 3 N
2 4 20 W
4 7 2 S
输出52 
*/
void dfs(int u,int fa){ //直径模板 
	int mx=0;//mx为u节点的最长链
	for(int i=head[u];i;i=e[i].nxt) {
		int v=e[i].to,w=e[i].w;
		if(v==fa) continue ;
		dfs(v,u);//v的最长+u之前最长链 +w
		ans=max(ans,mx+w+dp[v]) ;
		mx=max(mx,dp[v]+w);
	}
	dp[u]=mx;//访问完u的所有子树后更新当前u的最长链 
}
