#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1000010, p=998244353;
LL n, pw[N], a[N], c[N], ans;
int lowbit(int x)
{
    return x&-x;
}
void modify(int x, int k)
{
    for(int i=x; i<=n; i+=lowbit(i))
        c[i]=(c[i]+k)%p;
}
int query(int x)
{
    int ans=0;
    for(int i=x; i>=1; i-=lowbit(i))
        ans=(ans+c[i])%p;
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    cin>>n;
    pw[0]=1;
    for(int i=1; i<=n; i++) pw[i]=pw[i-1]*i%p;
    for(int i=1; i<=n; i++) cin>>a[i], modify(a[i], 1);
    for(int i=1; i<=n; i++)
    {
        modify(a[i], -1);
        ans=(ans+query(a[i])*pw[n-i]%p)%p;
    }
    cout<<ans+1<<endl;
    return 0;
}