// Problem: P3865 【模板】ST 表
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3865
// Memory Limit: 125 MB
// Time Limit: 800 ms

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

const int N=100010;

int n, m;
int st[N][20];

int query(int l, int r)
{
	int k=log2(r-l+1);
	return max(st[l][k], st[r-(1<<k)+1][k]);
}

signed main()
{
	cin.tie(0); cout.tie(0);
	n=int_rd, m=int_rd;
	for(int i=1; i<=n; i++)
		st[i][0]=int_rd;
	for(int k=1; k<=21; k++)
		for(int i=1; i+(1<<k)-1<=n; i++)
			st[i][k]=max(st[i][k-1], st[i+(1<<(k-1))][k-1]);
	while(m--)
	{
		int l=int_rd, r=int_rd;
		cout<<query(l, r)<<endl;
	}
	return 0;
}