#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int exgcd(int a, int b, LL &x, LL &y)
{
    if(b==0)
    {
        x=1, y=0;
        return a;
    }
    int d=exgcd(b, a%b, y, x);
    y-=a/b*x;
    return d;
}
int main()
{
    int a, b, m, n, l;
    LL x=0, y=0;
    cin>>a>>b>>m>>n>>l;
    int d=exgcd(m-n, l, x, y);
    if((b-a)%d) puts("Impossible");
    else
    {
        x*=(b-a)/d;
        LL t=abs(l/d);
        cout<<(x%t+t)%t;
    }
    return 0;
}