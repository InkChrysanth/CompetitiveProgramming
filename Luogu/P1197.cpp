// Problem: P1197 [JSOI2008] 星球大战
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1197
// Memory Limit: 125 MB
// Time Limit: 1000 ms

// #pragma GCC optimize(2)
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

const int N=400010;
int n, m, k;
vector<int> g[N], tar;
int p[N], ans[N], tot;
bool st[N];

int find(int x)
{
	if(x==p[x]) return x;
	return p[x]=find(p[x]);
}

void merge(int x, int y)
{
	int fx=find(x), fy=find(y);
	if(fx!=fy) p[fx]=fy, tot--;
}

signed main()
{
	cin.tie(0); cout.tie(0);
	n=int_rd, m=int_rd;
	for(int i=0; i<m; i++)
	{
		int u=int_rd, v=int_rd;
		g[u].emplace_back(v), g[v].emplace_back(u);
	}
	for(int i=0; i<n; i++) p[i]=i;
	k=int_rd; tot=n-k;
	for(int i=0; i<k; i++)
	{
		int x=int_rd;
		tar.emplace_back(x);
		st[x]=true;
	}
	reverse(tar.begin(), tar.end());
	for(int u=0; u<n; u++)
		if(!st[u]) 
			for(auto v: g[u]) if(!st[v]) merge(u, v);
	ans[k]=tot;
	for(int i=0; i<tar.size(); i++)
	{
		st[tar[i]]=false; tot++;
		for(auto v: g[tar[i]]) if(!st[v]) merge(tar[i], v);
		ans[k-1-i]=tot;
	}
	for(int i=0; i<=k; i++) cout<<ans[i]<<endl;
	return 0;
}