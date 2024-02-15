/*
快递排序 
void QSort(int a[],int low,int high)
*/ 
#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int a[maxn];
int k,n;
int Partition(int low,int high){
	a[0]=a[low]; //取第一个元素为中心点 
	k=a[low]; //中心点的值 
	while(low<high){
		while(low<high && a[high]>=k)--high;
		a[low]=a[high]; //找后面的小值填补low点的值 
		while(low<high && a[low]<=k) ++low;
		a[high]=a[low]; //找前面的大值填补high点的值 
	}
	a[low]=a[0];//保存中心点的值到中心点该在的数组下标位置 
	return low; //返回中心点的下标位置 
}

void QSort(int low,int high){ //对数组a进行快速排序 
	if(low<high){ //结束条件 
	k=Partition(low,high)	;
	//将a[low..high] 一分为二，k为枢轴元素排好序的位置 
	QSort(low,high-1); //对低子表进行递归排序 
	QSort(low+1,high); //对高子表进行递归排序 
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	QSort(1,n);
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	return 0;
}
