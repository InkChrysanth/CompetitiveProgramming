// Problem: P3755 [CQOI2017] 老C的任务
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3755
// Memory Limit: 512 MB
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
constexpr int N=100010, M=500010;

int n, m;
struct Node
{
	ll x, y, p;
	bool type=0;
	ll res=0;
	bool operator<(const Node &T)const { return x!=T.x ? x<T.x : y!=T.y ? y<T.y : type<T.type; };
} a[M], tmp[M];
struct Query{ ll x1, y1, x2, y2; }q[N];

void merge(int l, int r)
{
	if(l>=r) return;
	int mid=(l+r)>>1;
	merge(l, mid), merge(mid+1, r);
	int p=l, q=mid+1, len=0;
	ll sum=0;
	while(p<=mid && q<=r)
	{
		if(a[p].y<=a[q].y)
		{
			if(!a[p].type) sum+=a[p].p;
			tmp[++len]=a[p++];
		} 
		else
		{
			if(a[q].type) a[q].res+=sum;
			tmp[++len]=a[q++];
		}
	}
	while(p<=mid)
	{
		if(!a[p].type) sum+=a[p].p;
		tmp[++len]=a[p++];
	}
	while(q<=r)
	{
		if(a[q].type) a[q].res+=sum;
		tmp[++len]=a[q++];
	}
	for(int i=1; i<=len; i++) a[l+i-1]=tmp[i];
}

map<ll, map<ll, ll>> res;

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		cin>>a[i].x>>a[i].y>>a[i].p;
	int tot=n;
	for(int i=1; i<=m; i++)
	{
		ll x1, y1, x2, y2;
		cin>>x1>>y1>>x2>>y2;
		a[++tot]={x1-1, y1-1, 0, 1, 0};
		a[++tot]={x2, y2, 0, 1, 0};
		a[++tot]={x1-1, y2, 0, 1, 0};
		a[++tot]={x2, y1-1, 0, 1, 0};
		q[i]={x1, y1, x2, y2};
	}
	sort(a+1, a+tot+1);
	merge(1, tot);
	for(int i=1; i<=tot; i++)
		if(a[i].type)
			res[a[i].x][a[i].y]=a[i].res;
	for(int i=1; i<=m; i++)
	{
		ll &x1=q[i].x1, &y1=q[i].y1, &x2=q[i].x2, &y2=q[i].y2;
		cout<<res[x2][y2]+res[x1-1][y1-1]-res[x1-1][y2]-res[x2][y1-1]<<endl;
	}
	return 0;
}
