/*
6
1 3 5 7 9 11
 
（一）读入优化
快读scanf/printf(保险）
特别地，命令符号为字符时，可使用一些小技巧，避免误读：
char op=getchar();
while(op<'A' || op>'Z') op=getchar(); //吃掉不该用的字符 
(二）位运算优化（效果不明显）：：
1.struct Segment{ }tree[MAXN<<2];
2.mid的取值 int mid=(l+r)>>1;
3.左右子节点的编号
p<<1
p<<1|1; 
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
int n,a[MAXN];
struct SegmentTree{ //SegmentTree线段树的全称 
	int l,r; //区间左右端点 
	//附加信息，附加信息是线段树的重头戏 
	int sum; //区间和 
}tree[MAXN*4];
void bulid(int p,int l,int r){ //区间编号，区间左端点，区间右端点 
	tree[p].l=l;tree[p].r=r;//标识区间左右端点 
	if(l==r){tree[p].sum=a[l];return;}//叶节点存储实际数列元素 
	int mid=(l+r)/2;
	bulid(p*2,l,mid); //递归左半 
	bulid(p*2+1,mid+1,r); //递归右半 
	//回溯时更新区间附加信息 
	tree[p].sum=tree[p*2].sum+tree[p*2+1].sum ;//区间和更新pushup 
}
void add1(int p,int d){ //更新以p为根的整棵子树节点信息 
	if(tree[p].l==tree[p].r) {
		tree[p].sum+=d;return;
	}
	add(p*2,d);
	add(p*2+1,d);
	tree[p].sum=tree[p*2].sum+tree[p*2+1].sum;
}
void add(int p,int d){ 
	tree[p].sum+=d*(tree[p].r-tree[p].l+1); //进入时完成 
	if(tree[p].l==tree[p].r) return;
	add(p*2,d);
	add(p*2+1,d);
}
void update(int p,int l,int r,int d){ //线段树区间修改 
	if(l<=tree[p].l && tree[p].r<=r ){
		add(p,d);
		return ;
	}
	int mid=(tree[p].l+tree[p].r)/2;
	if(r<=mid) update(p*2,l,r,d);
	else if(l>mid) update(p*2+1,l,r,d);
	else update(p*2,l,r,d),update(p*2+1,l,r,d);
	tree[p].sum=tree[p*2].sum+tree[p*2+1].sum; 
}
int query(int p,int l,int r){ //区间查询写法1 
	if(l<=tree[p].l && tree[p].r<=r) return tree[p].sum; //完全覆盖 
	int mid=(tree[p].l+tree[p].r)/2;
	int val =0;
	if(l<=mid) val+=query(2*p,l,r); //左 
	if(r>mid) val+=query(p*2+1,l,r); //右 
	return val;
}
int query1(int p,int l,int r){ //区间查询写法2 
	if(tree[p].l==tree[p].r) return tree[p].sum;
	int mid=(tree[p].l+tree[p].r)/2;
	if(r<=mid) return query1(p*2,l,r); //完全在左 
	else if(l>mid) return query1(p*2+1,l,r);//完全在右 
	else return query1(p*2,l,r)+query1(p*2+1,l,r);//横跨中点 
}
void print(int p){
	cout<<p<<" "<<tree[p].l<<" "<<tree[p].r<<" "<<tree[p].sum<<endl;
	if(tree[p].l==tree[p].r) return ;
	print(p*2);
	print(p*2+1);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	bulid(1,1,n);
	update(1,2,5,1); //改 
	print(1);
//	cout<<query1(1,2,5)<<endl; //查 
	return 0;
}
