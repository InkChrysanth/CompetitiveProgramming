// Problem: Kruskal算法求最小生成树
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/861/
// Memory Limit: 64 MB
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

const int N=100010;

struct Node
{
	int u, v, w;
	bool operator<(const Node &T)const
	{
		return w<T.w;
	}
};

int n, m;
int p[N];
vector<Node> e;

int find(int x)
{
	if(p[x]==x) return p[x];
	return p[x]=find(p[x]);
}

signed main()
{
	cin.tie(0); cout.tie(0);
	n=int_rd, m=int_rd;
	for(int i=1; i<=m; i++)
		e.push_back({int_rd, int_rd, int_rd});
	sort(e.begin(), e.end());
	for(int i=1; i<=n; i++)
		p[i]=i;
	int res=0, cnt=0;
	for(auto [u, v, w]: e)
	{
		u=find(u), v=find(v);
		if(u!=v)
		{
			p[v]=u;
			res+=w;
			cnt++;
		}
	}
	if(cnt<n-1) puts("impossible");
	else cout<<res<<endl;
	return 0;
}