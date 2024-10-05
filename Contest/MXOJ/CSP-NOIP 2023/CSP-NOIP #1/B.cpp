#include <bits/stdc++.h>
#define ing long long
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N=100010, MOD=1e9+7;
int n, q;
int p[N], d[N];

int find(int x)
{
	if(p[x]==x) return x;
	int t=p[x];
	p[x]=find(p[x]);
	d[x]=d[x]^d[t];
	return p[x];
}
signed main()
{
	freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>q;
	for(int i=1; i<=n; i++) p[i]=i;
	for(int i=1; i<=n-1; i++){int u, v; cin>>u>>v;}
	while(q--)
	{
		int u, v, w; cin>>u>>v>>w;
		int x=find(u), y=find(v);
		if(x==y && d[u]!=(d[v]^w))
		{cout<<"0"<<endl; return 0;}
		else if(x!=y)
		{
			p[y]=x;
			d[y]=d[u]^d[v]^w;
		}
	}
	int cnt=0;
	for(int i=1; i<=n; i++)
		if(find(i)==i)
			cnt++;
	int ans=1;
	for(int i=1; i<cnt; i++)
		ans=(ans*2)%MOD;
	cout<<ans<<endl;
	return 0;
}