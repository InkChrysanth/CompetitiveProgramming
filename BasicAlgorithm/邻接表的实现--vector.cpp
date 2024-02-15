/*
4 6 1
1 2 2
2 3 2
2 4 1
1 3 5
3 4 3
1 4 4 
输出
2 2
3 5
4 4 
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN=10e5+5;
int n,m,s;
struct Node{ //定义结构体，存放终点和权值 
	int v,w; //终点，权值 
	Node(int _v,int _w) {v=_v; w=_w;	}
	//定义构造函数，方便加边处理 
};
vector<Node>G[MAXN];
int main(){
	cin>>n>>m>>s;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].push_back(Node(v,w)); //带权有向图加边 
	}
//	G[u].push_back(Node(v,w)); //带权无向图加边 
//	G[v].push_back(Node(u,w));
    int k=G[s].size(); //提高效率 
    for(int i=0;i<k;i++)
         cout<<G[s][i].v<<" "<<G[s][i].w<<endl;
	return 0;
}
