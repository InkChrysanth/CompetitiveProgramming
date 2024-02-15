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
const int maxn=10e5+5;

vector<int>G[maxn];
int n,m;
bool vis[maxn];
void dfs(int x){
	cout<<x<<" ";
	vis[x]=true;
	int k=G[x].size();
	for(int i=0;i<k;i++){
		int y=G[x][i];
		if(!vis[y]) dfs(y);
	}
//	cout<<x<<" ";	
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
	}
	int sum=0; //sum记录联通块个数 
	for(int i=1;i<=n;i++){
		if(!vis[i]) {
			dfs(i);
			sum++;
		}
	}
	cout<<sum<<endl;
	return 0;
}
