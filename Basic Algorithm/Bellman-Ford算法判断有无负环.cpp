bool Bellman(int s){
	fill(d,d_Maxv,INF);
	d[s]=0;
	for(int i=0;i<n-1;i++) //只要循环n-1次求离点s的最短路径 
	   bool update=false; ,
	    for(int u=0;u<n;u++){
	       if(d[u]=d_Maxv) continue ;//优化 
	       for(int j=0;j<Adj[u].size();j++){
	       	int v=Adj[u][j].v;
	       	int dis=Adj[u][j].dis;
	       	if(d[u]+dis<d[v])
	       	    d[v]=d[u]+dis;
	       	    update=true;//还可以松弛 
		   }
	    }
	    if(!update) break;//优化 无法松弛就提前结束   
    for(int u=0;u<n;u++){ //判断负环 
    	for(int j=0;j<Adj[u].size();j++){
    		int v=Adj[u][j].v;
    		int dis=Adj[u][j].dis;
    		if(d[u]+dis<d[v])
    		      return false; //有负环退出 
		}
	}	
	return true;	   
}
