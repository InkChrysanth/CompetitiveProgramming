#include<bits/stdc++.h>
using namespace std;
const int N=20; //因为有对角线，所以数组要开大一倍！ 
int n;
char g[N][N];
bool col[N],dg[N],udg[N];
void dfs(int u){  
	if(u==n) { //U代表放到第几行 
		for(int i=0;i<n;i++) puts(g[i]);
		puts(" ");
		return ;
	}
	for(int i=0;i<n;i++){ //在u行的时候第几列可以放 
		if(!col[i] && !dg[u+i] && !udg[u-i+n]){ //对角线的求法一定要掌握 
			col[i]=dg[u+i]=udg[u-i+n]=true;
			g[u][i]='G';
			dfs(u+1);
			col[i]=dg[u+i]=udg[u-i+n]=false; //回溯 
			g[u][i]='.';
		}
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
	   for(int j=0;j<n;j++)
	       g[i][j]='.';
	dfs(0);
	return 0;
}
