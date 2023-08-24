#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1000010, P=998244353;
int n;
int pw[N], a[N];
void init()
{
    pw[0]=pw[1]=1;
    for(int i=1; i<N; i++)
        pw[i]=(LL)i*pw[i-1]%P;
}
int solve()
{
    int ans=1;
    for(int i=1; i<=n; i++)
    {
        int cnt=0;
        for(int j=i+1; j<=n; j++)
            if(a[j]<a[i])
                cnt++;
        ans=(ans+(LL)cnt*pw[n-i]%P)%P;
    }
    return ans%P;
}
int main()
{
    cin>>n;
    init();
    for(int i=1; i<=n; i++)
        cin>>a[i];
    cout<<solve()<<endl;
    return 0;
}