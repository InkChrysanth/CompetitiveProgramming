/*
4 5
1 2
1 3
2 3
2 4
3 4
画递归树是分析递归算法和深搜的重要工具一定要熟练掌握 
&&(g[cur][i]>cur)
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
bool G[maxn][maxn];
int ans[maxn],length,n,m,start;
bool visit[maxn];
void print(int length){
	for(int i=1;i<length;i++){
		printf("%d--",ans[i]);
	}
	printf("%d\n",ans[length]);
}
void dfs(int last, int cur){  //
    visit[cur] = true;//visit表示点否访问过 
    ans[++length] = cur; //lenth记录经过的点的个数，记录找到的环中第几点的标记 
    for(int i=1;i<=n;i++){ //检索所有和点cur相连的边 
        if(G[cur][i]&&!visit[i] && i== start && i!=last){ //回到起点，构成哈密尔顿环 
            ans[++length] = i;
            print(length);
            length--; //退到上一点 
            //break;不需要break,因为要找所有的环 
        }
        if(G[cur][i]&&!visit[i] )  dfs(cur,i);//必须加条件g[cur][i]>cur保证后面的点的数字大于前面才不会重复?
    }//遍历与点i相关联的所有未访问过的顶点 
    length--;//回溯 
    visit[cur] = false;//回溯 
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		G[x][y]=1;
		G[y][x]=1;
	}
	for(start=1;start<=n;start++){
		length=0;
		dfs(0,start);
	}
	return 0;
}
