/*
约瑟夫环的模拟链表实现 
*/
#include<bits/stdc++.h>
using namespace std;
const int n=5,m=3; 
int a[n+1],b[n+1]; //a[n+1]指针， b[n+1]存出链顺序 

int main(){
	int i,k=1,j=n;
	for(i=1;i<n;i++) a[i]=i+1; //模拟链表 
	a[n]=1; //第n人指向第一人，形成一个环 
	for(i=1;i<=n;i++) //n个人均出链为止 
	{
		while(k<m){ //报数 
			j=a[j]; //移动指针 
			k++; //计数器加 1 
		}
		b[i]=a[j]; //保存m; 
		a[j]=a[a[j]]; //m出链 
		k=1;		
	}
	for(i=1;i<=n;i++) cout<<b[i]<<" "; //输出 
	return 0;
}
