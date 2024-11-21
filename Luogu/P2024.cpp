//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

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

signed main()
{
	setIO();
	int n, m; cin>>n>>m;
    vector<int> p(3*n+1);
    iota(all(p), 0);
    function<int(int)> find=[&](int x)
    { return x==p[x] ? x : p[x]=find(p[x]); };
    int ans=0;
    for(int i=1; i<=m; i++)
    {
        int op, a, b; cin>>op>>a>>b;
        if(a>n || b>n)
        {
            ans++;
            continue;
        }
        if(op==1)
        {
            if(find(a)==find(b+n) || find(b)==find(a+n)) ans++;
            else
            {
                p[find(a)]=find(b);
                p[find(a+n)]=find(b+n);
                p[find(a+2*n)]=find(b+2*n);
            }
        }
        else
        {
            if(find(a)==find(b) || find(a)==find(b+n)) ans++;
            else
            {
                p[find(b)]=find(a+n);
                p[find(b+n)]=find(a+2*n);
                p[find(b+2*n)]=find(a);
            }
        }
    }
    cout<<ans<<endl;
	return 0;
}
/*
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

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

signed main()
{
	setIO();
	int n, k; cin>>n>>k;
	vector<int> p(n+1), d(n+1, 0);
	iota(all(p), 0);
	function<int(int)> find=[&](int x)
	{
		if(x==p[x]) return x;
		int px=find(p[x]);
		d[x]=(d[x]+d[p[x]])%3;
		p[x]=px;
		return p[x];
	};
	int ans=0;
	for(int i=1; i<=k; i++)
	{
		int opt, x, y; cin>>opt>>x>>y;
		if(x>n || y>n || (opt==2 && x==y))
		{
			ans++;
			continue;
		}
		if(opt==1)
		{
			if(find(x)==find(y))
			{
				if(d[x]!=d[y]) ans++;
			}
			else
			{
				d[p[x]]=(d[y]-d[x]+3)%3;
				p[p[x]]=p[y];
			}
		}
		else
		{
			if(find(x)==find(y))
			{
				if(d[x]!=(d[y]+1)%3)// x不吃y (矛盾情况)
				// if((d[x]+2)%3!=d[y])//y不被x吃
					ans++;
			}
			else
			{
				d[p[x]]=(d[y]-d[x]+3+1)%3;
				p[p[x]]=p[y];
			}
		}
		// debug(ans);
	}
	cout<<ans<<endl;
	return 0;
}
*/
// dsu