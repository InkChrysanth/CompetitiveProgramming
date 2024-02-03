// Problem: F2. Wine Factory (Hard Version)
// Contest: Codeforces - Hello 2024
// URL: https://codeforces.com/contest/1919/problem/F2
// Memory Limit: 512 MB
// Time Limit: 5000 ms

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

const int N=500010, M=750;

ll a[N], b[N], c[N];
int q[N];
int l[M], r[M];
ll bsum[M], w[M], wt[M], contrib[M];

void build(int i)
{
	int L=l[i], R=r[i];
	bsum[i]=w[i]=wt[i]=0, contrib[i]=1e18;
	for(int j=L; j<=R; j++)
	{
		bsum[i]+=b[j];
		w[i]+=min(wt[i]+a[j], b[j]);
		wt[i]=min(c[j], max(0ll, wt[i]+a[j]-b[j]));
		contrib[i]=min(contrib[i], (bsum[i]-w[i])+(c[j]-wt[i]));
	}
}

signed main()
{
	cin.tie(0); cout.tie(0);
	int n=int_rd, t=int_rd;
	for(int i=1; i<=n; i++) a[i]=ll_rd;
	for(int i=1; i<=n; i++) b[i]=ll_rd;
	for(int i=1; i<n; i++) c[i]=ll_rd;
	int T=sqrt(n);
	for(int i=1; i<=n; i++)
	{
		q[i]=(i-1)/T+1;
		if(!l[q[i]]) l[q[i]]=i;
		r[q[i]]=i;
	}
	int B=q[n];
	for(int i=1; i<=B; i++) build(i);
	while(t--)
	{
		int id=int_rd;
		a[id]=ll_rd, b[id]=ll_rd, c[id]=ll_rd;
		build(q[id]);
		ll flow=0, ans=0;
		for(int i=1; i<=B; i++)
		{
			flow=min(flow, contrib[i]);
			ll res=min(flow, bsum[i]-w[i]);
			ans+=res, flow-=res;
			ans+=w[i], flow+=wt[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}