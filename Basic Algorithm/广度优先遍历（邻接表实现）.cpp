/*
9 10
1 2
1 3
1 4
2 5
3 4
4 6
5 7
6 8
7 8
7 9
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=10006;
vector<int>G[maxn];
int n,m,d[maxn];
bool vis[maxn];
void bfs(int x){
	cout<<x<<" ";
	vis[x]=true;
	memset(d,0,sizeof(d)); //d记录顶点x的访问层数 
	queue<int>q;
	q.push(x);d[x]=1;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(int i=0;i<G[x].size();i++)
		{
			int y=G[x][i];
			if(!d[y]){//d[y] 初始为0当!d[y]成立代表y没被访问到 
				q.push(y);d[y]=d[x]+1;vis[y]=true;cout<<y<<" ";
			} 
		}
		}	
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]) {
			bfs(i);
			sum++; //记录联通块个数 
		}
	}
	cout<<endl;
	cout<<sum<<endl; //
	for(int i=1;i<=n;i++) cout<<i<<":"<<d[i]<<endl;
	return 0;
}
