#include<bits/stdc++.h>
using namespace std;
const int N=100010;int n,m;
int h[N],size;
void down(int u){
	int t=u;
	if(u*2<=size && h[t]>h[u*2]) t=u*2;
	if(u*2+1<=size && h[t]>h[u*2+1]) t=u*2+1;
	if(t!=u){
		swap(h[u],h[t]);
		down(t);
	}
}
void up(int x){
    if(x==1) return ;
    if(h[x]<h[x/2]) {
        swap(h[x],h[x/2]);
        up(x/2);
    }
    return ;
}
void up1 (int u){
	while(u/2&& h[u]<h[u/2]){
		swap(h[u],h[u/2]);
		u/=2;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&h[i]);
	size=n;
	for(int i=n/2;i;i--) down(i); //思考为何是n/2 从倒数第二层开始 
	while(m--){
		printf("%d ",h[1]);
		h[1]=h[size];
		size--;
		down(1);
	}
	return 0;
}
