#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<cmath>
#define cmin(i,j) (i)=min((i),(j))
#define cmax(i,j) (i)=max((i),(j))
using namespace std;
inline int read(){
	int w=0,x=0;char c=getchar();
	while(!isdigit(c))w|=c=='-',c=getchar();
	while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return w?-x:x;
}
namespace star
{
	const int maxn=2e6+10,INF=0x3f3f3f3f;
	int n,m,checkn,checkm,rt,tot,qx,qy,g[maxn],t;
	struct node{
		int x,y,ls,rs,l[2],r[2],siz,d;
	}e[maxn];
	inline bool cmpx(int a,int b){return e[a].x<e[b].x;}
	inline bool cmpy(int a,int b){return e[a].y<e[b].y;}
	inline void maintain(int x){
		e[x].siz=e[e[x].ls].siz+e[e[x].rs].siz+1;
		e[x].l[0]=e[x].r[0]=e[x].x;
		e[x].l[1]=e[x].r[1]=e[x].y;
		if(e[x].ls)
			cmin(e[x].l[0],e[e[x].ls].l[0]),cmax(e[x].r[0],e[e[x].ls].r[0]),
			cmin(e[x].l[1],e[e[x].ls].l[1]),cmax(e[x].r[1],e[e[x].ls].r[1]);
		if(e[x].rs)
			cmin(e[x].l[0],e[e[x].rs].l[0]),cmax(e[x].r[0],e[e[x].rs].r[0]),
			cmin(e[x].l[1],e[e[x].rs].l[1]),cmax(e[x].r[1],e[e[x].rs].r[1]);
	}
	int build(int l,int r){
		if(l>r)return 0;
		int mid=l+r>>1;
		double av[2],va[2];
		av[0]=av[1]=va[0]=va[1]=0;
		for(int i=l;i<=r;i++)av[0]+=e[g[i]].x,av[1]+=e[g[i]].y;
		av[0]/=(r-l+1),av[1]/=(r-l+1);
		for(int i=l;i<=r;i++)
			va[0]+=(av[0]-e[g[i]].x)*(av[0]-e[g[i]].x),
			va[1]+=(av[1]-e[g[i]].y)*(av[1]-e[g[i]].y);
		if(va[0]>va[1])nth_element(g+l,g+mid,g+r+1,cmpx),e[g[mid]].d=1;
		else nth_element(g+l,g+mid,g+r+1,cmpy),e[g[mid]].d=2;
		e[g[mid]].ls=build(l,mid-1);
		e[g[mid]].rs=build(mid+1,r);
		maintain(g[mid]);
		return g[mid];
	}
	void getson(int x){
		if(!x)return;
		getson(e[x].ls);
		g[++t]=x;
		getson(e[x].rs);
	}
	inline void rebuild(int &x){
		t=0;
		getson(x);
		x=build(1,t);
	}
	inline bool bad(int x){return 0.9*e[x].siz<=(double)max(e[e[x].ls].siz,e[e[x].rs].siz);}
	void insert(int &x,int k){
		if(!x){
			x=k,maintain(k);return;
		}
		if(e[x].d==1){
			if(e[k].x<=e[x].x)insert(e[x].ls,k);
			else insert(e[x].rs,k);
		}else{
			if(e[k].y<=e[x].y)insert(e[x].ls,k);
			else insert(e[x].rs,k);
		}
		maintain(x);
		if(bad(x)) rebuild(x);
	}
	inline int getdis(int x){return max(0,qx-e[x].r[0])+max(0,e[x].l[0]-qx)+max(0,qy-e[x].r[1])+max(0,e[x].l[1]-qy);}
	inline int dist(int x){return abs(qx-e[x].x)+abs(qy-e[x].y);}
	int ans;
	void query(int x){
		cmin(ans,dist(x));
		int dl=INF,dr=INF;
		if(e[x].ls)dl=getdis(e[x].ls);
		if(e[x].rs)dr=getdis(e[x].rs);
		if(dl<dr){
			if(dl<ans)query(e[x].ls);
			if(dr<ans)query(e[x].rs);
		}else{
			if(dr<ans)query(e[x].rs);
			if(dl<ans)query(e[x].ls);
		}
	}
	inline void work(){
		n=read(),m=read();
		checkn=n, checkm=m;
		while(n--){
			e[++tot].x=read(),e[tot].y=read();
			g[tot]=tot;
		}
		rt=build(1,tot);
		while(m--){
			if(read()==1){
				e[++tot].x=read(),e[tot].y=read();
				insert(rt,tot);
			}else{
				qx=read(),qy=read();ans=INF;query(rt);
				printf("%d\n",ans);
			}
		}
	}
}
signed main(){
	star::work();
	return 0;
}
