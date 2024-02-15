/*
100 7
1 101 1
2 1 2
2 2 3
2 3 3
1 1 3
2 3 1
1 5 5
*/
#include<bits/stdc++.h> 
using namespace std;
int fa[150005];
int n,k,ans;
int find(int x)
{
	if(x!=fa[x]) fa[x]=find(fa[x]);
	return fa[x];
} //查询 
inline int read()
{
	int sum=0;
	char ch=getchar();
	int flag=1;
	while(ch>'9' or ch<'0') {
	    if(ch=='-') flag=-1;
	    ch=getchar();
	    }
	while(ch>='0' && ch<='9') sum=sum*10+ch-48,ch=getchar();
	return flag*sum;
} //读人优化
int unity(int x,int y) 
{
	int r1=find(fa[x]),r2=find(fa[y]);
	fa[r1]=r2;
} //合并 
int main() 
{
	int x,y,z;
	n=read();k=read();
	for(int i=1;i<=3*n;i++) fa[i]=i; //对于每种生物：设 x 为本身，x+n 为猎物，x+2*n 为天敌
	for(int i=1;i<=k;i++)
	{
		z=read(),x=read(),y=read();
		if(x>n||y>n){ // 不属于该食物链显然为假
			ans++;continue;
		}
		if(z==1)
		{
			if(find(x+n)==find(y) || find(x+2*n)==find(y)) {
				ans++;continue; //如果1是2的天敌或猎物，显然为谎言
			}
			unity(x,y);unity(x+n,y+n);unity(x+2*n,y+2*n);
			//如果为真，那么1的同类和2的同类，1的猎物是2的猎物，1的天敌是2的天敌
		}
		else if(z==2)
		{
			if(x==y) { //其实是废话但是可以稍微省点时间
				ans++;continue;
			}
			if(find(x)==find(y)||find(x+2*n)==find(y)){
				ans++;continue; //如果1是2的同类或猎物，显然为谎言
			}
			unity(x,y+2*n);unity(x+n,y);unity(x+2*n,y+n);
			//如果为真，那么1的同类是2的天敌，1的猎物是2的同类，1的天敌是2的猎物
		}
	}
	printf("%d\n",ans);
	return 0;
}
