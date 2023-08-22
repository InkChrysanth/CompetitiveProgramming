#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
struct BinaryTreeNode{
	int value;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;
};
 
void addBTNode(BinaryTreeNode **myBT,int val);//添加节点，满足每个父亲节点大于左边的，小于右边的 
 
void preorder_showBT(BinaryTreeNode *myBT);
void midorder_showBT(BinaryTreeNode *myBT);
void lastorder_showBT(BinaryTreeNode *myBT);
 
int main(){
	
	BinaryTreeNode *myBT = NULL;
	
	addBTNode(&myBT,10);
	addBTNode(&myBT,2);
	addBTNode(&myBT,3);
	addBTNode(&myBT,15);
	addBTNode(&myBT,18);
	addBTNode(&myBT,1);
	addBTNode(&myBT,16);
	
	preorder_showBT(myBT);
	cout<<endl;
	midorder_showBT(myBT);
	cout<<endl;
	lastorder_showBT(myBT);
	cout<<endl;
	
	return 0;
}
 
 
void addBTNode(BinaryTreeNode **myBT,int val){
	if(*myBT == NULL){
		*myBT = new BinaryTreeNode();
		(*myBT)->value = val;
		(*myBT)->m_pLeft = NULL;
		(*myBT)->m_pRight = NULL;
		return;	
	}
		
	if(val == (*myBT)->value){
		return;
	}
	else if(val < (*myBT)->value){
		addBTNode(&(*myBT)->m_pLeft,val);
	}
	else{
		addBTNode(&(*myBT)->m_pRight,val);
	}			
}
 
void preorder_showBT(BinaryTreeNode *myBT){
	if(myBT == NULL )
		return;
	cout<<myBT->value<<" ";
	
	preorder_showBT(myBT->m_pLeft);
	preorder_showBT(myBT->m_pRight);
}
 
void midorder_showBT(BinaryTreeNode *myBT){
	if(myBT == NULL )
		return;
	
	midorder_showBT(myBT->m_pLeft);
	cout<<myBT->value<<" ";
	midorder_showBT(myBT->m_pRight);
}
 
void lastorder_showBT(BinaryTreeNode *myBT){
	if(myBT == NULL )
		return;
	
	lastorder_showBT(myBT->m_pLeft);
	lastorder_showBT(myBT->m_pRight);
	cout<<myBT->value<<" ";
}

