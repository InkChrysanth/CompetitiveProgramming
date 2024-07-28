#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
vector <int> G[MAXN];
int dep[MAXN],fa[MAXN],siz[MAXN],hs[MAXN],ans=0;
void dfs0(int u,int fz) {
	vector <int> E;
	fa[u]=fz,siz[u]=1;
	for(int v:G[u]) if(v^fz) {
		E.push_back(v);
		dep[v]=dep[u]+1,dfs0(v,u),siz[u]+=siz[v];
	}
	G[u].swap(E);
}
void dfs1(int u,int lim) {
	++ans;
	for(int v:G[u]) if(v!=fa[u]&&v!=hs[u]&&siz[u]>lim) {
		siz[u]-=siz[v],dfs1(v,lim);
	}
}
signed main() {
//	freopen("30.in","r",stdin); 
	int n;
	scanf("%d",&n);
	for(int i=1,u,v;i<n;++i) {
		scanf("%d%d",&u,&v);
		G[u].push_back(v),G[v].push_back(u);
	}
	dfs0(1,0);
//	cerr<<dep[n]+1<<endl;
	if((n-dep[n])&1) return puts("-1"),0;
	for(int i=1;i<=n;++i) {
		sort(G[i].begin(),G[i].end(),[&](int x,int y){ return siz[x]>siz[y]; });
	}
	for(int i=n,s=0;i;i=fa[i]) {
		hs[fa[i]]=i,siz[i]-=s,s+=siz[i];
		dfs1(i,(n-dep[n])/2+dep[i]);
	}
	printf("%d\n",ans);
	return 0;
}
