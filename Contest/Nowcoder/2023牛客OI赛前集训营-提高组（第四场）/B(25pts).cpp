// Problem: 任务
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/65195/B
// Memory Limit: 1048576 KB
// Time Limit: 6000 ms

#include <bits/stdc++.h>
#define int_rd (int)read()
#define ll_rd read()
#define endl '\n'
#define mp make_pair
#define int long long

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

const int N=2010, MOD=998244353;
string s;
int n, q;
int tr[N*2];
int c[N][N];
int sz[N];
void init()
{
	c[0][0]=1;
	for(int i=1; i<=1000; i++)
		for(int j=0; j<=1000; j++)
		{
			if(!j) c[i][j]=26*c[i-1][j]%MOD;
			else c[i][j]=(25*c[i-1][j]+c[i-1][j-1])%MOD;
		}
}
void pushup(int u)
{
	tr[u]=tr[u<<1]*tr[u<<1|1]%MOD;
}
void build(int l, int r, int u)
{
	if(l==r)
	{
		tr[u]=c[int_rd][sz[l]];
		return;
	}
	int mid=(l+r)>>1;
	build(l, mid, u<<1); build(mid+1, r, u<<1|1);
	pushup(u);
}

void modify(int l, int r, int u, int pos, int val)
{
	if(l==r && l==pos)
	{
		tr[u]=c[val][sz[pos]];
		return;
	}
	int mid=(l+r)>>1;
	if(pos<=mid) modify(l, mid, u<<1, pos, val);
	if(pos>mid) modify(mid+1, r, u<<1|1, pos, val);
	pushup(u); 
}

int query(int ql, int qr, int l, int r, int u)
{
	if(ql<=l && qr>=r) return tr[u]; 
    int res=1;
    int mid=(l+r)>>1;
    if(ql<=mid) res=(res*query(ql, qr, l, mid, u<<1))%MOD; 
    if(qr>mid) res=(res*query(ql, qr, mid+1, r, u<<1|1))%MOD; 
    return res; 
}

signed main()
{
	cin.tie(0); cout.tie(0);
	n=int_rd, q=int_rd; init();
	for(int i=1; i<=n; i++) cin>>s, sz[i]=s.size();
	build(1, n, 1);
	while(q--)
	{
		int op=int_rd, x=int_rd, y=int_rd;
		if(op==0) modify(1, n, 1, x, y);
		else cout<<query(x, y, 1, n, 1)<<endl;
	}
	return 0;
}