/*
直接插入排序、二分、希尔三种方法 
希尔排序算法效率与增量序列的取值有关 
直接插入排序和二分排序为稳定排序 
希尔排序为不稳定的排序 
*/

#include<bits/stdc++.h>
using namespace std;

const int maxn=100005;
int i,j,a[maxn],n;
void kin(int a[]){  //直接插入排序
	for(i=2;i<=n;i++){
	   if(a[i]<a[i-1]) {
		    a[0]=a[i];//启用哨兵
		    for(j=i-1;a[0]<a[j];j--) //从后往前比较 
                 a[j+1]=a[j];
            a[j+1]=a[0];
	    }	 
    }
}
void erfenin(int a[]){  //二分排序 
	for(i=2;i<=n;i++){
	   if(a[i]<a[i-1]) {
		    a[0]=a[i];//启用哨兵
		    int low=1,high=i-1;
		    while(low<=high){ //二分排序 
		    	int mid=low+(high-low)/2;
		        if(a[0]<a[mid]) high=mid-1;
		        else low=mid+1;
			}
		    for(j=i-1;j>=low;--j) a[j+1]=a[j]; //移动后面的位置 
		    a[low]=a[0]; //把a[0]赋给找到的插入位置 
	    }	 
    }
}
int b[3]={7,3,1};//排序时的元素间隔距离 
void ShellInsert(int a[],int t){ //希尔排序,t为间隔距离 
	for(i=t+1;i<=n;i++) //间隔为t的插入排序 把原来插入排序的1换成t就可 
	   if(a[i]<a[i-t]){
	   	a[0]=a[i];
	   	for(j=i-t;a[0]<a[j];j-=t)
	   	   a[j+t]=a[j];
	   	a[j+t]=a[0];   
	   }	   
}
void ShellSort(int a[],int b[]){ //按数组b为间隔距离进行的希尔排序 
	int t=sizeof(b);
	for(int k=0;k<t;k++)
	  ShellInsert(a,b[k]);
}

int main(){
	
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	//kin(a);
    //erfenin(a);
    ShellSort(a,b); 
    for(i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}


 
