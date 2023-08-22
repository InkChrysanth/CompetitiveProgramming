/*
7
1 1 1 1 1 1 1
1 3
2 3
6 4
7 4
4 5
3 5
0 0
输出 5 
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,e,x,y,a[maxn],to[maxn],nxt[maxn],head[maxn],f[maxn][2];
void dfs(int u,int fa){
     f[u][0]=0;//不参加
	 f[u][1]=a[u];//初始化,参加把点u的值加进去 
	 for(int i=head[u];i;i=nxt[i])	//枚举当前节点u的所有孩子 
	    {
	    	int v=to[i];
	    	if(v==fa)  continue; //剪枝优化 
	    	dfs(v,u); //先计算孩子v的答案 
	    	f[u][0] +=max(f[v][0],f[v][1]); //如果u不参加，u的孩子v可以参加也可以不参加（取最大值） 
	    	f[u][1]+=f[v][0]; //如果u参加，u的孩子v就一定都不能参加 
		}
}
int main(){
	while(scanf("%d",&n)!=EOF){
		e=0;
		memset(head,0,sizeof(head));
		for(int i=1;i<=n;i++) scanf("%d",a+i);//scanf("%d",&a[i]);
		while(scanf("%d%d",&x,&y),x+y){//建边  x+y用来判断是不是输入0,0 
			to[++e]=x;nxt[e]=head[y];head[y]=e;
			to[++e]=y;nxt[e]=head[x];head[x]=e;
		}
		dfs(1,0); //按DFS的顺序DP从第一个节点开始 
		printf("%d\n",max(f[1][0],f[1][1])); //答案为1号点参加和不参加的最大值 
	}
}
