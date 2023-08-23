#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
bool st[N];
int primes[N], cnt;
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
int main()
{
    int n; cin>>n;
    getPrimes(n);
    for(int i=0; i<cnt; i++)
    {
        int p=primes[i];
        int s=0;
        for(int j=n; j; j/=p)
            s+=j/p;
        cout<<p<<" "<<s<<endl;
    }
    return 0;
}