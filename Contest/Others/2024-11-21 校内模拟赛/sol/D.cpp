#include <cstdio>
#include <cstdlib>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
const int N=100500;
int n;
int a[N];
int main()
{
	scanf("%d",&n);
	a[0]=a[1]=1;
	fo(I,2,n)
	{
		int t=0;
		fo(i,1,a[0])
		{
			a[i]=a[i]*I+t;
			t=a[i]/10;
			a[i]=a[i]%10;
		}
		for(;t;a[++a[0]]=t%10,t/=10);
	}
	a[1]+=n;
	fo(i,1,a[0])if(a[i]>9)
	{
		a[i+1]+=a[i]/10;
		a[i]%=10;
	}
	for(;a[a[0]+1];++a[0],a[a[0]+1]+=a[a[0]]/10,a[a[0]]%=10);
	fod(i,a[0],1)printf("%d",a[i]);
	printf("\n");
	return 0;
}
