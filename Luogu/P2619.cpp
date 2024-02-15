// Problem: P2619 [国家集训队] Tree I
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2619
// Memory Limit: 500 MB
// Time Limit: 2000 ms

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

const int N=100010, W=100;

struct Node
{
	int u, v, w, col;
	bool operator<(const Node &T)const
	{
		if(w==T.w) return col<T.col;
		return w<T.w;
	}
}edges[N];

int n, m, need;
int ans=0;
int p[N];

int find(int x)
{
	if(x==p[x]) return p[x];
	return p[x]=find(p[x]);
}

int kruskal()
{
	int wcnt=0;
	for(int i=1; i<=n; i++) p[i]=i;
	sort(edges+1, edges+m+1);
	int cnt=0; ans=0;
	for(int i=1; i<=m; i++)
	{
		int u=edges[i].u, v=edges[i].v, w=edges[i].w, col=edges[i].col;
		u=find(u), v=find(v);
		if(u!=v)
		{
			p[v]=u;
			cnt++;
			ans+=w;
			if(!col) wcnt++;
		}
	}
	return wcnt;
}

bool check(int x)
{
	for(int i=1; i<=m; i++)
		if(!edges[i].col)
			edges[i].w+=x;
	bool res=(kruskal()>=need);
	for(int i=1; i<=m; i++)
		if(!edges[i].col)
			edges[i].w-=x;
	return res;
}

signed main()
{
	cin.tie(0); cout.tie(0);
	n=int_rd, m=int_rd, need=int_rd;
	for(int i=1; i<=m; i++)
	{
		int u=int_rd, v=int_rd, w=int_rd, col=int_rd;
		edges[i]={u+1, v+1, w, col};
	}
	int tmp=0, l=-W, r=W;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
		{
			tmp=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	check(tmp);
	cout<<ans-tmp*need<<endl;
	return 0;
}