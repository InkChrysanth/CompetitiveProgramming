// Problem: 磁力块
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/description/252/
// Memory Limit: 64 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
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
constexpr int N=250010, K=510;

int n, tot, T;
ll x_0, y_0, p0, r0;
int lb[K], rb[K];
ll md[K];
bool vis[N];

struct Node{ ll d, m, p, r; }a[N];

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin>>x_0>>y_0>>a[0].p>>a[0].r>>n;
	a[0].r*=a[0].r;
	T=2*sqrt(n); cmin(T, n);
	for(int i=1, x, y; i<=n; i++)
	{
		cin>>x>>y;
		a[i].d=(x-x_0)*(x-x_0)+(y-y_0)*(y-y_0);
		cin>>a[i].m>>a[i].p>>a[i].r;
		a[i].r*=a[i].r;
	}
	sort(a+1, a+n+1, [&](Node x, Node y){ return x.d<y.d; });
	while(++tot)
	{
		lb[tot]=rb[tot-1]+1;
		rb[tot]=min(T*tot, n);
		md[tot]=a[rb[tot]].d;
		sort(a+lb[tot], a+rb[tot]+1, [&](Node x, Node y){ return x.m<y.m; });
		if(rb[tot]==n) break;
	}
	int ans=0;
	queue<int> q;
	q.push(0); vis[0]=1;
	while(q.size())
	{
		int t=q.front(); q.pop();
		ll p=a[t].p, r=a[t].r;
		for(int i=1; i<=tot; i++)
		{
			if(md[i]>r)
			{
				for(int j=lb[i]; j<=rb[i]; j++)
				{
					if(!vis[j] && a[j].d<=r && a[j].m<=p)
						q.push(j), vis[j]=1, ans++;
					else if(a[j].d>r && a[j].m>p) break;
				}
				break;
			}
			else
			{
				for(int j=lb[i]; j<=rb[i]; j++)
				{
					if(!vis[j] && a[j].m<=p)
						q.push(j), vis[j]=1, ans++;
					else if(a[j].m>p) break;
					lb[i]++;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
