void dijkstra(int src){
	memset(dist1,0x3f,sizeof(dist1));
	memset(dist2,0x3f,sizeof(dist2));
	priority_queue<pii,vector<pii>,greater<pii> >pq;
	pq.push({0,src});
	while(!pq.empty()){
		int d=pq.top().first,u=pq.top().second;pq.pop();
		if(d>dist2[u]) continue;
		for(int i=0;i<e[u].size();i++){
			int v=e[u][i].first,c=e[u][i].second,w=d+c;
			if(w<dist1[v]){ 
			     swap(dist1[v],w);
			     pq.push({sist1[v],v});}
			if(w<dist2[v]){
			     dist2[v] =w;
				 pq.push({dist2[v],v});	
				 }
			}
		}
	}
}
