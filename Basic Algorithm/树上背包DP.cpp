 
/*
7  4
2  2
0  1
0  4
2  1
7  1
7  6
2  2
13

 */
 #include<bits/stdc++.h>
 using namespace std;
 int n,m;
 const int maxn=305;
 int score[maxn],fa[maxn];
 bool vis[maxn];
 int f[maxn][maxn];//f[i][j]以i为根子树分配j个所能达到最大学分
 int head[maxn],tot;
 struct Edge{
 	int to,nxt;
 }edge[maxn*2];
 void add(int from,int to){ //加边 
 	edge[++tot].to=to;edge[tot].nxt=head[from];head[from]=tot;
 }
 void dfs(int u){
 	f[u][1]=score[u];
 	for(int i=head[u];i;i=edge[i].nxt){
 		int v=edge[i].to;
		if(v==fa[i]) continue; //不可少 
 		dfs(v);
 		for(int j=m;j>=1;j--) //0/1背包倒序
		    for(int i=j-1;i>=1;i--) 
		       f[u][j]=max(f[u][j],f[u][j-i]+f[v][i]);
	 }
 }
 int main(){
 	scanf("%d%d",&n,&m);
 	memset(head,-1,sizeof(head));
 	for(int i=1;i<=n;i++){
 		scanf("%d%d",&fa[i],&score[i]);
 		add(fa[i],i);//由父节点指向子节点的单向边 
	 }
	 m++;//由于0号虚拟节点的参与，m需要自加1
	 dfs(0) ;
	 cout<<f[0][m];
	 return 0;
 }
