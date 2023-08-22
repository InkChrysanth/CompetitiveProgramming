void make_set(int x){
	p[x]=x;
	rank[x]=0; //rank[]存树的高度 
}
int find_set(int x){
	if(x!=p[x])
	   p[x]=find_set(p[x]);
	return p[x] ;  
}
void union1(int x,int y){
	x=find_set(x);
	y=find_set(y);
	if(x!=y){
		if(rank[x]>rank[y])
		     p[y]=x; //y挂在x上 
		else {
			 p[x]=y;
			 if(rank[x]==rank[y]) //假如挂在y 树上且，原来树等高则树高+1 
			    rank[y]=rank[y]+1;
		}		        
	}
}
