// Problem: P5829 【模板】失配树
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P5829
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
constexpr int N=1000010, K=21;

string s;
int dep[N], fa[N][K];
int ne[N];

int lca(int x, int y)
{
	if(dep[x]<dep[y]) swap(x, y);
	for(int i=20; i>=0; i--)
		if(dep[fa[x][i]]>=dep[y])
			x=fa[x][i];
	if(x==y) return x;
	for(int i=20; i>=0; i--)
	{
		if(fa[x][i]!=fa[y][i])
		{
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin>>s;
	ne[0]=-1;
	int k=-1, j=0;
	while(j<s.size())
	{
		if(k==-1 || s[j]==s[k])
		{
			j++, k++;
			// ne[j]=(s[j]==s[k] ? ne[k] : k);
			ne[j]=k;
		}
		else k=ne[k];
	}
	// for(int i=1; i<=s.size(); i++) debug(ne[i]);
	for(int i=1; i<=s.size(); i++)
	{
		dep[i]=dep[ne[i]]+1;
		fa[i][0]=ne[i];
		for(int j=1; j<=20; j++)
			fa[i][j]=fa[fa[i][j-1]][j-1];
	}
	int q;
	cin>>q;
	for(int x, y; q>=1; q--)
	{
		cin>>x>>y;
		x=fa[x][0], y=fa[y][0];
		cout<<lca(x, y)<<endl;
	}
	return 0;
}
