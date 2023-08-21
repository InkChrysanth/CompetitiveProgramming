#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100010, INF = 0x3f3f3f3f;

struct PII{
    int num, val;
    bool operator< (const PII &W)const{
        return num < W.num;
    }
}a[N];

int n, sum[N];
int findl(int x)                    //找到大于等于x的最小值
{
    int l = 1, r = n + 1;
    while(l < r)
    {
        int mid = l + r >> 1;
        if(a[mid].num >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

int findr(int x)                    //找到小于等于x的最大值
{
    int l = 0, r = n;
    while(l < r)
    {
        int mid = l + r + 1 >> 1;
        if(a[mid].num <= x)
            l = mid;
        else
            r = mid - 1;
    }
    return l;
}

int main()
{
    int m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++)  scanf("%d%d", &a[i].num, &a[i].val);

    sort(a + 1, a + n + 1);

    int j = 1;
    for(int i = 2; i <= n; i ++) //去重 
        if(a[i].num > a[i - 1].num)
            a[++ j] = a[i];
        else
            a[j].val += a[i].val;
    n = j;
    a[0].num = -INF, a[n + 1].num = INF;            //加两个极值点方便二分
    //for(int i = 1; i <= n; i ++)  printf("%d %d %d\n", i, a[i].num, a[i].val);

    for(int i = 1; i <= n; i ++)  sum[i] = sum[i - 1] + a[i].val;

    while(m --)
    {
        int l, r;
        scanf("%d%d", &l, &r);

        l = findl(l), r = findr(r);
        printf("%d\n", sum[r] - sum[l - 1]);
    }
    return 0;
}

