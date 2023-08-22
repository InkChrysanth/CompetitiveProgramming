/*
树的重心 
    将树上的一个节点删除后会得到多个联通块，求删去哪些点后，所得到的联通块的
节点的最大值最小。这个被删除的点通常把它称为树的重心。	 
6
1 2
2 3
2 5
3 4
3 6
输出
2 3 
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=55555;
const int maxm=111111;
int tot,ans,x,y,n,f[maxn],head[maxn],nxt[maxm],edg[maxm],cnt[maxn];
bool vis[maxn];
void AddEdge(int x,int y){ //建边 
	edg[++tot]=y;nxt[tot]=head[x];head[x]=tot;
}
void dfs(int u,int fa){
	cnt[u]=1;//cnt[x]记录以u为根的子树的大小
	for(int j=head[u];j;j=nxt[j]) { //枚举u的每一个孩子 
		int v=edg[j];
		if(v!=fa){
			dfs(v,u); //先计算v的答案 		
			f[u]=max(f[u],cnt[v]); //u的最大子树 
			cnt[u]+=cnt[v]; //u为根子树大小 
		}
	}
	f[u]=max(f[u],n-cnt[u]); //删除u后，u的父亲所在的联通块的大小为n-cnt[u] 
	ans=min(ans,f[u]); //要求联通块尽可能小 
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		AddEdge(x,y);AddEdge(y,x);
	}
	ans=n;//找联通块最小，打擂台
	dfs(1,0) ;//自底向上 
	for(int i=1;i<=n;i++)
	    if(f[i]==ans) printf("%d ",i);
	printf("\n")    ;
	return 0;
}
