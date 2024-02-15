/*
6
1 3 5 7 9 11
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
int n,a[MAXN];
struct SegmentTree{
	int l,r;
	int sum;
	int add;//延迟标记 
}tree[MAXN*4];
void build(int p,int l,int r){
	tree[p].l=l;tree[p].r=r;
	if(l==r) {
		tree[p].sum=a[l];return ;
	}
	int mid=(l+r)/2;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	tree[p].sum=tree[p*2].sum+tree[p*2+1].sum;
}
void pushdown(int p){ //下传延迟标记 
	if(tree[p].add){ //节点p有延迟标记
	    //根据延迟标记更新左右子节点信息 
		tree[p*2].sum+=tree[p].add*(tree[p*2].r-tree[p*2].l+1);
		tree[p*2+1].sum+=tree[p].add*(tree[p*2+1].r-tree[p*2+1].l+1);
		//为p的两个子结点增加标记 
		tree[p*2].add+=tree[p].add;
		tree[p*2+1].add+=tree[p].add;
		//清除p的延迟标记 
		tree[p].add=0;
	}
}
void update(int p,int l,int r,int d){
	if(tree[p].l<=l && tree[p].r<=r) {
		tree[p].sum+=d*(tree[p].r-tree[p].l+1) ;
		tree[p].add+=d;//给划分成的O(logN)个区间节点打上延迟标记
		return; 
	}
	pushdown(p);//下传延迟标记 
int mid=(tree[p].l+tree[p].r)/2;
	if(r<=mid) update(p*2,l,r,d);
	else if(l>mid) update(p*2+1,l,r,d);
	else update(p*2,l,r,d),update(p*2+1,l,r,d);
	tree[p].sum=tree[p*2].sum+tree[p*2+1].sum; 
}

int query(int p,int l,int r){
	if(l<=tree[p].l && tree[p].r<=r) return tree[p].sum;
	pushdown(p);
	int mid=(tree[p].l+tree[p].r)/2;
	if(r<=mid) return query(p*2,l,r);
	else if(l>mid) return query(p*2+1,l,r);
	else return query(p*2,l,r)+query(p*2+1,l,r);	
}
void print(int p){
	cout<<p<<" "<<tree[p].l<<" "<<tree[p].r<<" "<<tree[p].sum<<" "<<tree[p].add<<endl;
	if(tree[p].l==tree[p].r) return ;
	print(p*2);
	print(p*2+1);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	update(1,2,5,1); //改 
	print(1);
	cout<<query(1,2,3)<<endl; //查 
	print(1);
	return 0;
}
