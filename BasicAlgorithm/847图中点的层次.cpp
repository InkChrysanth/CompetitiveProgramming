#include<bits/stdc++.h>
using namespace std;
const int N=100010,M=2*N;
int e[M],ne[M],h[N],idx;
bool vis[M];
int d[M],q[N];
int n,m;
void add(int a,int b){
	e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
int bfs(){
	memset(d,-1,sizeof d);
	queue<int>q;
	d[1]=0;//这个千万不能忘 
	q.push(1);
	while(q.size()){
		int t=q.front();
		q.pop();
		for(int i=h[t];i!=-1;i=ne[i]){
			int j=e[i];
			if(d[j]==-1) {
				d[j]=d[t]+1;
				if(j==n) return d[n];
				q.push(j);
			}
		}
	}
	return d[n];
}
int main(){
	cin.tie(0);
	cin>>n>>m;
	int a,b;
	memset(h,-1,sizeof h);
	for(int i=0;i<m;i++){
		cin>>a>>b;
		add(a,b);
	}
	cout<<bfs()<<endl;
}

