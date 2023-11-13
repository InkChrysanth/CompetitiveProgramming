// Problem: Remainder Problem
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1207F
// Memory Limit: 500 MB
// Time Limit: 4000 ms

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

const int N=500010, M=710;
int a[N], sum[M][M];
signed main()
{
	cin.tie(0); cout.tie(0);
	int q=int_rd, n=sqrt(N);
	while(q--)
	{
		int op=int_rd, x=int_rd, y=int_rd;
		if(op==1)
		{
			for(int i=1; i<=n; i++)
				sum[i][x%i]+=y;
			a[x]+=y;
		}
		else
		{
			if(x<=n) cout<<sum[x][y]<<endl;
			else
			{
				int ans=0;
				for(int i=y; i<=N; i+=x)
					ans+=a[i];
				cout<<ans<<endl;
			}
		}
	}
	return 0;
}