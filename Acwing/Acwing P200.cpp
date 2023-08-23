#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 500010, M=2010;
bool st[N];
int primes[N], cnt;
struct Node
{
    int p, s;
}ps[M];
int devide[N], cntd, cntf;
void getPrimes(int n)
{
    for(int i=2; i<=n; i++)
    {
        if(!st[i]) primes[cnt++]=i;
        for(int j=0; primes[j]<=n/i; j++)
        {
            st[primes[j]*i]=true;
            if(i%primes[j]==0) break;
        }
    }
}

int gcd(int a, int b)
{
    return b ? gcd(b, a%b) : a;
}

void dfs(int u, int p)
{
    if(u>cntf)
    {
        devide[++cntd]=p;
        return;
    }
    for(int i=0; i<=ps[u].s; i++)
    {
        dfs(u+1, p);
        p*=ps[u].p;
    }
}

int main()
{
    getPrimes(N-1);
    int n; cin>>n;
    while (n -- )
    {
        int a0, a1, b0, b1;
        cin>>a0>>a1>>b0>>b1;
        int t=b1;
        cntd=cntf=0;
        for(int i=0; primes[i]<=t/primes[i]; i++)
        {
            int p=primes[i];
            if(t%p==0)
            {
                int s=0;
                while(t%p==0) s++, t/=p;
                ps[++cntf]={p, s};
            }
        }
        if(t>1) ps[++cntf]={t, 1};
        dfs(1, 1);
        int res=0;
        for(int i=1; i<=cntd; i++)
        {
            int x=devide[i];
            if(gcd(x, a0)==a1 && (LL)x*b0/gcd(x, b0)==b1)
                res++;
        }
        cout<<res<<endl;
    }
    return 0;
}