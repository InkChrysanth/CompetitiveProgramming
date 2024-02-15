/*
强联通分量：kosaraju算法+邻接点+栈 
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=99;
int A1[maxn][maxn],A2[maxn][maxn];//邻接点
int vis1[maxn],vis2[maxn];//访问标记 
int Stack[maxn],s;//栈、指针 
int Set[maxn],num;//记录哪一个连通图，计数器 
void dfs1(int u){//深搜原图 
	int i,v;
	for(i=1;i<=A1[u][0];i++){
		v=A1[u][i];//取出U的邻接点
		if(!vis1[v]){
			vis1[v]=1;//标记 
			dfs1(v);//深搜原图 
		}
	}
	Stack[++s]=u;//后序入栈 
	printf("%d ",u);//跟踪 
}
void dfs2(int u){//深搜反图 
	int i,v;
	Set[u]=num;//下标存储第num个联通图的某个点 
	for(i=1;i<=A2[u][0];i++){
		v=A2[u][i];//取出u的邻接点 
		if(!vis2[v]){
			vis2[v]=1;//标记 
			dfs2(v);//深搜反图 
		}
	}	
}
int main(){
	int i,j,n=9,m=12,a,b;
	int E[15][3]={{1,2},{2,3},{3,1},{1,4},{4,5},{5,6},
	              {5,7},{7,6},{6,4},{5,8},{8,9},{9,8}};
	for(i=0;i<m;i++){
		a=E[i][0];b=E[i][1];
		A1[a][++A1[a][0]]=b;//存储原图 
		A2[b][++A2[b][0]]=a;//存储反图 
	}              
	printf("入栈顺序：");
	for(i=1;i<=n;i++){
		if(!vis1[i]){
			vis1[i]=1;//标记 
			dfs1(i);//深搜原图 
		}
	}
	while(s){
		a=Stack[s--];//出栈 
		if(!vis2[a]){
			vis2[a]=1;//标记 
			num++;
			dfs2(a);//深搜反图 
		}
	}
	for(i=1;i<=num;i++){//输出各个连通图 
		printf("\n强联通分量%d: ",i);
		for(j=1;j<=n;j++)
		   if(Set[j]==i) printf("%d ",j);
	}
}
