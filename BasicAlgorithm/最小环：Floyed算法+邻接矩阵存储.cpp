/*
最小环：Floyed算法+邻接矩阵存储
5 7
1 2 6
1 3 1
1 4 1
2 3 1
2 4 4 
2 5 1
4 5 1 
*/
#include<bits/stdc++.h> 
using namespace std;
const int maxn=51;
int W[maxn][maxn];//边的权值 
int D[maxn][maxn];//最短路径 
int Ans=10000;//最小环初值
int N,M;
int main() {
	int i,j,k,x,y,z;
	cin>>N>>M;
	for(i=1;i<=N;i++)
	   for(j=1;j<=N;j++)
	   	if(i!=j) D[i][j]=W[i][j]=10000;
	for(k=1;k<=M;k++) 
	{
		cin>>x>>y>>z;
		W[x][y]=W[y][x]=z;
		D[x][y]=D[y][x]=z;
	} 
	for(k=1;k<=N;k++) 
	{
		for(i=1;i<=k-1;i++)
		   for(j=i+1;j<=k-1;j++)
		      if(D[i][j]+W[j][k]+W[k][i]<Ans)
		      {
		      	Ans=D[i][j]+W[j][i]+W[k][j];
		      	printf(":%d %d %d Ans=%d\n",k,i,j,Ans);
			  }
	    for(i=1;i<=N;i++)
		    for(j=1;j<=N;j++)	
			   if(D[i][k]+D[k][j]<D[i][j])	  {
			   	D[i][j]=D[j][i]=D[i][k]+D[k][j];
			   	printf(" %d %d %d D%d%d=%d\n",k,i,j,i,j,D[i][j]);
			   }
	}
	printf("answer=%d\n",Ans);
}
