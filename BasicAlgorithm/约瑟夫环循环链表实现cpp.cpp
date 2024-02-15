/*
约瑟夫环的循环链表实现 
*/
#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *next;
};
node *h,*t,*p; //h头指针,t尾指针,p移动指针 
int main(){
	int i,j,n,m; 
	cin>>n>>m;
	h=new node; //申请头结点 
	h->data=1;
	h->next=0;
	t=h;
	for(i=2;i<=n;i++){ //申请新结点 
		p=new node;
		p->data=i;
		p->next=NULL;
		t->next=p;
		t=p;
	}
	t->next=h;t=h; //连成环 
	for(i=1;i<=n;i++){ //遍历输出 
		for(j=1;j<m-1;j++){
			t=t->next;//每次向后移一位 
		}
		cout<<t->next->data<<" ";
		t->next=t->next->next;
	}
	return 0;
}
