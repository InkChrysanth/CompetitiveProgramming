/*
单链表 
*/
#include<bits/stdc++.h>
using namespace std;
/*
typedef struct Lnode{
	int  data;
	struct Lnode *next;
}*LinkList;
*/
typedef struct{
	char num[8];
	char name[8];
	int score;
}ElemType;
typedef struct Lnode{
	ElemType data;
	struct Lnode *next;
}Lnode,*LinkList;
/*
Lnode *LocateELem_L(LinkList L,Elemtype(e)){
	Lnode *p;
	p=L->next;
	while(p && p->data!=e)
	    p=p->next;
	return p;    
}
*/
int main(){
	Lnode *p;
	LinkList L;
	L =new Lnode;
//	L=(LinkList)malloc(sizeof(Lnode)); //分配内存 
    L->next=NULL;
    /*
    p=L;
    L=->next;
    delete p;
    //free(p) ; 用malloc分配地址时可用;
	*/ 
	//计算链表的长度
	int count=0;
	p=L->next;
	while(p){ //计算链表的长度 
		count++;
		p=p->next ;
	}
	
	//获取线性表L中的第i个数据元素的内容，通过变量e返回
	p=L->next;
	int i,j=1;
	while(p && j<i) {
		p=p->next;++j;
	}
	if(!p || j>i) return 0 ;
	cout<<p->data.num<<endl; //取第i个元素的num成员值 
	
	//找到值为e的数据元素 
	p=L->next;
	while(p && p->data.num==1)
	    p=p->next;
	Lnode *pp=p;
	
	//销毁单链表
    while(L){ //销毁单链表 
    	p=L;
    	L=L->next;
    	delete p;
	}
	
	//清空单链表
	p=L->next;
	while(p){ //清空单链表 
		L->next=p->next;
		delete p;
		p=L->next;
	}
	L->next=NULL;
	
	
	return 0;
}
