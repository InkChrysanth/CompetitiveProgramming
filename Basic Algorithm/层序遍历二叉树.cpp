#include<bits/stdc++.h>
using namespace std;
typedef struct TNode * BiTree;
const int maxn=1005;
struct TNode{
	char Data;
	BiTree Left;
	BiTree Right;
};
BiTree BT;
int t=-1;
char a[maxn]="ABC..GH...DE.I..F..";
void CreateBiTree(BiTree &BT){
	if(a[++t]!='.') {
		BT=new TNode;
		BT->Data=a[t];
		CreateBiTree(BT->Left);
		CreateBiTree(BT->Right);
	}
	else BT=NULL;	
}
BiTree Root;
void LevelOrder(BiTree BT){
	BiTree Q[maxn];
	int head=0,tail=0;
	if(BT){
		cout<<BT->Data<<" ";
		Q[++tail]=BT;
	}
	while(head!=tail){
		BiTree T=Q[++head];
		if(T->Left){
			Q[++tail]=T->Left;
			cout<<Q[tail]->Data<<" ";
		}
		if(T->Right){
			Q[++tail]=T->Right;
			cout<<Q[tail]->Data<<" ";
		}
	}	
}
int main(){
	CreateBiTree(Root);
	LevelOrder(Root);
}

