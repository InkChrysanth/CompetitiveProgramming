/*
树的遍历dfs框架

*/
void dfs(x) {
   (1) //位置1对x当前做一个初始化 
   对于x的每个孩子y{
   	    (2) //在深搜之前对每一个儿子初始化 
   	    dfs(y); //‘；’代表y这棵子树已经完全访问完了 
   	    (3) //建立 x和y之间的联系，也可以做一些统计把y的信息统计到x上去 
   } 
    (4) //大有文章可做 
}//深度优先遍历的时间复杂度是O(N),N为树中的节点数 
const int MAXN=1e5_10;
int fa[MAXN],tot=0,head[MAXN];
struct node{
	int v,w,next;
}edge[MAXN];
void Addedge(int x,int y,int d){ //链式向前星建边
     edge[++tot].v=y;
	 edge[tot].w=d;
	 edge[tot].next=head[x] ;
	 head[x]=tot;
	 fa[y]=x;	
}
