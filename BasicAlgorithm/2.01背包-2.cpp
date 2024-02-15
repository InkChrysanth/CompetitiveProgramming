#include<bits/stdc++.h> 
using namespace std;
int n,m;
const int N=1010;
int f[N],w[N],v[N];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>v[i]>>w[i];
	for(int i=1;i<=n;i++)
	    for(int j=m;j>=v[i];j--)
	    {
	     f[j]=max(f[j],f[j-v[i]]+w[i]);//ºÃ≥–÷¡…œ“ª≤„ 
		}
    cout<<f[m]<<endl;
	return 0;		
}
