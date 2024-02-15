/*
关键路径：算法+邻接点+邻接矩阵+栈 
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=51;
int A[maxn][maxn],W[maxn][maxn];//邻接点，邻接矩阵 
int cd[maxn],rd[maxn];//出度、入度 
int sd,zd;//始点、终点 
int Stack[maxn],s;//零入度顶点栈，指针 
int topo[maxn],t;//拓扑序列，计数器 
int ve[maxn],vl[maxn];//事件的最早，最晚时间 
int ae[maxn],al[maxn];//活动的最早，最晚时间 
int B[maxn][maxn];//关键路径顶点的邻接点 
int path[maxn],cd2[maxn];//关键路径顶点，出度 
int N,M;//顶点数，边数 
void Print(int,int);//输出关键路径 

void Init() //初始化 
{
	int i,j,k,l;//
	N=8,M=10;
	int E[15][3]={{1,2,4},{1,3,6},{2,4,1},{3,4,1},{4,5,9},
	              {4,6,6},{4,7,7} ,{5,8,3},{6,8,7},{7,8,4}};
	for(i=1;i<=M;i++){
		j=E[i-1][0];k=E[i-1][1];l=E[i-1][2];
		cd[j]++;//存储点j的出度 
		A[j][cd[j]]=k;//存储邻接点 
		rd[k]++;//存储点k的入度 
		W[j][k]=l;//邻接矩阵存储边权 
	}
	for(i=1;i<=N;i++){
		if(rd[i]==0) sd=i; //始点 
		if(cd[i]==0) zd=i; //终点 
	}		
}
bool TopoOrder(){//拓扑排序 
	int i,j,k;
	int num=0;//计数器 
	Stack[++s]=sd;//始点入栈 
	while(s){
		i=Stack[s--];//出栈 
		num++;//计数 
		topo[++t]=i;//记录拓扑序列 
		for(j=1;j<=cd[i];j++)
		{
			k=A[i][j];//取出邻接点 
			rd[k]--;//入度减1 
			if(rd[k]==0) Stack[++s]=k;//如果入度变成0后继点入栈 
			if(ve[i]+W[i][k]>ve[k])//更新事件的最早发生事件 
			   ve[k]=ve[i]+W[i][k];
		}
	}
	if(num==N) return 1;//无回路 
	else return 0;	//有回路 
}
void CritlPath() //关键路径 
{
	int i,j,k,l;
	if(TopoOrder())//无回路 
	{ //初始化事件的最迟发生事件 
		for(i=1;i<=N;i++) vl[i]=ve[N];//拓扑逆序求各顶点的vl值 
		for(l=N;l>=1;l--)
		{
			k=topo[l];
			for(j=cd[k];j>=1;j--)
			{
				i=A[k][j];//取出邻接点 
				if(vl[i]-W[k][i]<vl[k])
				   vl[k]=vl[i]-W[k][i];
			}
		}
		j=0;//求活动ae,al和关键活动 
		for(i=1;i<=N;i++)
		    for(l=1;l<=cd[i];l++){
		    	k=A[i][l];//取出邻接点 
		    	ae[++j]=ve[i];al[j]=vl[k]-W[i][k];
		    	if(ae[j]==al[j]){//关键活动 
		    		B[i][++cd2[i]]=k;//存储邻接点 
				}
			}
	    printf("事件ve:")	;//跟踪事件 
		for(i=1;i<=N;i++) printf("%2d ",ve[i])	;
		printf("\n事件v1:")	;
		for(i=1;i<=N;i++) printf("%2d ",vl[i])	;
		printf("\n活动ae:")	;
		for(i=1;i<=N;i++) printf("%2d ",ae[i])	;
		printf("\n活动al:")	;
		for(i=1;i<=N;i++) printf("%2d ",al[i])	;
		printf("\n\n关键路径 ：");
		Print(sd,1);//输出关键路径		 
	}
}
void Print(int v,int deep)//输出关键路径 
{
	path[deep]=v;//存储关键路径顶点 
	if(v==zd){//到达终点，输出路径 
		for(int j=1;j<=deep;j++)
		    printf("%d ",path[j]);
		printf("\n")   ; 
	}
	else{
		for(int j=1;j<=cd2[v];j++)
		   Print(B[v][j],deep+1);//递归 
	}
}
int main(){
	Init();//初始化 
	CritlPath();//关键路径 
}

