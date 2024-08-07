// Problem: P1533 可怜的狗狗
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1533
// Memory Limit: 125 MB
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
constexpr int N=300010, M=N<<5;

int n, m, tot;
int a[N], f[N];
int root[N];
struct Node{ int l, r, cnt; } tr[M];

void build(int &u, int l, int r)
{
	u=++tot;
	if(l==r) return;	
	int mid=(l+r)>>1;
	build(tr[u].l, l, mid);
	build(tr[u].r, mid+1, r);
}

void modify(int &u, int ver, int l, int r, int val)
{
	u=++tot;
	tr[u]=tr[ver];
	tr[u].cnt++;
	if(l==r) return;
	int mid=(l+r)>>1;
	if(mid>=val) modify(tr[u].l, tr[ver].l, l, mid, val);
	else modify(tr[u].r, tr[ver].r, mid+1, r, val);
}

int query(int p, int q, int l, int r, int k)
{
	int cnt=tr[tr[q].l].cnt-tr[tr[p].l].cnt;
	if(l==r) return f[l];
	int mid=(l+r)>>1;
	if(k<=cnt) return query(tr[p].l, tr[q].l, l, mid, k);
	return query(tr[p].r, tr[q].r, mid+1, r, k-cnt);
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i], f[i]=a[i];
	sort(f+1, f+n+1);
	int _n=unique(f+1, f+n+1)-f-1;
	for(int i=1; i<=n; i++)
		a[i]=lower_bound(f+1, f+_n+1, a[i])-f;
	build(root[0], 1, _n);
	for(int i=1; i<=n; i++)
		modify(root[i], root[i-1], 1, _n, a[i]);
	for(int i=1, l, r, k; i<=m; i++)
	{
		cin>>l>>r>>k;
		cout<<query(root[l-1], root[r], 1, _n, k)<<endl;
	}
	return 0;
}
