#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *next;
};
node *head,*tail,*p;
void del(int key){ //删除节点 
	node *pre;
	p=head; pre=p;
	while(p->next!=NULL){	
		if(p->data==key){
			pre->next=p->next;
			delete p;
			p=pre->next;
		}
		else
		{ //向后检索 
			pre=p;
			p=p->next;
		}
	}
	if(p->data==key){
		pre->next=NULL;
		delete p;
	}
}
void inst(int key,int pos){ //插入节点到指定位置 
	int k=0;
	node *np,*pre;
	p=head;pre=head;
	while(p->next!=NULL){
		p=p->next;
		k++;
		if(k==pos){
			np=new node;
			np->data=key;
			pre->next=np;
			np->next=p;	
			break;		
		}
		else
		{
			pre=p;		
		}
	}	
	if(k<pos){
		np=new node;
		np->data=key;
		p->next=np;
		np->next=NULL;
	}
}

int main(){
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
    p=head->next;
    if(p->next!=NULL){
    	while(p->next!=NULL){
    	cout<<p->data<<" ";
    	p=p->next;
	    }
	    cout<<p->data<<endl;
	}
    else
        cout<<"空链表"<<endl;
}
