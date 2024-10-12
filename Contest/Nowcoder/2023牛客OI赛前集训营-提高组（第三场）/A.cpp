#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=100010;
bool cmp(int a, int b)
{
    return abs(a)>abs(b);
}
int n, m;
int a[N];
vector<int> b;
signed main()
{
    cin>>n>>m;
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a, a+n, cmp);
    for(int i=0; i<m; i++)
    {
        int x; cin>>x;
        b.push_back(x);
    }
    sort(b.begin(), b.end());
    int ans=0, st=0, ed=0;
    for(int i=0; i<n; i++)
    {
        if(a[i]<0)
            ans+=b[st++]*a[i];
        else
            ans+=b[m-(ed++)-1]*a[i];
    }
    cout<<ans<<endl;
    return 0;
}