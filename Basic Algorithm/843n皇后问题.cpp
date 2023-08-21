#include<bits/stdc++.h>
using namespace std;
const int N=10;

int n;
char g[N][N] ;
int row[N],col[N],dg[2*N],udg[2*N];
void dfs(int x,int y ,int s){
	if(s>n) return ;
	if(y==n) {
		y=0;x++;
	}
	if(x==n){
		if(s==n){
			for(int i=0;i<n;i++) cout<<g[i]<<endl;
			cout<<endl;
		}
		return ;
	}
	g[x][y]='.';
	dfs(x,y+1,s); //情况1不放皇后 
	if(!row[x]&&!col[y]&&!dg[x+y]&&!udg[x-y+n]) //情况2想放皇后 
	{
		row[x]=col[y]=dg[x+y]=udg[x-y+n]=true;
		g[x][y]='Q';
		dfs(x,y+1,s+1);
		g[x][y]='.';
		row[x]=col[y]=dg[x+y]=udg[x-y+n]=false;
	}
}
int main(){
	cin>>n;
	dfs(0,0,0);
	return 0;
}
