/*
850.Dijkstra求最短路II 
3 3 
1 2 2
2 3 1
1 3 4 
*/
#include<bits/stdc++.h>
using namespace std;
const int N=510;
int n,m;
int e[N],w[N],h[N],ne[N],idx;
int dist[N];
bool st[N];
typedef pair<int,int>PII;
void add(int a,int b,int c){
	e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
int dijkstra(){
	memset(dist,0x3f,sizeof dist);
	dist[1]=0;
	priority_queue<PII,vector<PII>,greater<PII> >heap; 
	heap.push({0,1}) ;//第一条边，距离为0  
	while(heap.size()){
		PII t=heap.top(); //取队头 
		heap.pop(); //弹出 
		int ver=t.second,distance=t.first; //ver为点的编号 
		for(int i=h[ver];i!=-1;i=ne[i]){ //i为以点ver为起点的边的编号 
			int j=e[i]; //j为边i的出点的编号 
			if(dist[j]>distance+w[i])
			{
				dist[j]=distance+w[i];
				heap.push({dist[j],j});
			}
		}
	}
	if(dist[n]==0x3f3f3f3f) return -1;
	return dist[n];
}
int main(){
	cin>>n>>m;
	memset(h,-1,sizeof h);
	int a,b,c;
	while(m--){
		cin>>a>>b>>c;
		add(a,b,c);
	}
	int t=dijkstra();
	cout<<t<<endl;
	return 0;
}
