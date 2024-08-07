// Problem: P4735 最大异或和
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4735
// Memory Limit: 512 MB
// Time Limit: 1500 ms
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
constexpr int N=600010, M=N<<5, K=25;

int n, m;
int root[N], tot;
int tr[M][2], last[M];
int s[N];

void insert(int pre, int cur, int i, int k)
{
	if(k<0)
	{
		last[cur]=i;
		return;
	}
	int to=(s[i]>>k)&1;
	if(pre) tr[cur][to^1]=tr[pre][to^1];
	tr[cur][to]=++tot;
	insert(tr[pre][to], tr[cur][to], i, k-1);
	last[cur]=i;
}

int query(int cur, int x, int l)
{
	int p=cur;
	for(int i=K; i>=0; i--)
	{
		int to=(x>>i)&1;
		if(last[tr[p][to^1]]>=l) p=tr[p][to^1];
		else p=tr[p][to];
	}	
	return x^s[last[p]];
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	root[0]=++tot, last[0]=-1;
	insert(0, root[0], 0, K);
	for(int i=1, x; i<=n; i++)
	{
		cin>>x;
		s[i]=s[i-1]^x;
		root[i]=++tot;
		insert(root[i-1], root[i], i, K);
	}
	for(int i=1, l, r, x; i<=m; i++)
	{
		char opt;
		cin>>opt;
		if(opt=='A')
		{
			cin>>x;
			n++;
			s[n]=s[n-1]^x;
			root[n]=++tot;
			insert(root[n-1], root[n], n, K);
		}
		else 
		{
			cin>>l>>r>>x;
			cout<<query(root[r-1], s[n]^x, l-1)<<endl;
		}
	}
	return 0;
}
