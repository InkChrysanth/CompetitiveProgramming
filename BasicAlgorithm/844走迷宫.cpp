/*
5 5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
*/
#include<bits/stdc++.h>
using namespace std;
const int N=105,M=105;
typedef pair<int,int>pii;
pii q[N*N];
int n,m;
int  g[N][N]; //记录有没有被访问过 
int d[N][N];//记录到达点i，j的步数 
int bfs(){
	int tt=0,hh=0;
	q[0]={0,0};
	memset(d,-1,sizeof d); //-1代表没被访问过 
	d[0][0]=0;
	int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
	
	while(hh<=tt){
		pii t=q[hh++];
		for(int i=0;i<4;i++){
			int x=t.first+dx[i],y=t.second+dy[i];
			if(x>=0 &&x<n && y>=0&&y<m &&g[x][y]==0 &&d[x][y]==-1 )
			{
				d[x][y]=d[t.first][t.second]+1;
				q[++tt]={x,y};
			}
		}
		
	}
	return d[n-1][m-1];//第几步 
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)
	  for(int j=0;j<m;j++) 
	     cin>>g[i][j];
	cout<<bfs()<<endl;
	return 0;   
}

