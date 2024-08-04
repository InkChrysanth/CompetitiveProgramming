// Problem: P5357 【模板】AC 自动机
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P5357
// Memory Limit: 250 MB
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
constexpr int N=200010;

int tr[N][26], tot;
int fail[N], cnt[N];
int e[N];
vector<int> g[N];

void insert(string str, int idx)
{
	int u=0;
	each(v, str)
	{
		v-='a';
		if(!tr[u][v]) tr[u][v]=++tot;
		u=tr[u][v];
	}
	e[idx]=u;
}

void build()
{
	queue<int> q;
	for(int i=0; i<26; i++)
		if(tr[0][i]) q.push(tr[0][i]);
	while(q.size())
	{
		int u=q.front(); q.pop();
		for(int i=0; i<26; i++)
		{
			if(tr[u][i]) fail[tr[u][i]]=tr[fail[u]][i], q.push(tr[u][i]);
			else tr[u][i]=tr[fail[u]][i];
		}
	}
}

void query(string str)
{
	int u=0;
	each(v, str)
	{
		v-='a';
		u=tr[u][v];
		cnt[u]++;
	}
}

void dfs(int u)
{
	each(v, g[u])
	{
		dfs(v);
		cnt[u]+=cnt[v];
	}
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin>>n;
	string t, p;
	for(int i=1; i<=n; i++)
		cin>>p, insert(p, i);
	build();
	for(int i=1; i<=tot; i++)
		g[fail[i]].eb(i);
	cin>>t;
	query(t);
	dfs(0);
	for(int i=1; i<=n; i++)
		cout<<cnt[e[i]]<<endl;
	return 0;
}
