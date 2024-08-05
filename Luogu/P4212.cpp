// Problem: P4212 外太空旅行
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4212
// Memory Limit: 125 MB
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
constexpr int N=51;

int start=clock();
int n, ans=0;
bool g[N][N], st[N];
vector<int> a;

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	for(int i=1; i<=n; i++) a.eb(i);
	int u, v;
	while(cin>>u>>v) g[u][v]=g[v][u]=1;
	while(clock()-start<=CLOCKS_PER_SEC*0.95)
	{
		random_shuffle(all(a));
		int cnt=0;
		memset(st, 0, sizeof st);
		for(int i=1; i<=n; i++)
		{
			if(!st[a[i]])
			{
				cnt++;
				for(int j=1; j<=n; j++)
				{
					if(!g[a[i]][a[j]])
					{
						st[a[j]]=1;	
					}
				}
			}
		}
		cmax(ans, cnt);
	}
	cout<<ans<<endl;
	return 0;
}
