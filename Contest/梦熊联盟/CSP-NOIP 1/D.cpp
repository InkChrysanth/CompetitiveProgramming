#include <bits/stdc++.h>
#define ll long long
#define get(a, b, c) (a*m*n+b*m+c+1)
#define endl '\n'
using namespace std;
int dx[8]={1, 1, 1, 0, 0, -1, -1, -1}, dy[8]={-1, 0, 1, 1, -1, 1, 0, -1};
ll n, m, k, g[25][320010], ans;
char t[220][220];
unsigned ll f[25][320010], hs[25];
map<unsigned ll, int> mp;
signed main()
{
	freopen("genius.in", "r", stdin);
	freopen("genius.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>k;
	k=min(k, n*m/__gcd(n, m));
	ll lg=log2(n*m*8), d=n*m*8;
	for(int i=0; i<n; i++) cin>>t[i];
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			for(int k=0; k<8; k++)
			{
				f[0][get(k, i, j)]=t[i][j]-'a';
				g[0][get(k, i, j)]=get(k, (i+dx[k]+n)%n, (j+dy[k]+m)%m);
			}
	hs[1]=1e10+69;
	for(int i=2; i<=lg; i++) hs[i]=hs[i-1]*hs[i-1];
	for(int i=1; i<=lg; i++)
		for(int j=1; j<=d; j++)
		{
			f[i][j]=f[i-1][j]*hs[i]+f[i-1][g[i-1][j]];
			g[i][j]=g[i-1][g[i-1][j]];
		}
	for(int i=1; i<=d; i++)
	{
		int res=0, x=i;
		for(int j=0; j<=lg; j++)
		{
			if(k&(1<<j))
			{
				res=res*hs[j+1]+f[j][x];
				x=g[j][x];
			}
		}
		ans+=2*mp[res]+1, mp[res]++;
	}
	ll dd=__gcd(ans, d*d);
	cout<<ans/dd<<'/'<<d*d/dd<<endl;
	return 0;
}