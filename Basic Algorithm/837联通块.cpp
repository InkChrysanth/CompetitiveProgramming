#include<iostream>
using namespace std;
const int N=1e5+10;
//siz[N]指的是以N为根节点的所在连通块中点的数量
int f[N],siz[N];
int find(int x)//寻找x的根节点+路径压缩
{
    if(f[x]!=x) f[x]=find(f[x]);
    return f[x];
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        f[i]=i;
        siz[i]=1;
    }
    while(m--)
    {
        char a[3];
        int b,c;
        scanf("%s",a);
        if(a[1]=='1')//判断a和b是否在同一个连通块中
        {
            scanf("%d%d",&b,&c);
            //如果b和c所在集合为同一集合,则返回ture 否则返回No
            if(find(b)==find(c)) printf("Yes\n");
            else printf("No\n");
        }
        else if(a[1]=='2')//返回b所在连通块的点的个数
        {
            scanf("%d",&b);
            printf("%d\n",siz[find(b)]);
        }
        else
        {
            scanf("%d%d",&b,&c);
            if(find(b)!=find(c))//如果b和c所在连通块不相等,则进行合并
            {
                /*当c和b两个所在连通块合并时,新合并的连通块的
                根节点为b的根节点
                */
                //更新合并后的连通块的点的个数
                siz[find(c)]+=siz[find(b)];
                //合并连通块
                f[find(b)]=find(c);
            }
        }
    }
}

