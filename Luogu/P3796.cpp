// Problem: P3796 AC 自动机（简单版 II）
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3796
// Memory Limit: 128 MB
// Time Limit: 3000 ms
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
constexpr int N=151, M=N*71;

int tr[M][26], tot;
int cnt[M], fail[M], id[M];

void init()
{
	memset(tr, 0, sizeof tr); tot=0;
	memset(cnt, 0, sizeof cnt);
	memset(fail, 0, sizeof fail);
	memset(id, 0, sizeof id);
}

void insert(string str, int idx)
{
	int u=0;
	each(v, str)
	{
		v-='a';
		if(!tr[u][v]) tr[u][v]=++tot;
		u=tr[u][v];
	}
	id[u]=idx;
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

int query(string str)
{
	int u=0, res=0;
	each(v, str)
	{
		v-='a';
		u=tr[u][v];
		for(int i=u; i; i=fail[i])
			if(id[i])
			{
				cnt[id[i]]++;
				cmax(res, cnt[id[i]]);
			}
	}
	return res;
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n;
	while(cin>>n, n)
	{
		init();
		vector<string> p(n+1);
		for(int i=1; i<=n; i++)
			cin>>p[i], insert(p[i], i);
		build();
		string t;
		cin>>t;
		int ans=query(t);
		cout<<ans<<endl;
		for(int i=1; i<=n; i++)
			if(cnt[i]==ans)
				cout<<p[i]<<endl;
	}
	return 0;
}
