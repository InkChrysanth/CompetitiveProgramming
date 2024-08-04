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
constexpr int N=1000010;

int tr[N][26], tot;
int cnt[N], fail[N];

void insert(string str)
{
	int u=0;
	each(v, str)
	{
		v-='a';
		if(!tr[u][v]) tr[u][v]=++tot;
		u=tr[u][v];
	}
	cnt[u]++;
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
		v=v-'a';
		u=tr[u][v];
		for(int i=u; i && cnt[i]!=-1; i=fail[i])
			res+=cnt[i], cnt[i]=-1;
	}
	return res;
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n; cin>>n;
	string p, t;
	for(int i=1; i<=n; i++)
		cin>>p, insert(p);
	build();
	cin>>t;
	cout<<query(t)<<endl;
	return 0;
}
