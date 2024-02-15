// Problem: B - 上帝造题的七分钟
// Contest: Virtual Judge - 基础算法二
// URL: https://vjudge.net/contest/598949#problem/B
// Memory Limit: 131 MB
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

const int N=2050;
int n, m;
int a, b, c, d, k;
char ch, op;
int tr1[N][N], tr2[N][N], tr3[N][N], tr4[N][N];

int lowbit(int x){return x&-x;}
void add(int x, int y, int k)
{
	for(int i=x; i<=n; i+=lowbit(i))
		for(int j=y; j<=m; j+=lowbit(j))
		{
			tr1[i][j]+=k;
			tr2[i][j]+=k*(x-1);
			tr3[i][j]+=k*(y-1);
			tr4[i][j]+=k*(x-1)*(y-1);	
		}
}

void modify(int a, int b, int c, int d, int k)
{
	add(a, b, k);
	add(c+1, b, -k);
	add(a, d+1, -k);
	add(c+1, d+1, k);
}

int query(int x, int y)
{
	int r1=0, r2=0, r3=0, r4=0;
	for(int i=x; i; i-=lowbit(i))
		for(int j=y; j; j-=lowbit(j))
		{
			r1+=tr1[i][j];
			r2+=tr2[i][j];
			r3+=tr3[i][j];
			r4+=tr4[i][j];
		}
	r1*=x*y;
	return r1-r2*y-r3*x+r4;
}

signed main()
{
	cin.tie(0); cout.tie(0);
	cin>>ch>>n>>m;
	while(cin>>op && op)
	{
		if(op=='L')
		{
			a=int_rd, b=int_rd, c=int_rd, d=int_rd, k=int_rd;
			modify(a, b, c, d, k);
		}
		else if(op=='k')
		{
			a=int_rd, b=int_rd, c=int_rd, d=int_rd;
			cout<<query(c, d)-query(c, b-1)-query(a-1, d)+query(a-1, b-1)<<endl;
		}
	}
	return 0;
}