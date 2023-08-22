#include<bits/stdc++.h>
using namespace std;

struct node
{
	char data;
	node *lchild,*rchild;
};
node *bt,*NewT;
int a;
char ch;
void CreateBitree(node * &bt) {
	cin>>ch;
	if(ch=='#') bt=NULL;
	else{
		bt=new node;
		bt->data=ch;
		CreateBitree(bt->lchild);
		CreateBitree(bt->rchild);
	}
	return ;
}
void build(node* &bt)  //建树 
{
	cin>>a;	 
	if(a==0)  bt=NULL; 
	else
	{
		bt=new node;
		bt->data=a;
		build(bt->lchild);
		build(bt->rchild);
	}	    
	return ;
}
void printxx(node* bt)  //输出先序序列 
{
	if(bt)
	{
	    cout<<bt->data<<"-> ";
		printxx(bt->lchild);	
		printxx(bt->rchild);
	}
}
void printzx(node* bt)  //输出中序序列 
{
	if(bt)
	{
		printzx(bt->lchild);
		cout<<bt->data<<"-> ";
		printzx(bt->rchild);
	}
}
void printhx(node* bt)  //输出后序序列 
{
	if(bt)
	{
		printhx(bt->lchild);		
		printhx(bt->rchild);
		cout<<bt->data<<"-> ";
	}
}
void FloorPrint(node* bt)  //层序遍历
{
    node* temp[100];   //创建pBTNode指针类型的指针数组
    int tail = 0;
    int head = 0;
    temp[tail++] = bt;   

    while (tail > head)
    {
        if (temp[head])
        {
            cout << temp[head]->data << " → ";
            temp[tail++] = temp[head]->lchild;
            temp[tail++] = temp[head]->rchild;
        }
        head++;  
    }
}
void FloorPrint_QUEUE(node* &bt) //层序遍历_队列实现 传值 
{
    queue < node*> q;
    if (bt != NULL)
    {
        q.push(bt);   //根节点进队列
    }

    while (!q.empty())  //队列不为空判断
    {
        cout << q.front()->data << " → "; 

        if (q.front()->lchild != NULL)   //如果有左孩子，leftChild入队列
        {
            q.push(q.front()->lchild);   
        }

        if (q.front()->rchild != NULL)   //如果有右孩子，rightChild入队列
        {
            q.push(q.front()->rchild);
        }
        q.pop();  //已经遍历过的节点出队列
    }
}
//求叶子结点总数 
int LeafCount(node* bt){
	if( bt==NULL) 
	    return 0;
	if(bt->lchild==NULL && bt->rchild==NULL) 
	    return 1;
	else
	    return LeafCount(bt->lchild)+LeafCount(bt->rchild);
}

//求总结点个数
int Count(node* bt){
	if(bt==NULL) 
	    return 0;
	else 
	    return Count(bt->lchild)+Count(bt->rchild)+1;	
}

//求树的深度
int Depth(node* bt) {
	if(bt==NULL)
	   return 0;
	else
	    return max(Depth(bt->lchild) ,Depth(bt->rchild)) +1;  
}

//复制二叉树
int Copy(node* bt,node* &NewT) {
	if(bt==NULL){
		NewT=NULL; return 0;
	}
	else{
		NewT=new node;
		NewT->data=bt->data;
		Copy(bt->lchild,NewT->lchild);
		Copy(bt->rchild,NewT->rchild);
	}
}
int main()
{
		
//	build(bt); 
    CreateBitree(bt);
	cout<<"LeafCount:"<<LeafCount( bt)<<endl;
	cout<<"Count:"<<Count(bt)<<endl;
	cout<<"Depth:"<<Depth(bt)<<endl;
	printxx(bt);
	cout<<endl;
	printzx(bt);
	cout<<endl;
	printhx(bt);
	cout<<endl;
	FloorPrint(bt) ;
	cout<<endl;	
	FloorPrint_QUEUE(bt);
	cout<<endl;
	Copy(bt,NewT);
	cout<<"NewT:";
	printxx(NewT);
	cout<<endl;
	return 0;
}


