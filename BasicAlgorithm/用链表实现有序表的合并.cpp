/*
用链表实现有序表的合并 
pc->next=pa?pa:pb;
if(pa)
   pc->next=pa;
else
   pc->next=pb;
delete lb;    //释放Lb的头结点 
*/
void MergeList_L(LinkList &La,LinkList &Lb,LinkList &Lc){
	pa=La->next ;pb=Lb->next; //pa,pb指针分别指向它们链表的元地址 
	pc=Lc=La; //用La的头结点作为Lc的头结点
	while(pa&& pb) {
		if(pa->data<=pb->data) {
			pc->next=pa;
			pc=pa;
			pa=pa->next;
		}
		else{
			pc->next=pb;
			pc=pb;
			pb=pb->next;
		}
	}
	pc->next=pa?pa:pb; //插入剩余段 (pa=NULL的话 pc->next=pb;pb=NULL的话pc->next=pa; 
	delete Lb; //释放Lb的头结点 
	 
}
