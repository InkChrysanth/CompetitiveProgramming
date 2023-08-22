#include<bits/stdc++.h> 
#include<unordered_set>
using namespace std;
const int N=110;
int f[N];
int sg(int x)
{
	if(f[x]!=-1) return f[x];
	unordered_set<int>S;
	for(int i=0;i<x;i++)
	   for(int j=0;j<=i;j++)
	       S.insert(sg(i)^sg(j));
	for(int i=0;;i++)      
	    if(!S.count(i)) 
	       return f[x]=i;
}
int main()
{
   int n;
   cin>>n;
   memset(f,-1,sizeof f);
   int res=0;
   for(int i=0;i<n;i++)	
   {
   	int x;
   	cin>>x;
   	res^=sg(x);
   }
   if(res) puts("Yes");
   else puts("No");
   return 0;
}
