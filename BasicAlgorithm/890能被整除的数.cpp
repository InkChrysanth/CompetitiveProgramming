#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=20;
int n,m;
int p[N];
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++) cin>>p[i];
	int res=0;
	for(int i=1;i<1<<m;i++) //多少个组合
	{
		int t=1,cnt=0;
		for(int j=0;j<m;j++)
		   if(i>>j&1)
		   {
		   	cnt++;
		   	if((LL)p[j]*t>n)
			   {
		   		t=-1;
		   		break;
			   }
			   t*=p[j];
		   }
		   if(t!=-1)
		   {
		   	    if(cnt%2) res+=n/t;
		   	    else res-=n/t;
		   }
	} 
	cout<<res<<endl;
	return 0;
}
