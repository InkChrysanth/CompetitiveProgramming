/*
线段树的整体框架不变，我们只需要在bulid和update函数中完善pushup操作 
*/
struct SegmentTree
{
	int l,tr;
	int sum; //区间和 
	int dat; //区间最大连续子段和 
	int lmax;//紧靠左端的最大连续子段和 
	int rmax;//紧靠右端的最大连续子段和 
	
}tree[MAXN<<2];
void bulid(int p,int l,int r){
	tree[p].l=l,tree[p].r=r;
	if(l==r){tree[p].sum=tree[p].dat=tree[p].lmax=tree[p].rmax=a[l]	;return ;} //叶节点
	int mid=(l+r)/2; //折半 
	bulid(p*2,l,mid);//左子节点[l,mid],编号p*2 
	bulid(p*2+1,mid+1,r);//右子节点[mid+1,r],编号p*2+1 
	//从下往上传递信息
	tree[p].sum=tree[p*2].sum+tree[p*2+1].sum;
	tree[p].lmax=max(tree[p*2].lmax,tree[p*2].sum+tree[p*2+1].lmax) ;
	tree[p].rmax=max(tree[p*2+1].rmax,tree[p*2+1].sum+tree[p*2].rmax) ;
	tree[p].dat=max(tree[p*2].dat,max(tree[p*2+1].dat,tree[p*2].rmax+tree[p*2+1].lmax));
}
