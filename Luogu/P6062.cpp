// Problem: P6062 [USACO05JAN] Muddy Fields G
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P6062
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

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin>>n>>m;
	vector<string> g(n);
	for(int i=0; i<n; i++)
		cin>>g[i];
	int rcnt=0, ccnt=0;
	vector<vector<bool>> vis(n, vector<bool>(m, 0));
	vector<vector<int>> rid(n, vector<int>(m)), cid(n, vector<int>(m));
	for(int i=0; i<n; i++) for(int j=0; j<m; j++)
    {
    	if(g[i][j]=='*' && !vis[i][j])
        {
            rcnt++;
            int k=j;
            while(k<m && g[i][k]=='*')
            {
                rid[i][k]=rcnt;
                vis[i][k]=1;
                k++;
            }
        }
    }
    fill(all(vis), vector<bool>(m, 0));
    for(int i=0; i<n; i++) for(int j=0; j<m; j++)
    {
    	if(g[i][j]=='*' && !vis[i][j])
        {
            ccnt++;
            int k=i;
            while(k<n && g[k][j]=='*')
            {
                cid[k][j]=ccnt;
                vis[k][j]=1;
                k++;
            }
        }
    }
    vector<vector<bool>> ct(rcnt+1, vector<bool>(ccnt+1, 0));
    for(int i=0; i<n; i++) for(int j=0; j<m; j++)
    	if(g[i][j]=='*') ct[rid[i][j]][cid[i][j]]=1;
    vector<bool> st(ccnt+1, 0);
    vector<int> match(ccnt+1, 0);
    function<bool(int)> dfs=[&](int u)
    {
    	for(int v=1; v<=ccnt; v++)
    	{
    		if(ct[u][v] && !st[v])
    		{
    			st[v]=1;
    			if(!match[v] || dfs(match[v]))
    			{
    				match[v]=u;
    				return 1;
    			}
    		}
    	}
    	return 0;
    };
    int ans=0;
    for(int i=1; i<=rcnt; i++)
    {
    	fill(all(st), 0);
    	ans+=dfs(i);
    }
    cout<<ans<<endl;
	return 0;
}
