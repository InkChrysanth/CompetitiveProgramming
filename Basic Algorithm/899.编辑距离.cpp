#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int n,m;
char a[N][12];
int edit_distance(char a[],char b[])
{
	int f[12][12];
	int la=strlen(a+1),lb=strlen(b+1);
	for(int i=0;i<=la;i++) f[i][0]=i;
	for(int i=0;i<=lb;i++) f[0][i]=i;
	for(int i=1;i<=la;i++)
	   for(int j=1;j<=lb;j++)
	    {
	    	f[i][j]=min(f[i-1][j]+1,f[i][j-1]+1);
	    	f[i][j]=min(f[i][j],f[i-1][j-1]+(a[i]!=b[j]));
		}
    return f[la][lb];		
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i]+1;
	while(m--)
	{
		int res=0;
		int limit;
		char b[12];
		cin>>b+1>>limit;
		for(int i=1;i<=n;i++)
		{
			if(edit_distance(a[i],b)<=limit) res++;
		}
		cout<<res<<endl;
	}
	return 0;
}

