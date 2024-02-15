/*
 二叉排序树的生成 
 二叉排序树，是非常特殊的一种树，具体定义见任何一本数据结构书籍。

其删除一个节点需要考虑对应节点的状态，具体的说就是，是否存在左右节点，等等。需要按照以下情况讨论。

1.查找待删除节点，在查找的同时需要记录一下待删除节点的父亲。

2.如果待删除节点的左右节点都不存在，那么直接删除。

3.如果待删除节点左子树存在右子树不存在，或者左子树不存在右子树存在。直接将其子树中存在的一边候补上来即可。

4.如果待删除节点左右子树都在，这个情况是最复杂的。需要按照二叉排序树的性质从其左子树或者有子树中选择节点补到待删除节点的位置。

    如果从左子树中选，就应该选择左子树中最右边的那个叶子节点（这里肯定是叶子，如果不是叶子，那么就不是最右边的节点）

    如果从右子树中选，就应该选择有子树中最左边的那个叶子节点。
*/
#include<bits/stdc++.h>
using namespace std;
int x;
struct node
{
	int data;
	node *lchild,*rchild;
};
node *bt;
void Jians(node* &bt ,int k){	
	if(bt==NULL) {
	   bt=new node;
	   bt->data=x;
	   bt->lchild=NULL;
	   bt->rchild=NULL;
	   return ;
	}
	if(k<bt->data) Jians(bt->lchild,k);
	else if(k==bt->data) return ;
    else if(k>bt->data) Jians(bt->rchild,k);	
}
void ZX(node* bt){
	if(bt) {
		ZX(bt->lchild);
		cout<<bt->data<<" ";
		ZX(bt->rchild);
	}
}
void  Del(node* &bt,int k)
{//1.寻找待删除节点在链表中的位置,如果不存在该结点，p指针会一直向后移动直到最后一位
	node  *p,*f,*s,*q;
	p=bt;f=NULL;
	while(p)
	{
		if(p->data==k)   break;
		f=p;//f为p的双亲结点
		if(p->data>k) //往左找 
			p=p->lchild;
		else
		p=p->rchild; //往右找 
	}
	//2.判断该点在二叉树中是否存在
	if(p==NULL) return ;
	//3.单分支结构
	if(p->lchild==NULL)//p无左子树
	{
		if(f==NULL)
			bt=p->rchild;
		else  if(f->lchild==p)
			f->lchild=p->rchild;
		else 
			f->rchild=p->rchild;
		free(p);
	}
	else//双分支结点
	{
		q=p;s=p->lchild;//此时将p赋值为q，s为p的左子树，则q为s的双亲
		while(s->rchild)//查找p的左子树中查找最右下结点——最大结点
			{
				q=s;
				s=s->rchild;//s为左子树最大结点，q为左子树最大节点的父母结点
			}
	if(q==p)//用来判断p结点的左子树是否有右子树的
		 q->lchild=s->lchild;//s为p左子树的最右子树，所以它没有右子树了
	else     
		q->rchild=s->lchild;
		p->data=s->data;
		free(s);
	}
	return  ;
}

int main(){
	while(cin>>x){
	   Jians(bt,x);	
	}	
	Del(bt,24);
	ZX(bt);
	return 0;
}
