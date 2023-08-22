#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *next;
};
node *head,*tail,*p;
void del(int k){
	node *pre;//要寻找结点的前驱
	p=head;pre=p;
	while(p->next!=NULL){//判断p是否移到尾结点 
		if(p->data==k){
			pre->next=p->next;
			delete p;//释放p所指向的结点 
			p=pre->next; //
		}		
		else
		{ //当前的结点值不为k,则继续走 
			pre=p;
			p=p->next;
		 } 
	}
	 if(p->data==k){ //while循环完了以后，p指向的是最后一个节点，需要单独处理 
	 	delete p; //删除最后一个节点，pre就是最后一个节点 
	 	pre->next=NULL;
	 }
}
void inst(int key,int pos){
	node *pre,*np;
	p=head;pre=p;
	int k=0;//记录当前节点是第几个节点 
	while(p->next!=NULL){
		p=p->next;
		k++;
		if(k==5){
			np=new node;
			np->data=key;
			np->next=p;
			pre->next=np;
			break;
		}
		else{
			pre=p;
		}
	}
	if(k<5){
		np=new node;
		np->next=NULL;
		np->data=key;
		p->next=np;
	}
}
int main()
{
	int x;
	cin>>x;
	head=new node;
	tail=head;
	tail->next=NULL;
	while(x!=-999){
		p=new node;
		p->data=x;
		tail->next=p;
		tail=p;
		tail->next=NULL;
		cin>>x;		
	}
	del(8);
	inst(100,5);
	if(head->next!=NULL){
		p=head->next;
	    while(p->next!=NULL){
		    cout<<p->data<<" ";
		   p=p->next;
	    }
	     cout<<p->data;
	}
	else cout<<" 空链表"<<endl;
	return 0;
}
