#include<bits/stdc++.h>
using namespace std;
const int N=110;
int f[N],v[N],w[N];
int main()
{
	int n,m,s;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		for(int k=1;k<=s;k++)cin>>v[k]>>w[k];		
		for(int j=m;j>=0;j--)
		    for(int k=1;k<=s;k++)
		        if(j>=v[k])
		            f[j]=max(f[j],f[j-v[k]]+w[k]);
	}
	cout<<f[m]<<endl;
	return 0;
}
