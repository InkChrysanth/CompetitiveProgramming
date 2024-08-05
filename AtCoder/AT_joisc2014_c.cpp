// Problem: 歴史の研究
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/AT_joisc2014_c
// Memory Limit: 512 MB
// Time Limit: 4000 ms
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
constexpr int N=100010, K=510;

int n, m;
int a[N], aa[N], f[N], pos[N];
int lb[K], rb[K], T, tot;
int cnt[N], _cnt[N];
ll ans[N];

struct Node
{
	int l, r, id;
	bool operator<(const Node &T)const
	{ return pos[l]==pos[T.l] ? r<T.r : pos[l]<pos[T.l]; }
}q[N];

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	T=sqrt(n);
	while(++tot)
	{
		lb[tot]=rb[tot-1]+1;
		rb[tot]=min(T*tot, n);
		for(int i=lb[tot]; i<=rb[tot]; i++)
			pos[i]=tot;
		if(rb[tot]==n) break;	
	}
	for(int i=1; i<=n; i++) 
		cin>>a[i], f[i]=a[i];
	sort(f+1, f+n+1);
	int _n=unique(f+1, f+n+1)-f-1;
	for(int i=1; i<=n; i++)
		aa[i]=lower_bound(f+1, f+_n+1, a[i])-f;
	for(int i=1; i<=m; i++)
		cin>>q[i].l>>q[i].r, q[i].id=i;;
	sort(q+1, q+m+1);
	for(int i=1; i<=m; )
	{
		for(int k=1; k<=tot; k++)
		{
			memset(cnt, 0, sizeof cnt);
			ll res=0;
			int l=rb[k]+1, r=rb[k];
			for(; pos[q[i].l]==k; i++)
			{	
				int ql=q[i].l, qr=q[i].r; ll tmp;
				if(pos[ql]==pos[qr])
				{
					tmp=0;
					for(int j=ql; j<=qr; j++) _cnt[aa[j]]=0;
					for(int j=ql; j<=qr; j++) _cnt[aa[j]]++, cmax(tmp, 1ll*_cnt[aa[j]]*a[j]);
					ans[q[i].id]=tmp;
					continue;
				}
				while(r<qr)	
				{
					r++;
					cnt[aa[r]]++;
					cmax(res, 1ll*cnt[aa[r]]*a[r]);
				}
				tmp=res;
				while(l>ql)
				{
					l--;
					cnt[aa[l]]++;
					cmax(res, 1ll*cnt[aa[l]]*a[l]);
				}
				ans[q[i].id]=res;
				while(l<rb[k]+1) cnt[aa[l]]--, l++;
				res=tmp;
			}
		}
	}
	for(int i=1; i<=m; i++) cout<<ans[i]<<endl;
	return 0;
}
