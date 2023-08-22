/*
双向链表 、
p->pre->next=p=p->next->pre//对称性 
在双向链表中插入s 
1.s->pre=p->pre;
2.p->pre->next=s;
3.s->next=p;
4.p->pre=s;
删除p
p->pre->next=p->next;
p->next->pre=p->pre;
delete p; 

*/ 
typedef struct DuLNode{
	Elemtype data;
	struct DuLNode *pre,*next;
}DuLNode,*DuLinkList;

