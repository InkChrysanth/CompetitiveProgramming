#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL gcd(LL a, LL b)
{
    return b ? gcd(b, a%b) : a;
}
LL qmul(LL a, LL k, LL b)
{
    LL res = 0;
    while (k)
    {
        if (k & 1) res = (res + a) % b;
        a = (a + a) % b;
        k >>= 1;
    }
    return res;
}

LL qmi(LL a, LL k, LL b)
{
    LL res = 1;
    while (k)
    {
        if (k & 1) res = qmul(res, a, b);
        a = qmul(a, a, b);
        k >>= 1;
    }
    return res;
}
int main()
{
    LL l, idx=0;
    while(cin>>l, l)
    {
        idx++;
        LL d=gcd(l, 8);
        LL x=9*l/d;
        if(x%2==0 || x%5==0)
        {
            printf("Case %lld: 0\n", idx);
            continue;
        }
        LL res=x, y=x;
        for(int i=2; i<=x/i; i++)
        {
            if(x%i==0)
            {
                res=res/i*(i-1);
                while(x%i==0) x/=i;
            }
        }
        if(x>1) res=res/x*(x-1);
        LL ans=1e18;
        for(LL i=1; i<=res/i; i++)
        {
            if(res%i) continue;
            if(qmi(10, i, y)==1) ans=min(ans, i);
            if(qmi(10, res/i, y)==1) ans=min(ans, res/i);
        }
        printf("Case %lld: %lld\n", idx, ans);
    }
    return 0;
}