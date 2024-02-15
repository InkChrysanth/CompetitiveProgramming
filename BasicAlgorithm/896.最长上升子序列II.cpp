#include<bits/stdc++.h> 
using namespace std;
const int N=100010;
int q[N],a[N];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int len=0; //记录最大的上升序列长度 
	q[0]=-2e9;
	for(int i=1;i<=n;i++)
	{
		int l=-1,r=len;
		while(l<r)
		{
			int mid=(r-l)/2+l+1;
			if(q[mid]<a[i]) l=mid;
			else r=mid-1;
		}
		len=max(len,r+1);
		q[r+1]=a[i];
	}
	cout<<len<<endl;
	return 0;
}
