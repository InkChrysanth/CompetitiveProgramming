#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=12010,M=2010;
int f[M],v[N],w[N];

int main()
{
    cin>>n>>m;
    int cnt=0;
    for(int i=1;i<=n;i++) //通过二进制转换成01背包问题 
	{
		int a,b,s;
		cin>>a>>b>>s;
		int k=1;
		while(k<=s)
		{
			cnt++;
			v[cnt]=a*k;
			w[cnt]=b*k;
			s-=k;
			k<<=1;
		}
		if(s>0) 
		{
			cnt++;
			v[cnt]=a*s;
			w[cnt]=b*s;
		}
	}
	n=cnt;
    for(int i=1;i<=n;i++)
        for(int j=m;j>=v[i];j--)
           f[j]=max(f[j],f[j-v[i]]+w[i]);
    cout<<f[m]<<endl;           
    return 0;       
}
