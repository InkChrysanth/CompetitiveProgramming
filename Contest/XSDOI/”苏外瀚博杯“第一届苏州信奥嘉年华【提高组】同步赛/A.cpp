//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define cmin(i,j) (i)=min((i),(j))
#define cmax(i,j) (i)=max((i),(j))
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define all(x) x.begin(), x.end()
#define each(i,x) for(auto &i:(x))
#define fi first
#define se second
#define endl "\n"
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ins insert

using ll=long long;
using ull=unsigned long long;
using db=double;
using ld=long double;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

inline namespace FileIO{
void setIn(string s) { freopen(s.c_str(), "r", stdin); }
void setOut(string s) { freopen(s.c_str(), "w", stdout); }
void setIO(string s="")
{	
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	#ifndef LOCAL
        if(s.size()) setIn(s+".in"), setOut(s+".out");
	#else
        setIn("inkorange.in"), setOut("inkorange.out");
    #endif
}
}

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;
constexpr int N=101;

int n, m;
char g[N][N];

signed main()
{
	setIO("tile");
	cin>>n>>m;
	auto work=[&](int x, int y) -> char
	{
		auto inbound=[&](int x, int y) -> bool
		{ return x>=1 && x<=n && y>=1 && y<=m; };
		array<bool, 4> st={false};
		if(inbound(x+1, y)) st[g[x+1][y]-'A']=true;
		if(inbound(x-1, y)) st[g[x-1][y]-'A']=true;
		if(inbound(x, y+1)) st[g[x][y+1]-'A']=true;
		if(inbound(x, y-1)) st[g[x][y-1]-'A']=true;
		for(int i=0; i<4; i++) if(!st[i])
			return 'A'+i;
	};
	int i=1, j=1;
	while(true)
	{
		label: ;
		char ch=work(i, j);
		int sz=1;
		while(i+sz<=n && j+sz<=m && work(i, j+sz)==ch && g[i][j+sz]==0) sz++;
		for(int a=i; a<i+sz; a++) for(int b=j; b<j+sz; b++)
			g[a][b]=ch;
		bool flag=false;
		for(int c=1; c<=n; c++) for(int d=1; d<=m; d++)
			if(!g[c][d])
			{
				i=c, j=d;
				flag=true;
				goto label;
			}
		if(!flag) break;
	}
	for(int i=1; i<=n; i++, cout<<endl) for(int j=1; j<=m; j++)
		cout<<g[i][j];
	return 0;
}
// greedy, implementation
