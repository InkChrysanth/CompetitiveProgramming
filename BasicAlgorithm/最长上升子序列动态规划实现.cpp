#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int a[maxn],f[maxn],n,k,maxnn;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=0;i<=n;i++)f[i]=1;
	for(int i=1;i<=n;i++)
	   for(int j=1;j<=i-1;j++)
	   if(a[i]>a[j]){
	   	  f[i]=max(f[i],f[j]+1);//到第i个数时有两种情况，取不取i
	   	  maxnn=max(f[i],maxnn);
	   }
	       
	cout<<maxnn<<endl;
}
