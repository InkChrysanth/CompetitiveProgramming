void dijkstra(int src){
	memset(dist,0x3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	memset(cnt,0,sizeof(cnt));
	priority_queue<pii,vector<pii>,greater<pii> >pq;
	pq.push({0,src});
	while(!pq.empty()){
		int u=pq.top().second;pq.pop();
		if(vis[u]) continue;vis[u]=1;
		for(int i=0;i<e[u].size();i++){
			int v=e[u][i].first,c=e[u][i].second;
			if(dist[v]==dist[u]+c) cnt[v]+=cnt[u];
			if(!vis[v] && dist[v]>dist[u]+c){
				dist[v]=dist[u]+c;
				cnt[v]=cnt[u];
				pq.push({dist[v],v});
			}
		}
	}
}
