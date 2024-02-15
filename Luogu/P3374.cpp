// Problem: P3374 【模板】树状数组 1
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3374
// Memory Limit: 512 MB
// Time Limit: 1000 ms

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

const int N=500010;

int n, m;
int tr[N];

int lowbit(int x){return x&-x;}

void add(int x, int c)
{
	for(int i=x; i<=n; i+=lowbit(i))
		tr[i]+=c;
}

int query(int x)
{
	int res=0;
	for(int i=x; i; i-=lowbit(i))
		res+=tr[i];
	return res;
}

signed main()
{
	cin.tie(0); cout.tie(0);
	n=int_rd, m=int_rd;
	for(int i=1; i<=n; i++)
	{
		int x=int_rd;
		add(i, x);
	}
	for(int i=1; i<=m; i++)
	{
		int op=int_rd, x=int_rd, y=int_rd;
		if(op==1) add(x, y);
		if(op==2) cout<<query(y)-query(x-1)<<endl;
	}
	return 0;
}