#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
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
constexpr int dx[]={-1, 1, -1, 1}, dy[]={1, -1, -1, 1};

signed main()
{
	setIO();
	int T; cin>>T;
    while(T--)
    {
        array<int, 2> ans={4, 4};
        vector<vector<char>> g(8, vector<char>(8));
        for(int i=1; i<=7; i++) for(int j=1; j<=7; j++)
            cin>>g[i][j];
        auto check=[&](int op)
        {
            // auto inbound=[](int x, int y)
            // { return x>=1 && x<=7 && y>=1 && y<=7; };
            for(int i=2; i<=6; i++) for(int j=2; j<=6; j++) 
            {
                if(((i&1)^(j&1))!=op || g[i][j]!='B') continue;
                bool flag=true;
                for(int k=0; k<4; k++)
                {
                    int ni=i+dx[k], nj=j+dy[k];
                    flag&=(g[ni][nj]=='B');
                }
                if(flag) return false;
            }
            return true;
        };
        function<void(int, int)> dfs=[&](int x, int op)
        {
            if(check(op)) cmin(ans[op], x);
            if(x>=ans[op]) return;
            for(int i=1; i<=7; i++) for(int j=1; j<=7; j++)
            {
                if(((i&1)^(j&1))!=op) continue;
                char tmp=g[i][j];
                g[i][j]=(tmp=='W' ? 'B' : 'W');
                dfs(x+1, op);
                g[i][j]=tmp;
            }
        };
        dfs(0, 0);
        dfs(0, 1);
        cout<<ans[0]+ans[1]<<endl;
    }
	return 0;
}
// dfs and similar, brute force, implementation, divide and conquer