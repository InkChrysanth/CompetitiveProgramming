/*
5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 0 1 0
1 1 1 1 1
3 1
4 5 
if(x<0||x>n||y<0||y>n||vist[x][y]||jz[x][y]||step>=ans)return;
*/ 
#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int fx[5][2]={{1,0},{-1,0},{0,-1},{0,1}};
bool jz[maxn][maxn];
int path[maxn][2];
int n,ans=100,step,desx,desy,soux,souy;
bool vist[maxn][maxn];
void print(int step){
	for(int i=1;i<=step;i++) cout<<path[i][0]<<"."<<path[i][1]<<" ";
	cout<<desx<<"."<<desy<<endl;
}
void dfs(int x,int y,int step){
	if(x<0||x>n||y<0||y>n||vist[x][y]||jz[x][y]||step>=ans)return;
	//关键一步剪枝，只输出最短路径 
	path[step][0]=x;
	path[step][1]=y;
	for(int i=0;i<4;i++){
	   int xx=x+fx[i][0];
	   int yy=y+fx[i][1];
	   vist[x][y]=true;
	   if(xx==desx&&yy==desy)	 {
	   	ans=step;
//	   	print(step);
	   }
	   else{
	   	if(!jz[xx][yy]&& !vist[xx][yy]) {
	   		dfs(xx,yy,step+1);
	   		vist[xx][yy]=false;
		   }
	   }
	}
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
	   for(int j=1;j<=n;j++) 
	      cin>>jz[i][j];
	cin>>soux>>souy>>desx>>desy;
	dfs(soux,souy,1)  ;
	cout<<ans<<endl;
	print(ans);
	return 0;    
}
