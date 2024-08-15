#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2000010;
bool st[N];
int primes[N], s[N], cnt;
int n, p;
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
int get(int n, int p)
{
    int res=0;
    while(n)
    {
        res+=n/p;
        n/=p;
    }
    return res;
}
int qmi(int a, int k, int p)
{
    int res=1;
    while(k)
    {
        if(k&1) res=(LL)res*a%p;
        a=(LL)a*a%p;
        k>>=1;
    }
    return res;
}
int main()
{
    getPrimes(N-1);
    cin>>n>>p;
    int C1=1, C2=1;
    for(int i=0; i<cnt; i++)
    {
        int S=get(2*n, primes[i])-get(n, primes[i])-get(n, primes[i]);
        C1=(LL)C1*qmi(primes[i], S, p)%p;
    }
    for(int i=0; i<cnt; i++)
    {
        int S=get(2*n, primes[i])-get(n+1, primes[i])-get(n-1, primes[i]);
        C2=(LL)C2*qmi(primes[i], S, p)%p;
    }
    cout<<(LL)(C1-C2+p)%p<<endl;
    return 0;
}