//LCA公共祖先 
int LCA(int x,int y){ //暴力求LCA 
	if(depth[x]<depth[y]) swap(x,y);  
	while(depth[x]!=depth[y]) x=fa[x]; //逐层往上走到达同层 
	while(x!=y) x=fa[x],y=fa[y]; //一起往上跳
	return x;//LCA
}
//优化：用倍增加速这个过程 
/*
预处理
令f[x][i](i=0...logn)为从x向根移动2^i步到达的位置（如f[x][0]就是x的父亲2^0=1）。 
求x,y两点的LCA:
首先将x,y提到同一深度：不妨设x当前比y深，从大到小枚举步长2^i,
若y不比f[x][i]深则更新x.这里i=0...logn,复杂度O(logn) 
若此时x==y则返回结果(y)
从大到小枚举步长2^i,若f[x][i]!=f[y][i]则更新x,y。这里i=0...logn因此复杂度O(logn)
最后答案即为当前x/y结点的父节点，即f[x][0] 
*/
//预处理倍增数组 
void dfs(int u,int father){ //对应深搜预处理f数组
     dep[u]=dep[father]+1; //深度+1； 
     for(int i=1;(1<<i)<=dep[u];i++)   
          f[u][i]=f[f[u][i-1]][i-1];//2^i=2^(i-1)+2^(i-1)=2*2^(i-1)
    //因u移动2^i次就相当于从u移动2^(i-1)次后再移动2^(i-1)次
	for(int i=head[u];i;i=edge[i].next) {
		int v=edge[i].to;
		if(v==father) continue ; //往下走 
		f[v][0]=u;  //u是v的父亲 
		dfs(v,u);
	}     	
}
//CODE模板
const int logN=18;
int LCA(int x,int y){ //寻找公共祖先 
	if(depth[x]<depth[y]) swap(x,y);
	/*
	for(int i=logN;i>=0;--i) //将x 跳到和y同一深度 
	   if(depth[f[x][i]]>=depth[y])
	       x=f[x][i];
	*/
	int c=depth[x]-depth[y];
	for(int i=0;i<=14;i++){
		if(c &(1<<i)) x=up[y][i];
	} //跳同层 位运算优化
	if(x==y) return x;
	for(int i=logN;i>=0;--i) //一起向上跳
	    if(f[x][i]!=f[y][i]) 
	       x=f[x][i],y=f[y][i];
	return f[x][0] ;//两个点均在其LCA的下方，再往上跳一次      
} 
