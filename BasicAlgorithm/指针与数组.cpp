/*
指针和数组
 
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[205];int *p;
	p=a; //p指向数组a的起始地址，亦即p指向了a[0] 
	*p=10; //使得a[0]=10 
	*(p+1)=20; //使得a[1] =20
	p[0]=30; //p[i]和*(p+i) 是等效的，使得a[0]=30 
	p[4]=40; //使得a[4 ]=40
	for(int i=0;i<10;i++) *(p+i)=i; //对数组a的前10个元素进行赋值 
	++p; //p指向a[1] 
	cout<<p[0]<<endl;//输出1 p[0]等效于*p,p[10]既是a[1] 
	p=a+6; //p指向a[6] 
	cout<<*p<<endl; //输出6 
	return 0;
}
