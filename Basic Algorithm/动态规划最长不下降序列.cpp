/*
动态规划最长不下降序列 
5 13 12 23 62 32 32 60 53 1 7 81 
单调队列o(lgn) 
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int a[maxn],f[maxn],n,k,maxnn,pre[maxn];
int main(){
	cin>>n;
	pre[1]=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=0;i<=n;i++)f[i]=1;
	for(int i=1;i<=n;i++)
	   for(int j=1;j<=i-1;j++)
	   if(a[i]>a[j]){
	   	if(f[i]<f[j]+1){
	   		f[i]=f[j]+1;
	   		pre[i]=j;
		   }
	   	  f[i]=max(f[i],f[j]+1);
	   	  maxnn=max(f[i],maxnn);
	   }	       
	cout<<maxnn<<endl;
}

