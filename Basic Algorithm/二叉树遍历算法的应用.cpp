/*
二叉树遍历算法的应用 
*/
#include<bits/stdc++.h>
using namespace std;
char ch;
typedef struct BiTree;
typedef BiTree *BT;
struct BiTree{
	int data;
	BT lchild;
	BT rchild;
};
BT bt;
//建立二叉树
void CreateBitree(BiTree &T) {
	cin>>ch;
	if(ch=='#') T=NULL;
	else{
		T=new BiTree;
		T->data=ch;
		CreateBitree(T->lchild);
		CreateBitree(T->rchild);
	}
	return ;
}
//求叶子结点个数 
int LeafCount(BiTree T){
	if(T==NULL) 
	    return 0;
	if(T->lchild==NULL && T->rchild==NULL) 
	    return 1;
	else
	    return LeafCount(T->lchild)+LeafCount(T->rchild);
}

//求总结点个数
int Count(BiTree T){
	if(T==NULL) 
	    return 0;
	else 
	    return Count(T->lchild)+Count(T->rchild)+1;	
}

//求树的深度
int Depth(BitTree T) {
	if(T==NULL)
	   return 0;
	else
	    return max(Depth(T->lchild) ,Depth(T->rchild)) +1;  
}

//复制二叉树
int Copy(BiTree T,Bitree &NewT) {
	if(T==NULL){
		NewT=NULL; return 0;
	}
	else{
		NewT=new BitNode;
		NewT->data=T->data;
		Copy(T->lchild,NewT->lchild);
		Copy(T->rchild,NewT->rchild);
	}
}
int main(){
	
	CreateBitree(T);
	return 0;
}
