#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int a[maxn]={0,1,2}; 
int bu(int x){
  if(a[x]!=0) return a[x];
  a[x]=bu(x-1)+bu(x-2);
	return a[x];
}
int main()
{
int n;
cin>>n;
bu(n);
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
return 0;
}
