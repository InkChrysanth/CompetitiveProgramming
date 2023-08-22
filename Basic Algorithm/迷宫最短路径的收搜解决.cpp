/*
5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 0 1 0
1 1 1 1 1
3 1
4 5
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int fx[5][2]={{1,0},{-1,0},{0,-1},{0,1}};
bool jz[maxn][maxn];
int path[maxn][2];
int n,desx,desy,soux,souy;
bool vist[maxn][maxn];
int ans=100;
 
 void dfs(int i,int j,int cnt)
 {  //实现最短路径的关键一步是cnt>=ans条件剪枝 
     if(i<0||i>n||j<0||j>n||vist[i][j]||jz[i][j]||cnt>=ans)return;
     if(i==desx&&j==desy)
     {
         ans=cnt;
         return;
     } 
     vist[i][j]=1;       // 这个已经遍历了x` 
     dfs(i,j-1,cnt+1);
     dfs(i-1,j,cnt+1);
     dfs(i,j+1,cnt+1);
     dfs(i+1,j,cnt+1);   
     vist[i][j]=0;
 }
 
 int main()
 {
    cin>>n;
	for(int i=1;i<=n;i++)
	   for(int j=1;j<=n;j++) 
	      cin>>jz[i][j];
	cin>>soux>>souy>>desx>>desy;
	dfs(soux,souy,0)  ;
	cout<<ans<<endl;
	return 0; 
 }
