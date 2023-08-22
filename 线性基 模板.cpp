#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=70;
LL a[N];
bool flag;
bool insert(LL x)
{
    for(int i=63; i>=0; i--)
        if(x&(1ll<<i))
        {
            if(a[i]) x^=a[i];
            else
            {
                a[i]=x;
                return true;
            }
        }
    flag=true;
    return false;
}
LL get_max()
{
    LL res=0;
    for(int i=63; i>=0; i--)
        if((res^a[i])>res)
            res^=a[i];
    return res;
}
LL get_min()
{
    if(flag) return 0;
    for(int i=0; i<=63; i++)
        if(a[i]) return a[i];
}
int main()
{
    int n; cin>>n;
    for(int i=1; i<=n; i++)
    {
        LL x; cin>>x;
        insert(x);
    }
    cout<<get_max()<<endl;
    // cout<<get_min()<<endl;
    return 0;
}
