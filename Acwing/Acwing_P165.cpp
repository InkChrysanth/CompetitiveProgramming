#include <bits/stdc++.h>
using namespace std;
const int N=20;
int n, m, ans=N;
int sum[N], w[N];
void dfs(int u, int k)
{
    if(k>ans) return;
    if(u==n)
    {
        ans=k;
        return;
    }
    for(int i=0; i<k; i++)
        if(w[u]+sum[i]<=m)
        {
            sum[i]+=w[u];
            dfs(u+1, k);
            sum[i]-=w[u];
        }
    sum[k]=w[u];
    dfs(u+1, k+1);
    sum[k]=0;
}
int main()
{
    cin>>n>>m;
    for(int i=0; i<n; i++)
        cin>>w[i];
    sort(w, w+n, greater<int>());
    dfs(0, 0);
    cout<<ans<<endl;
    return 0;
}