#include<bits/stdc++.h>
using namespace std;
const int n=7;
int a[n]={3,5,1,7,6,4,2};
int heap[200],len=0;
void Insert(int x){
	int pa,son;
	heap[0]=-10000;//哨兵
	son=++len;
	pa=son/2;
	while(x<heap[pa]) {
		heap[son]=heap[pa]; //上面元素下移 
		son=pa;pa=son/2;    //下标上浮 
	}
	heap[son]=x; //插入x 
}
int DeleteMin()//取出并删除根元素 
{
	int pa,son;
	int h=heap[1];
	int t=heap[len--];
	pa=1;son=pa*2;
	while(son<=len){
		if(son<len && heap[son+1]<heap[son]) son++;
		if(t<=heap[son]) break;
		heap[pa]=heap[son]; //下面元素上移 
		pa=son;son=pa*2;  //下标下沉 
	}
	heap[pa]=t; //插入尾元素 
	return h;   //返回根元素 
}
int main(){
	for(int i=0;i<n;i++) Insert(a[i]); //建小根堆 
	for(int i=0;i<n;i++) cout<<DeleteMin()<<" "; //输出堆元素 
	return 0;
}
	
