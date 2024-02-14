// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define int long long
#define int_rd (int)read()
#define ll_rd read()
#define endl '\n'
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

inline ll read()
{
	ll a=0; int f=0; char p=getchar();
	while(!isdigit(p)){f|=p=='-'; p=getchar();}
	while(isdigit(p)){a=(a<<3)+(a<<1)+(p^48); p=getchar();}
	return f?-a:a;
}

const int N=3010, INF=1e18;
int g[N][N], f[N][N];

signed main()
{
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	cin.tie(0); cout.tie(0);
	int n=int_rd, m=int_rd;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
		{
			if(i==j) g[i][j]=0;
			else g[i][j]=INF;
		}
	while(m--)
	{
		int u=int_rd, v=int_rd;
		g[u][v]=g[v][u]=1;
	}
	memcpy(f, g, sizeof g);
	int mn=INF, ans=1;
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<k; i++)
            for(int j=1; j<i; j++)
            	if(f[i][j]+g[i][k]+g[j][k]<mn)
            		mn=f[i][j]+g[i][k]+g[j][k], ans=1;
            	else if(f[i][j]+g[i][k]+g[j][k]==mn) ans++;
        for(int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
                f[i][j]=min(f[i][j], f[i][k]+f[k][j]);
    }
    if(mn==INF) cout<<0<<endl;
    else cout<<ans<<endl;
	return 0;
}