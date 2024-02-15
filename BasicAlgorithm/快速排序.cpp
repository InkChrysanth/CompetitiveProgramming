#include<bits/stdc++.h>
using namespace std;
int a[10005];
void swap(int &a,int &b)
{
	int tmp=a;
	a=b;
	b=tmp;
}
void QuickSort(int a[],int s,int e)
{
	if(s>=e) return ;
	int k=a[s];
	int i=s,j=e;
	while(i!=j){
		while(j>i && a[j]>=k) --j;
        swap(a[i],a[j])	; //翻转 
	    while(i<j && a[i]<=k) ++i;
	    swap(a[i],a[j]); //翻转 
	} //处理完后，a[i]=k 
	QuickSort(a,s,i-1); //k左边的一半 
	QuickSort(a,i+1,e); //k右边的一半 
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	QuickSort(a,0,n-1);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
