/*
强联通分量：tarjan算法+邻接点+栈 
*/
#include<bits/stdc++.h>
using namespace std;
int A[100][100];//邻接点 
int Dfn[100],num;//记录点的访问次序 
int Low[100];//动态改小点的访问次序 
int Stack[100],t;//顶点入栈，分量出栈 
bool out[100];//出栈标记 
void DFS(int u){//深搜算法 
	int i,v;
	Dfn[u]=Low[u]=++num;//记录u的访问次序 
	Stack[++t]=u;//入栈 
	for(i=1;i<=A[u][0];i++){
		v=A[u][i];//取出u点的邻接点 
		if(Dfn[v]==0){//v没访问过 
			DFS(v);//调用，回溯到点u时，改小Low[u] 
			Low[u]=min(Low[u],Low[v]);
		}//v已访问且在栈中，说明u,v已构成环 
		else if(!out[v]){//森林不能去掉 
			Low[u]=Low[v];//有环时，改小Low[u] 
		}
	}//
	if(Dfn[u]==Low[u]){//u是分量的根 
		printf("强联通分量:");
		while(Stack[t]!=u){
			printf("%d ",Stack[t]);
			out[Stack[t--]]=1;//出栈标记 
		}//u之后访问的点均出栈 
		printf("%d ",u); //u出栈标记 
		out[Stack[t--]]=1;
		cout<<endl;
	}
}
int main()
{
	int i,j,u,v,N=9,M=13;
	int E[20][2]={{1,2},{1,7},{2,3},{2,5},{2,9},{3,4},{4,2},
	              {5,6},{5,7},{5,8},{6,5},{8,6},{9,1} };
	for(i=0;i<M;i++){
		u=E[i][0];v=E[i][1];
		A[u][++A[u][0]]=v;//邻接点 
	} 
	for(i=1;i<=N;i++)  //图可能为森林           
	   if(Dfn[i]==0)//i没访问过 
	      DFS(i);//深搜 
	return 0;      
}
