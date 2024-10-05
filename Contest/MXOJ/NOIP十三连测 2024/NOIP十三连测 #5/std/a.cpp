#include<bits/stdc++.h>
using namespace std;
#define int long long
#define il inline
il int read()
{
	int re=0,k=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')k=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){re=re*10+ch-48;ch=getchar();}
	return re*k;
}
il void write(int x)
{
	if(x<0)return putchar('-'),write(-x),void();
	if(x<=9)return putchar(x+48),void();
	return write(x/10),write(x%10),void();
}
int t,n,l,r,ans;
const int M=4e18+7;
signed main()
{
	cin>>t;
	while(t--)
	{
		n=2;l=read();r=read();
		if(l==r)
		{
			puts("1");continue;
		}
		if(n==1ll)
		{
			write((r-l+1ll)%M);puts("");continue;
		}
		int rr,ll,rrr;
		int lim=62ll;
		while(lim>=0ll)
		{
			if(((l>>lim)&1ll)!=((r>>lim)&1ll))
			{
				ll=l&((1ll<<(lim+1ll))-1ll);
				rr=(1ll<<(lim))+ll;
				int tt=lim-1ll;
				while(tt>=0ll&&!((r>>tt)&1ll))tt--;
				rrr=(1ll<<lim)+(1ll<<(tt+1ll))-1ll;
				break;
			}
			lim--;
		}
		if(rrr>=rr)//区间取并
		{
			ans=(1ll<<(lim+1ll))-ll;
		}
		else
		{
			ans=(1ll<<(lim+1ll))-rr+rrr-ll+1ll;
		}
		write(ans%M);
		puts("");
	}
}
