#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,K=22;
int fa[N][K];
int h[N],e[N*2],ne[N*2],idx;
bool st[N];
int d[N],d2[N];
void add(int a,int b){
	ne[idx]=h[a],e[idx]=b,h[a]=idx++;
}
int n,q;
int r1,r2;
void dfs1(int u,int fat,int de){
	
	d[u]=de;
	for(int i=h[u];~i;i=ne[i]){
		int j=e[i];
		if(j==fat)continue;
		fa[j][0]=u;
		for(int i=1;i<K;i++)fa[j][i]=fa[fa[j][i-1]][i-1];
		dfs1(j,u,de+1);
	}
	
}
void dfs2(int u,int fat,int de){
	d2[u]=de;
	for(int i=h[u];~i;i=ne[i]){
		int j=e[i];
		if(j==fat)continue;
		dfs2(j,u,de+1);
	}
}
int lca(int a,int b){
	if(d[a]<d[b])swap(a,b);
	for(int i=K-1;~i;i--){
		if(d[fa[a][i]]>=d[b])a=fa[a][i];
	}
	if(a==b)return a;
	for(int i=K-1;~i;i--){
		if(fa[a][i]!=fa[b][i])a=fa[a][i],b=fa[b][i];
	}
	return fa[a][0];
}
int get(int x,int y){
	int f=lca(y,x);
	return d[x]+d[y]-2*d[f];
}
int main(){
	d[0]=-1;
	memset(h,-1,sizeof h);
	scanf("%d%d",&n,&q);
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b),add(b,a);
	}
	dfs1(1,0,1);
	int maxd=0;
	for(int i=1;i<=n;i++){
		if(d[i]>maxd)maxd=d[i],r1=i;
	}
	dfs2(r1,0,1);
	maxd=0;
	for(int i=1;i<=n;i++){
		if(d2[i]>maxd)maxd=d2[i],r2=i;
	}
	while(q--){
		char s[5];
		scanf("%s",s);
		if(s[0]=='G'){
			printf("%d\n",get(r1,r2));
		}else{
			int x;
			scanf("%d",&x);
			if(st[x]==0){
				st[x]=1;
				if(x==r1||x==r2){
					if(x==r1)swap(r1,r2);
					memset(d2,0,sizeof d2);
					maxd=0;
					dfs2(r1,0,1);
					for(int i=1;i<=n;i++){
						if(d2[i]>maxd&&(st[i]==0))maxd=d2[i],r2=i;
					}
				} 
			}else{
				st[x]=0;
				if(get(x,r2)>=get(x,r1)&&get(x,r2)>get(r1,r2)){
					r1=x;
				}else if(get(x,r1)>get(r1,r2)){
					r2=x;
				}
			}
		}
	}
	return 0;
}
