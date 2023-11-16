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

const int N=30;
int n;
basic_string<char> mHOP;
vector<pii> ans;
bool vis[N*10][N*10];
bool bar[N*10][N*10];
bool st[N*10][N*10];

pii get(char ch)
{
	if(ch=='L') return mp(-1, 0);
	if(ch=='R') return mp(1, 0);
	if(ch=='D') return mp(0, -1);
	if(ch=='U') return mp(0, 1);
}

void dfs(int u, int x, int y)
{
	if(u==n+1)
	{
		if(!vis[x][y])
		{
			vis[x][y]=true;
			ans.emplace_back(mp(x, y));
		}
		return;
	}
	pii dir=get(mHOP[u]);
	if(!st[x+dir.first][y+dir.second])
	{
		st[x+dir.first][y+dir.second]=true;
		bar[x+dir.first][y+dir.second]=false;
		dfs(u+1, x+dir.first, y+dir.second);
		bar[x+dir.first][y+dir.second]=true;
		dfs(u+1, x, y);
		st[x+dir.first][y+dir.second]=false;
		bar[x+dir.first][y+dir.second]=false;
	}
	else
	{
		if(!bar[x+dir.first][y+dir.second]) dfs(u+1, x+dir.first, y+dir.second);
		else dfs(u+1, x, y);
	}
}

void sbmH()
{
	st[N][N]=true;
	dfs(1, N, N);
	sort(ans.begin(), ans.end());
	cout<<ans.size()<<endl;
	for(auto [x, y]: ans)
		cout<<x-N<<' '<<y-N<<endl;
}

signed main()
{
	freopen("T2.in", "r", stdin);
	freopen("T2.out", "w", stdout);
	cin.tie(0); cout.tie(0);
	cin>>n>>mHOP; mHOP=" "+mHOP;
	sbmH();
	return 0;
}