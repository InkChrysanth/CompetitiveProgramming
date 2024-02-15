#include<bits/stdc++.h>
#include<unordered_set> 
using namespace std;
const int N=110,M=10010;

int n,m;
int s[N],f[M];
int sg(int x)
{
	if(f[x]!=-1) return f[x];
	unordered_set<int>S;
	for(int i=0;i<m;i++)
	{
		int sum=s[i];
		if(x>=sum) S.insert(sg(x-sum));
	}
	for(int i=0;;i++)
	   if(!S.count(i))
	       return f[x]=i;
}
int main()
{
	cin>>m;
	for(int i=0;i<m;i++) cin>>s[i];
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
