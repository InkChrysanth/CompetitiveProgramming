/*
采药（NOIP2005初中组）
70 3
71 33
69 1
1 2 
*/ 
#include<bits/stdc++.h>
using namespace std;
int f[10005],v[10005],t[10005];
int n,T;
int main(){
	cin>>T>>n;
	for(int i=1;i<=n;i++)cin>>t[i]>>v[i];
	for(int i=1;i<=n;i++) //穷举草药 
	   for(int j=T;j>=t[i];j--)
	      f[j]=max(f[j],f[j-t[i]]+v[i]);
	cout<<f[T] <<endl;
	return 0;     
}
