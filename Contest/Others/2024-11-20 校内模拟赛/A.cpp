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
    vector<int> p(5*n);
    iota(all(p), 0);
    function<int(int)> find=[&](int x)
    { return x==p[x] ? x : p[x]=find(p[x]); };
    auto check1=[&](int x, int y)
    {
        for(int i=0; i<4; i++)
        {
            if(i==2) continue;
            if(find(x)==find(y+i*n)) return true;
        }
        for(int i=0; i<4; i++)
        {
            if(i==3) continue;
            if(find(x+n)==find(y+i*n)) return true;
        }
        for(int i=0; i<4; i++)
        {
            if(i==4) continue;
            if(find(x+2*n)==find(y+i*n)) return true;
        }
        for(int i=0; i<4; i++)
        {
            if(i==0) continue;
            if(find(x+3*n)==find(y+i*n)) return true;
        }
        for(int i=0; i<4; i++)
        {
            if(i==1) continue;
            if(find(x+4*n)==find(y+i*n)) return true;
        }
        return false;
    };
    auto check2=[&](int x, int y)
    {
        for(int i=0; i<4; i++)
        {
            if(i==1) continue;
            if(find(x)==find(y+i*n)) return true;
        }
        for(int i=0; i<4; i++)
        {
            if(i==2) continue;
            if(find(x+n)==find(y+i*n)) return true;
        }
        for(int i=0; i<4; i++)
        {
            if(i==3) continue;
            if(find(x+2*n)==find(y+i*n)) return true;
        }
        for(int i=0; i<4; i++)
        {
            if(i==4) continue;
            if(find(x+3*n)==find(y+i*n)) return true;
        }
        for(int i=0; i<4; i++)
        {
            if(i==0) continue;
            if(find(x+4*n)==find(y+i*n)) return true;
        }
        return false;
    };
    int cnt=0;
    for(int i=1; i<=m; i++)
    {
        char opt; int x, y;
        cin>>opt>>x>>y;
        x--, y--;// use 0-indexed
        if(opt=='k')
        {
            if(check1(x, y))
            {
                cnt++;
                continue;
            }
            p[find(x)]=find(y+2*n);
            p[find(x+n)]=find(y+3*n);
            p[find(x+2*n)]=find(y+4*n);
            p[find(x+3*n)]=find(y);
            p[find(x+4*n)]=find(y+n);
        }
        else
        {
            if(check2(x, y))
            {
                cnt++;
                continue;
            }
            p[find(x)]=find(y+n);
            p[find(x+n)]=find(y+2*n);
            p[find(x+2*n)]=find(y+3*n);
            p[find(x+3*n)]=find(y+4*n);
            p[find(x+4*n)]=find(y);
        }
    }
    cout<<cnt<<endl;
	return 0;
}
// dsu