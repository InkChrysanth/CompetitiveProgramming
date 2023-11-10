// Problem: 自然数拆分
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/281/
// Memory Limit: 64 MB
// Time Limit: 1000 ms

#include <bits/extc++.h>
#define int long long
using namespace std;
const int N = 4010, mod = 2147483648;
int f[N];
signed main()
{
    int n; cin>>n;
    f[0] = 1;
    for (int i = 1; i < n; i ++ )
        for (int j = i; j <= n; j ++ )
            f[j] = (f[j] + f[j - i]) % mod;
    cout<<f[n]<<endl;
    return 0;
}