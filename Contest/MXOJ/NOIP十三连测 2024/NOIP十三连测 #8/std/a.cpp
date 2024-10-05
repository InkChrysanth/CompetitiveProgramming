#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>

using namespace std;

const int mo=1000000007;

int ksm(int a,long long b)
{
	int ans=1;
	while(b)
	{
		if (b&1) ans=1ll*ans*a%mo;
		a=1ll*a*a%mo;
		b>>=1;
	}
	return ans;
}

int solve(long long x)
{
	int ans=ksm(2,x+1)+mo-1;
	ans%=mo;
	if (x%2==0) ans--;
	int inv=(mo+1)/3;
	ans=1ll*ans*inv%mo;
	ans=(ans+mo-(x+1)/2%mo)%mo;
	return ans;
}

int main()
{
	long long l,r;
	scanf("%lld%lld",&l,&r);
	printf("%d\n",(solve(r)-solve(l-1)+mo)%mo);

	return 0;
}
