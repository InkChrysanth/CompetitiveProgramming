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
#define sz(x) int((x).size())
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
using pll=pair<ll, ll>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;
constexpr int N=400010;

set<pii> row[N], col[N];

void insert(set<pii> &s, int x)
{
	pii xx=mp(x, x);
	auto pos=s.insert(xx).fi;
	if(pos!=s.begin())
	{
		pii nd=*prev(pos);
		if(nd.se+1==x)
		{
			int l=nd.fi, r=x;
			s.erase(prev(pos));
			s.erase(pos);
			pos=s.insert(mp(l, r)).fi;
		}
	}
	if(pos!=prev(s.end()))
	{
		pii nd=*next(pos);
		if(nd.fi-1==(*pos).se)
		{
			int l=(*pos).fi, r=nd.se;
			s.erase(next(pos));
			s.erase(pos);
			s.insert(mp(l, r));
		}
	}
}

int find_pre(set<pii> s, int x)
{
	auto ptr=s.lower_bound(mp(x+1, x));
	ptr--;
	return (*ptr).fi-1;
}

int find_nxt(set<pii> s, int x)
{
	auto ptr=s.lower_bound(mp(x+1, x));
	ptr--;
	return (*ptr).se+1;
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin>>n;
	string s;
	cin>>s;
	int x=0, y=0;
	insert(row[n], 0);
	insert(col[n], 0);
	each(opt, s)
	{
		if(opt=='U') x=find_nxt(col[n+y], x);
		if(opt=='D') x=find_pre(col[n+y], x);
		if(opt=='L') y=find_pre(row[n+x], y);
		if(opt=='R') y=find_nxt(row[n+x], y);
		insert(row[n+x], y);
		insert(col[n+y], x);
	}
	cout<<y<<' '<<x<<endl;
	return 0;
}
