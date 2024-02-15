#include <bits/stdc++.h>
using namespace std;
const int N=15;
int n, q[N], w[5][N];
int est()
{
    int tot=0;
    for(int i=0; i<n-1; i++)
        if(q[i+1]!=q[i]+1)
            tot++;
    return (tot+2)/3;
}
bool dfs(int u, int lm)
{
    if(u+est()>lm) return false;
    if(est()==0) return true;
    for(int len=1; len<=n; len++)
        for(int l=0; l+len-1<n; l++)
        {
            int r=l+len-1;
            for(int k=r+1; k<n; k++)
            {
                memcpy(w[u], q, sizeof q);
                int y=l;
                for(int x=r+1; x<=k; x++, y++) q[y]=w[u][x];
                for(int x=l; x<=r; x++, y++) q[y]=w[u][x];
                if(dfs(u+1, lm)) return true;
                memcpy(q, w[u], sizeof q);
            }
        }
    return false;
}
int main()
{
    int T; cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=0; i<n; i++) cin>>q[i];
        int cnt=0;
        while(cnt<5 && !dfs(0, cnt)) cnt++;
        if(cnt>=5) puts("5 or more");
        else cout<<cnt<<endl;
    }
    return 0;
}
