// Problem: P3810 【模板】三维偏序（陌上花开）
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3810
// Memory Limit: 500 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

#define cmin(i,j) (i)=min((i),(j))
#define cmax(i,j) (i)=max((i),(j))
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define Fi(s) freopen(s,"r",stdin)
#define Fo(s) freopen(s,"w",stdout)
#define Fre(s) Fi(s".in"),Fo(s".out")
#define all(x) x.begin(), x.end()
#define each(i,x) for(auto &i:(x))
#define fi first
#define se second
#define endl '\n'
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define eb emplace_back

using ll=long long;
using ld=long double;
using pii=pair<int, int>;
using pli=pair<ll, int>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;
constexpr int N=100010, M=N<<1;

int n, m;
int ans[N];

struct Node
{
	int a, b, c;
	int cnt=1, res=0;
	bool operator<(const Node &T)const
	{
		return a!=T.a ? a<T.a : b!=T.b ? b<T.b : c<T.c;
	}
} a[N], tmp[N];

struct Fenwick
{
	int t[M];
	int lowbit(int x) { return x&-x; }
	void add(int k, int x)
	{
		for(int i=k; i<=m; i+=lowbit(i))
			t[i]+=x;
	}
	int query(int k)
	{
		int res=0;
		for(int i=k; i; i-=lowbit(i))
			res+=t[i];
		return res;
	}
} tr;

void merge(int l, int r)
{
	if(l>=r) return;
	int mid=(l+r)>>1, p=l, q=mid+1, len=0;
	merge(l, mid); merge(mid+1, r);
	while(p<=mid && q<=r)
	{
		if(a[p].b<=a[q].b) tr.add(a[p].c, a[p].cnt), tmp[++len]=a[p++];
		else a[q].res+=tr.query(a[q].c), tmp[++len]=a[q++];
	}
	while(p<=mid) tr.add(a[p].c, a[p].cnt), tmp[++len]=a[p++];
	while(q<=r) a[q].res+=tr.query(a[q].c), tmp[++len]=a[q++];
	for(int i=l; i<=mid; i++) tr.add(a[i].c, -a[i].cnt);
	for(int i=1; i<=len; i++) a[l+i-1]=tmp[i];
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		cin>>a[i].a>>a[i].b>>a[i].c;
	sort(a+1, a+n+1);
	int tot=1;
	for(int i=2; i<=n; i++)
	{
		if(a[tot].a==a[i].a && a[tot].b==a[i].b && a[tot].c==a[i].c) a[tot].cnt++;
		else a[++tot]=a[i];
	}
	merge(1, tot);
	for(int i=1; i<=tot; i++)
		ans[a[i].cnt+a[i].res-1]+=a[i].cnt;
	for(int i=0; i<n; i++)
		cout<<ans[i]<<endl;
	return 0;
}
