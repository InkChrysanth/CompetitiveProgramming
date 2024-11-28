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
	int T; cin>>T;
    while(T--)
    {
        int n; cin>>n;
        vector<vector<char>> g(2*n+1, vector<char>(2*n+1));
        bool _flag=false;
        for(int i=1; i<=2*n; i+=2)
        {
            bool flag=false;
            if(_flag)
            {
                for(int j=1; j<=2*n; j+=2)
                {
                    for(int a=0; a<2; a++) for(int b=0; b<2; b++)
                        g[i+a][j+b]=(flag ? '#' : '.');
                    flag^=true;
                }
            }
            else
            {
                for(int j=1; j<=2*n; j+=2)
                {
                    for(int a=0; a<2; a++) for(int b=0; b<2; b++)
                        g[i+a][j+b]=(flag ? '.' : '#');
                    flag^=true;
                }
            }
            _flag^=true;
        }
        for(int i=1; i<=2*n; i++, cout<<endl)
            for(int j=1; j<=2*n; j++)
                cout<<g[i][j];
    }
	return 0;
}
// implementation