#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=100003;
int qmi(int a, int k)
{
    int res=1;
    while(k)
    {
        if(k&1) res=res*a%MOD;
        a=a*a%MOD;
        k>>=1;
    }
    return res;
}
signed main()
{
    int m, n; cin>>m>>n;
    cout<<((qmi(m, n)-qmi(m-1, n-1)*m)%MOD+MOD)%MOD;
    return 0;
}