#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
int a[MAX],MaxSum[MAX],Pre[MAX],n;
void print(int Pre[],int x){
	int i=x;
	int b[MAX];
	int bn=0;
  while(Pre[i]!=0)	{ //保存到新数组中去 
  	b[++bn]=a[Pre[i]];
  	i=Pre[i];
  }
  for(int j=bn;j>=1;j--) cout<<b[j]<<" ";
  cout<<a[x]<<endl; //输出最后一位 
  return ;
}
int main()
{
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
		MaxSum[i]=1;
		Pre[i]=0;
	}
	for(i=2;i<=n;i++)
	   for(j=1;j<=i;j++){
	   	if(a[j]<a[i]){
	   		if(MaxSum[j]+1>MaxSum[i]) {
	   			MaxSum[i]=MaxSum[j]+1;
	   			Pre[i]=j;
			   }
		   }
	   }
	   int Max=0,k=0;
	for(i=1;i<=n;i++)  {
		if(MaxSum[i]>Max) {
			Max=MaxSum[i],k=i;
		}
	} 
	cout<<Max<<endl;
	print(Pre,k);
	return 0;
}
