/*
线性表 
*/
#include<bits/stdc++.h> 
using namespace std;
#define LS 1000
typedef struct{
	float p;
	int e;
}Polynomial;
typedef struct{
	Polynomial *elem; //存储空间的基地址 
	int length; //多项式中当前项的个数 
}SqList; //多项式的顺序存储结构类型为SqList 
int main(){
	SqList L;//定义变量L,L是SqList这种类型的，L是顺序表 
	 L.elem[0].e=7;
	 L.elem[0].p=1;
	return 0;
}
