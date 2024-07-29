// Problem: P1099 [NOIP2007 提高组] 树网的核
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1099
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
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
constexpr int N=301;

vector<pii> g[N];

int n, s, c;
int p[N], pre[N], suf[N], dep[N];
int dia[N], cnt;
bool vis[N];

void dfs(int u, int fa)
{
	p[u]=fa;
	for(auto ed: g[u])
	{
		int v=ed.fi, w=ed.se;
		if(v==fa || vis[v]) continue;
		dep[v]=dep[u]+w;
		if(dep[c]<dep[v]) c=v;
		dfs(v, u);
	}
}

void diameter()
{
	dfs(1, 0);
	dep[c]=0;
	dfs(c, 0);
	for(int pos=c; pos; pos=p[pos])
	{
		dia[++cnt]=pos;
		pre[cnt]=dep[pos];
	}
	reverse(pre+1, pre+cnt+1);
	reverse(dia+1, dia+cnt+1);
	for(int i=cnt; i>=1; i--) suf[i]=pre[cnt]-pre[i];
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>s;
	for(int i=1, u, v, w; i<=n-1; i++)
	{
		cin>>u>>v>>w;
		g[u].eb(mp(v, w));
		g[v].eb(mp(u, w));
	}
	diameter();
	for(int i=1; i<=cnt; i++)
		vis[dia[i]]=1;
	int maxd=0;
	for(int i=1; i<=cnt; i++)
	{
		dep[dia[i]]=0, c=0;
		dfs(dia[i], 0);
		cmax(maxd, dep[c]);
	}
	int l=1, r=1, ans=inf;
	while(l<=cnt)
	{
		while(r<=cnt && pre[r+1]-pre[l]<=s) r++;
		cmin(ans, max({maxd, pre[l], suf[r]}));
		l++;
	}
	cout<<ans<<endl;
	return 0;
}
