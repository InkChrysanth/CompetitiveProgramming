#include<bits/stdc++.h>
using namespace std;
long long inv[3000001];
int n, p;
int main()
{
    inv[1]=1;
    cout<<1<<endl;
    cin>>n>>p;
    for(int i=2; i<=n; i++)
    {
        inv[i]=(p-p/i)*inv[p%i]%p;
        printf("%lld\n",inv[i]);
    }
    return 0;
}