// Problem: P2391 白雪皑皑
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2391
// Memory Limit: 125 MB
// Time Limit: 1000 ms

// #pragma GCC optimize(2)
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

const int N=1000010;
int n, m, p, q;
int fa[N], col[N];

int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}

signed main()
{
	cin.tie(0); cout.tie(0);
	n=int_rd, m=int_rd, p=int_rd, q=int_rd;
	for(int i=1; i<=n; i++) fa[i]=i;
	for(int i=m; i>=1; i--)
	{
		int l=((i*p+q)%n)+1, r=((i*q+p)%n)+1;
		if(l>r) swap(l, r);
		for(int j=r; j>=l; )
		{
			int ne=find(j);
			if(ne==j) col[j]=i, fa[j]=find(j-1);
			j=fa[j];
		}
	}
	for(int i=1; i<=n; i++) cout<<col[i]<<endl;
	return 0;
}