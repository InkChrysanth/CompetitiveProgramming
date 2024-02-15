#include<bits/stdc++.h>
using namespace std;
const int N=100005,M=2*N;
int e[M],ne[M],h[N],idx;
int maxx=N,n;
bool vis[N];
void add(int a,int b){
	e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
int dfs(int u){
	vis[u]=true;
	int sum=0,size=0;
	for(int i=h[u];i!=-1;i=ne[i]) {
		int j=e[i];
		if(vis[j]) continue;
		int s=dfs(j); 
//		vis[j]=false 回溯时不需要这句话 
		size=max(size,s);//打擂台求出以u为根结点的所有子树中的最大值
		sum+=s; 
	}
	size=max(size,n-sum-1) ;//n-sum-1是因为除了要减去各个子树的和还要把跟结点也要减去 
	maxx=min(maxx,size);
	return sum+1; //返回以u为根结点的子树大小 
}
int main(){
	cin.tie(0);
	int a,b;
	cin>>n;
	memset(h,-1,sizeof h);
	for(int i=0;i<n-1;i++){
		cin>>a>>b;
		add(a,b),add(b,a);
	}
	dfs(4); //参数为点的编号 所以不能为0 
	cout<<maxx<<endl;
	return 0;
}
