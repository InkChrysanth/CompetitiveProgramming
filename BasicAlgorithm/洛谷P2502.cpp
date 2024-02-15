#include <bits/stdc++.h>
#define stO int
#define JSY main
#define Orz ()
#define stO_YQY return
#define YQY using
#define AK namespace
#define IOI std;
#define _Orz 0;
#define Let_us_begin {
#define So_bad }
#define F(i,a,b) for(int i=a;i<=b;i++)
#define D(i,a,b) for(int i=a;i>=b;i--)
int scan()
{
	int res=0,flag=0;
	char ch;
	if((ch=getchar())=='-')flag=1;
	else if(ch>='0'&&ch<='9')res=ch-'0';
	while((ch=getchar())>='0'&&ch<='9')res=res*10+(ch-'0');
	return flag?-res:res;
}
void print(int x)
{
	if(x<0)x=~x+1,putchar('-');
	if(x>9)print(x/10);
	putchar(x%10+'0');
}
YQY AK IOI
struct Edge{
	int to,next,from,val;
}edge[5005];
int len=0;
int head[10005];
void add(int u,int v,int val)
{
	len++;
	edge[len].from=u;
	edge[len].to=v;
	edge[len].next=head[u];
	edge[len].val=val;
	head[u]=len;
}
bool cmp(Edge a,Edge b)
{
	return a.val>b.val;
}
int fa[10005];
int vis[10005];
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int u(int x,int y)
{
	x=find(x);y=find(y);
	if(x!=y)fa[x]=y;
}
stO JSY Orz
Let_us_begin
	int n=scan(),m=scan();
	F(i,1,n)fa[i]=i;
	F(i,1,m)
	{
		int x=scan(),y=scan(),v=scan();
		add(x,y,v);
//		add(y,x,v);
		u(x,y);
	}
	int s=scan(),t=scan();
	if(find(s)!=find(t))
	{
		printf("IMPOSSIBLE\n");
		return 0;
	}
	sort(edge+1,edge+m+1,cmp);
	double minn=0x7fffffff;
	int a=0,b=0;
	F(i,1,m)
	{
		F(j,1,n)fa[j]=j;
		F(j,i,m)
		{
			u(edge[j].from,edge[j].to);
			if(find(s)==find(t))
			{
				double tmp=(1.0*edge[i].val)/(1.0*edge[j].val);
				if(tmp<minn)a=edge[i].val,b=edge[j].val,minn=tmp;
				break;
			}
		}
	}
	if(a%b==0)printf("%d\n",a/b);
	else printf("%d/%d\n",a/__gcd(a,b),b/__gcd(a,b));
	stO_YQY _Orz
    So_bad

