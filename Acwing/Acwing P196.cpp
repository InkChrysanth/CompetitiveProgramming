#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1000010;
bool st[N];
int primes[N], cnt;
void Init(int n)
{
    memset(st, false, sizeof st);
    cnt=0;
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
    int l, r;
    while(cin>>l>>r)
    {
        Init(50000);
        memset(st, false, sizeof st);
        for(int i=0; i<cnt; i++)
        {
            LL p=primes[i];
            for(LL j=max(2*p, (l+p-1)/p*p); j<=r; j+=p)
                st[j-l]=true;
        }
        cnt=0;
        for(int i=0; i<=r-l; i++)
            if(!st[i] && i+l>=2)
                primes[cnt++]=i+l;
        if(cnt<2) puts("There are no adjacent primes.");
        else
        {
            int minp=0, maxp=0;
            for(int i=0; i+1<cnt; i++)
            {
                int d=primes[i+1]-primes[i];
                if(d<primes[minp+1]-primes[minp]) minp=i;
                if(d>primes[maxp+1]-primes[maxp]) maxp=i;
            }
            printf("%d,%d are closest, %d,%d are most distant.\n", primes[minp], primes[minp+1], primes[maxp], primes[maxp+1]);
        }
    }
    return 0;
}