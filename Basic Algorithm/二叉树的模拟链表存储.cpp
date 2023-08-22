#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
struct node{ //模拟链表 
	int x,l,r;
}b[maxn];
bool pd[maxn];
int T,Root,num=0;
int find(int z){
	if(b[z].l) find(b[z].l);
	num++; //中序经过一个结点+1 
	if(b[z].x==T) { //找到 
		cout<<num<<endl;
		return 0;
	}
	if(b[z].r) find(b[z].r) ;
}
int main()
{
	int i,n;
	cin>>n>>T;
	for(i=1;i<=n;i++){
		cin>>b[i].x>>b[i].l>>b[i].r;
		pd[b[i].l]=pd[b[i].r]=1;		
	}
	for(i=1;i<=n;i++){ //寻找树根 
		if(!pd[i]) {
			Root=i;break;
		}
	}
	find(Root); //中序查找 
	return 0;
}
