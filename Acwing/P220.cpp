#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e7+10;
bool st[N];
int primes[N], phi[N], cnt;
LL sum[N], res;
void get_eulers(int n)
{
    phi[1]=1;
    for(int i=2; i<=n; i++)
    {
        if(!st[i])
        {
            primes[cnt++]=i;
            phi[i]=i-1;
        }
        for(int j=0; primes[j]<=n/i; j++)
        {
            st[primes[j]*i]=true;
            if(i%primes[j]==0)
            {
                phi[primes[j]*i]=phi[i]*primes[j];
                break;
            }
            else phi[primes[j]*i]=phi[i]*(primes[j]-1);
        }
    }
}
int main()
{
    int n; cin>>n;
    get_eulers(n);
    for(int i=2; i<=n; i++)
        sum[i]=sum[i-1]+phi[i];
    for(int i=0; i<cnt; i++)
        res+=sum[n/primes[i]]*2+1;
    cout<<res<<endl;
    return 0;
}