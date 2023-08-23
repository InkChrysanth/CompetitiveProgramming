#include <bits/stdc++.h>
using namespace std;
const int N=1010;
bool st[N];
int primes[N], phi[N], cnt;
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
    get_eulers(N);
    int t; cin>>t;
    for(int i=1; i<=t; i++)
    {
        int n; cin>>n;
        int res=1;
        for(int i=1; i<=n; i++)
            res+=phi[i]*2;
        cout<<i<<' '<<n<<' '<<res<<endl;
    }
    return 0;
}