// Problem: Array Queries
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF797E
// Memory Limit: 250 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>
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
const int N=100010, M=410;
int n, m, T;
int a[N];
int f[N][M];

signed main()
{
	cin.tie(0); cout.tie(0);
	n=int_rd, T=sqrt(N);
	for(int i=1; i<=n; i++) a[i]=int_rd;
	for(int i=n; i>=1; i--)
		for(int j=1; j<=T; j++)
			f[i][j]= i+a[i]+j>n ? 1 : f[i+a[i]+j][j]+1;
	m=int_rd;
	for(int i=1; i<=m; i++)
	{
		int p=int_rd, k=int_rd;
		if(k>T)
		{
			int cnt=0;
			while(p<=n)
			{
				cnt++;
				p=p+a[p]+k;
			}
			cout<<cnt<<endl;
		}
		else cout<<f[p][k]<<endl;
		
	}
	return 0;
}