#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
int primes[]={2, 3, 5, 7, 11, 13, 17, 19, 23};
int maxd, num;
void dfs(int u, int last, int p, int s)
{
    if(s>maxd || (s==maxd && num>p))
        maxd=s, num=p;
    if(u==9) return;
    for(int i=1; i<=last; i++)
    {
        if((LL)p*primes[u]>n) break;
        p*=primes[u];
        dfs(u+1, i, p, s*(i+1));
    }
}
int main()
{
    cin>>n;
    dfs(0, 30, 1, 1);
    cout<<num<<endl;
    return 0;
}
    cin>>n;
    dfs(0, 30, 1, 1);
    cout<<num<<endl;
    return 0;
}