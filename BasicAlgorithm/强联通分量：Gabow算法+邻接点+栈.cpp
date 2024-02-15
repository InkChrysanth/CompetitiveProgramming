/*
强联通分量：Gabow(加博)算法+邻接点+栈 
*/
#include<bits/stdc++.h>
using namespace std;
int A[100][100]; //邻接点 
int Dfn[100],num; //记录点的访问次序 
int Stack1[100],t1; //顶点入栈、分量出栈 
int Stack2[100],t2; //动态维护分量的根 
bool out[100]; //出栈标记 
void DFS(int u){ //深搜算法 
	int i,v;
	Dfn[u]=++num; //记录U的访问次序 
	Stack1[++t1]=Stack2[++t2]=u; //入栈 
	for(i=1;i<=A[u][0];i++){
		v=A[u][i]; //取出U的邻接点 
		if(Dfn[v]==0){ //v没访问过 
			DFS(v); //调用 
		}
		else if(out[v]==0){//v已访问还没出栈，有环 
			while(Dfn[Stack2[t2]]>Dfn[v]){
				--t2;
			} //v之后访问的点弹出栈2 
		}
	} 
	//向上层回溯前，判断根 
	if(u==Stack2[t2]){ //u是分量的根 
		printf("强联通分量 ");
		while(u!=Stack1[t1]){
			printf("%d ",Stack1[t1]);
			out[Stack1[t1]]=1; //出栈标记 
			--t1;
		} //u之后访问的点弹出栈1 
		printf("%d ",u); //u出栈 
		out[u]=1; //出栈标记 
		--t1;--t2; //分量的根u，弹出两栈 
		cout<<endl;
	}
}
int main(){
	int i,j,u,v,N=9,M=13; //点数、边数 
	int E[20][2]={{1,2},{1,7},{2,3},{2,5},{2,9},{3,4},{4,2},
	              {5,6},{5,7},{5,8},{6,5},{8,6},{9,1} };
	for(i=0;i<M;i++){
		u=E[i][0];v=E[i][1];
		A[u][++A[u][0]]=v; //邻接点 
	}  
	for(i=1;i<=N;i++) //图可能为森林 
	   if(Dfn[i]==0) //i没访问过 
	     DFS(i);  // 深搜 
	return 0;     
}
