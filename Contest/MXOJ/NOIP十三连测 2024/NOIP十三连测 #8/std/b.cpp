#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

#define inc(a,b) {a+=b;if (a>=mo) a-=mo;}
#define dec(a,b) {a-=b;if (a<0) a+=mo;}

const int maxn=100010;
const int mo=1000000007;

int n,m,y[maxn],z[maxn][2],cnt[maxn];

bool vis[maxn];

int gcd(int a,int b)
{
	if (!b) return a;
	else return gcd(b,a%b);
}

int mul(int a,int b)
{
	if (b==0) return 1;
	int ans=1;
	while (b)
	{
		if (b&1) ans=1ll*ans*a%mo;
		a=1ll*a*a%mo;
		b>>=1;
	}
	return ans;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int a=1;a<=m;a++)
		scanf("%d",&y[a]);
	for (int a=1;a<=m;a++)
		if (!vis[a])
		{
			int p=y[a],num=1;
			while (p!=a)
			{
				vis[p]=true;
				p=y[p];
				num++;
			}
			vis[a]=true;
			cnt[num]+=num;
		}
	int q=0;
	long long l=1;
	for (int a=1;a<=m;a++)
		if (cnt[a])
		{
			z[q][0]=a;
			z[q][1]=cnt[a];
			q++;
			l=l/gcd(l,a)*a;
		}
	fprintf(stderr,"%lld\n",l);
	int ans=0;
	for (int a=1;a<(1<<q);a++)
	{
		int num1=0,lcm=1,v=0;
		for (int b=0;b<q;b++)
			if (a&(1<<b)) 
			{
				num1++;
				lcm = lcm*z[b][0]/gcd(lcm,z[b][0]);
			}
		for (int b=a;b;b=(b-1)&a)
		{
			int num2=0,lcm=1,total=0;
			for (int c=0;c<q;c++)
				if (b&(1<<c))
				{
					num2++;
					lcm = lcm*z[c][0]/gcd(lcm,z[c][0]);
					if (lcm<0) printf("gg\n");
					total += z[c][1];
				}
			if ((num1&1)!=(num2&1)) dec(v,mul(total,n))
			else inc(v,mul(total,n));
		}
		inc(ans,1ll*v*lcm%mo);
	}
	ans=1ll*ans*mul(mul(m,n),mo-2)%mo;
	printf("%d\n",ans);

	return 0;
}
