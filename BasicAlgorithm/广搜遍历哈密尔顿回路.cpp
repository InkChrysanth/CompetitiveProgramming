/*
样例 
4 5
1 2
1 3
2 3
2 4
3 4
1 2 3 1
2 3 4 2
画递归树是分析递归算法和深搜的重要工具一定要熟练掌握 
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int Q[maxn],pre[maxn];
bool G[maxn][maxn];
int N,M,head,tail;
bool vist[maxn];
void print(int x){
	if(pre[x]!=0) print(pre[x]);
	cout<<Q[x]<<" ";
}
void bfs(int start){
	head=0,tail=1;
	Q[1]=start;
	pre[1]=0;
//	vist[start]=1;
	while(head!=tail)
	{
		head++;
		int i=Q[head];
		for(int j=1;j<=N;j++){
			if(G[i][j]&&i!=j ) 
			{
				G[i][j]=G[j][i]=0;
				tail++;
				Q[tail]=j;
                if(j==Q[1]&&head==M-1) {
					print(i);
				}
				else pre[j]=i;
				break;
			}
		}
	}
}
int main() {
	cin>>N>>M;
	int x,y;
	for(int i=1;i<=M;i++){
		cin>>x>>y;
		G[x][y]=G[y][x]=1;
	}
	bfs(1);
	
	return 0;
}
