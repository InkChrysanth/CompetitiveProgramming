#include <bits/stdc++.h>
#define N 200011
#define pii pair<int,int>
#define s1 first
#define s2 second
using namespace std;
const int p=998244353;
int n,a[N];pii mx[21][N];
int f[N],df[N],sf[N],g[N],sg[N];
int L[N],L_[N],R[N],R_[N];
void proc()
{
	memset(df,0,sizeof(df));
	memset(f,0,sizeof(f));
	memset(sf,0,sizeof(sf));
	for(int i=1;i<=n;++i)L[i]=i-1,R[i]=i+1;
	for(int i=1;i<=n;++i)while(L[i]&&a[L[i]]<=a[i])L[i]=L[L[i]];
	for(int i=n;i;--i)while(R[i]<=n&&a[R[i]]<a[i])R[i]=R[R[i]];
	f[0]=sf[0]=1;
	for(int M=1;M<=n;++M)
	{
		int R=::R[M]-1,L=::L[M]+1;
		if(R-M+1<=M-L)
		{
			for(int i=M;i<=R;++i)
			{
				int tl=L,tr=min(M,i-a[M]+1);
				if(tl<=tr)f[i]=(0ll+f[i]+sf[tr-1]-(tl>1?sf[tl-2]:0))%p;
			}
		}
		else
		{
			for(int i=L;i<=M;++i)
			{
				int tl=max(M,i+a[M]-1),tr=R;
				if(tl<=tr)
				{
					df[tl]=(df[tl]+f[i-1])%p;
					df[tr+1]=(df[tr+1]-f[i-1])%p;
				}
			}
		}
		df[M]=(df[M]+df[M-1])%p;
		f[M]=(f[M]+df[M])%p;
		sf[M]=(sf[M-1]+f[M])%p;
	}
}
int prv[N],nxt[N];
pii ta[N];
void getLR()
{
	for(int i=1;i<=n;++i)L[i]=i-1,R[i]=i+1;
	for(int i=1;i<=n;++i)while(L[i]&&a[L[i]]<=a[i])L[i]=L[L[i]];
	for(int i=n;i;--i)while(R[i]<=n&&a[R[i]]<a[i])R[i]=R[R[i]];
	for(int i=1;i<=n;++i)ta[i]=pii(a[i],i);
	sort(ta+1,ta+1+n,greater<pii >());
	nxt[n+1]=n+1;
	for(int i=1;i<=n;++i)
	{
		int x=ta[i].s2;
		prv[x]=L[x];
		nxt[x]=R[x];
		nxt[L[x]]=x;prv[R[x]]=x;
		L_[x]=prv[prv[x]];R_[x]=nxt[nxt[x]];
	}
}
int ans[N];
int calc(int l1,int r1,int l2,int r2,int llen,int rlen)
{
	int ans=0;
	if(r1-l1+1<=r2-l2+1)
	{
		for(int i=l1;i<=r1;++i)
		{
			int tl=max(l2,i+llen-1),tr=min(r2,i+rlen-1);
			if(tl<=tr)ans=(ans+1ll*f[i-1]*(sg[tr+1]-sg[tl]))%p;
		}
	}
	else
	{
		for(int i=l2;i<=r2;++i)
		{
			int tl=max(l1,i-rlen+1),tr=min(r1,i-llen+1);
			if(tl<=tr)ans=(ans+1ll*g[i+1]*(sf[tr-1]-(tl>1?sf[tl-2]:0)))%p;
		}
	}
	return ans;
}
int main()
{
	scanf("%d",&n);for(int i=1;i<=n;++i)scanf("%d",a+i);
	proc();
	for(int i=0;i<=n;++i)g[i]=f[i];
	reverse(a+1,a+1+n);
	proc();
	reverse(f,f+1+n+1);
	for(int i=0;i<=n+1;++i)swap(f[i],g[i]);
	reverse(a+1,a+1+n);
	getLR();
	sf[0]=f[0];sg[0]=g[0];
	for(int i=1;i<=n+1;++i)sf[i]=(sf[i-1]+f[i])%p,sg[i]=(sg[i-1]+g[i])%p;
	for(int i=1;i<=n;++i)ans[i]=f[n];
	for(int i=1;i<=n;++i)
	{
		if(L[i])ans[L[i]]=(ans[L[i]]+calc(L_[i]+1,L[i],i,R[i]-1,a[i],a[L[i]]-1))%p;
		if(R[i]<=n)
		{
			ans[R[i]]=(ans[R[i]]+calc(L[i]+1,i,R[i],R_[i]-1,a[i],a[R[i]]-1))%p;
		}
	}
	for(int i=1;i<=n;++i)if(a[i]!=1)ans[i]=(ans[i]+1ll*f[i-1]*g[i+1])%p;
	for(int i=1;i<=n;++i)printf("%d%c",(ans[i]%p+p)%p," \n"[i==n]);
	fclose(stdin);fclose(stdout);return 0;
}
