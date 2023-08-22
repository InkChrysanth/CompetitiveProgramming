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
using namespace std ;
#define MAXN 1005
using namespace std;
int n, m, x, lenth, g[MAXN][MAXN], num[MAXN], ans[MAXN];
bool visit[MAXN];
void print(){
    for(int i=1;i<lenth;i++) printf("%d ",ans[i]);
    // printf("\n");
    printf("%d\n",ans[lenth]);
}
void dfs(int last, int cur){  //图用模拟邻接表存储，从cur点开始查询，last表示上次访问的点 
    visit[cur] = true;//visit表示点否访问过 
    ans[++lenth] = cur; //lenth记录经过的点的个数，记录找到的环中第几点的标记 
    for(int i=1;i<=num[cur];i++){ //检索所有和点cur相连的边 
        if(g[cur][i] == x && g[cur][i]!=last){ //回到起点，构成哈密尔顿环 
            ans[++lenth] = g[cur][i];
            print();
            lenth--; //退到上一点 
            //break;不需要break,因为要找所有的环 
        }
        if(!visit[g[cur][i]] &&(g[cur][i]>cur))  dfs(cur,g[cur][i]);//必须加条件g[cur][i]>cur保证后面的点的数字大于前面才不会重复?
    }//遍历与点i相关联的所有未访问过的顶点 
    lenth--;//回溯 
    visit[cur] = false;//回溯 
}
 
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){ //用模拟邻接表存图 
        int u, v;
        scanf("%d%d",&u,&v);
        g[u][++num[u]] = v; g[v][++num[v]] = u; //理解为与u点相连的第num[u]条边的另一个点为v，其中num[u]记录与u相连的边的标号 
    }
    for(x=1;x<=n;x++) //每个点都作为起点尝试访问，因为不是从任何一点开始都能找过整个图 
         lenth = 0,dfs(0,x);//val表示从哪个点开始搜环。 
    return 0;
}

