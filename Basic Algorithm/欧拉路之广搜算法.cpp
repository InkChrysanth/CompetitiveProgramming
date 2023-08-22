/*
4 5
1 2
1 3
2 3
2 4
3 4
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
int G[maxn][maxn],path[maxn],pre[maxn],du[maxn];
int head,tail,N,M;
void print(int x);
bool flag=false;
void bfs(int i)
{
	head=0,tail=1;
	path[tail]=i;
	pre[tail]=head;
	int j;
	while(head!=tail){
		head++;
		for(j=1;j<=N;j++)
		{
			if(G[i][j])
			{
				tail++;
				path[tail]=j;
				pre[tail]=head;
				G[i][j]=0;G[j][i]=0; //删除这条边避免再走 
				if(head==M) {
					print(tail);flag=true;
				}
				break; //扩展一个点，立即跳出for循环 
			}
		}
		i=j; //更换起点 
	}
	if(flag==false) cout<<"No"<<endl;
}
void print(int i){
	if(pre[i]!=0) print(pre[i]);
	printf("%d  ",path[i]);
}
int main(){
	cin>>N>>M;
	int x,y;
	for(int i=1;i<=M;i++){
		cin>>x>>y;
		G[x][y]=G[y][x]=1;
		du[x]++;du[y]++;		
	}
	int start=1;
	for(int i=1;i<=N;i++){
		if(du[i]%2==1) {
			start=i;break;
		}
	}
	bfs(start);
	return 0;
}
