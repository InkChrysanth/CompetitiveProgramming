#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL gcd(LL a, LL b){return b ? gcd(b, a%b) : a;}
LL C(int n){return (LL)n*(n-1)*(n-2)/6;}
int main()
{
    int m, n; cin>>m>>n; m++, n++;
    LL res=C(m*n)-n*C(m)-m*C(n);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            res-=2*(gcd(i, j)-1)*(n-i)*(m-j);
    cout<<res<<endl;
    return 0;
}