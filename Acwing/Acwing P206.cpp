#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=70, M=20;
int n, m, t, act, p;
int id[M][M];
char s[M], g[M][M];
int a[N][N][N], f[N], d[N][N];
int o[N][N];
int get(int i, int j)
{
    return (i-1)*m+j;
}
void mul(int a[N][N], int b[N][N])
{
    int c[N][N]={0};
    for(int i=0; i<=p; i++)
        for(int j=0; j<=p; j++)
            for(int k=0; k<=p; k++)
                c[i][j]+=a[i][k]*b[k][j];
    memcpy(a, c, sizeof c);
}
void _mul(int a[N], int b[N][N])
{
    int c[N]={0};
    for(int j=0; j<=p; j++)
        for(int k=0; k<=p; k++)
            c[j]+=a[k]*b[k][j];
    memcpy(a, c, sizeof c);
}
void init()
{
    for(int t=1; t<=60; t++)
    {
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
            {
                int x=id[i][j], y=o[i][j];
                if(g[x][y]>='0' && g[x][y]<='9')
                {
                    a[t][0][get(i, j)]=g[x][y]-'0';
                    a[t][get(i, j)][get(i, j)]=1;
                }
                else if(g[x][y]=='N' && i>1) a[t][get(i, j)][get(i-1, j)]=1;
                else if(g[x][y]=='W' && j>1) a[t][get(i, j)][get(i, j-1)]=1;
                else if(g[x][y]=='S' && i<n) a[t][get(i, j)][get(i+1, j)]=1;
                else if(g[x][y]=='E' && j<m) a[t][get(i, j)][get(i, j+1)]=1;
                o[i][j]=(y+1)%strlen(g[x]);
            }
        a[t][0][0]=1;
    }
    memcpy(d, a[1], sizeof a[1]);
    for(int i=2; i<=60; i++)
        mul(d, a[i]);
}
signed main()
{
	cin>>n>>m>>t>>act;
    for(int i=1; i<=n; i++)
    {
        cin>>s+1;
        for(int j=1; j<=m; j++)
            id[i][j]=s[j]-'0';
    }
    for(int i=0; i<act; i++)
        cin>>g[i];
    p=n*m;
    init();
    int res=0;
    f[0]=1;
    int k=t/60;
    while(k)
    {
        if(k&1) _mul(f, d);
        mul(d, d);
        k>>=1;
    }
    int r=t%60;
    for(int i=1; i<=r; i++) _mul(f, a[i]);
    for(int i=1; i<=p; i++) res=max(res, f[i]);
    cout<<res<<endl;
    return 0;
}