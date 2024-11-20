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
constexpr int dx[]={0, -1, 0, 1}, dy[]={1, 0, -1, 0};


signed main()
{
    setIO();
    int T; cin>>T;
    while(T--)
    {
        int n, m; cin>>n>>m;
        vector<vector<char>> g(n+1, vector<char>(m+1));
        auto get=[&](int x, int y){ return (x-1)*m+y; };
        vector<int> p(n*m+1), sz(n*m+1, 1);
        iota(all(p), 0);
        function<int(int)> find=[&](int x)
        { return x==p[x] ? x : p[x]=find(p[x]); };
        bool flag=true;
        for(int i=1; i<=n; i++) for(int j=1; j<=m; j++)
        {
            cin>>g[i][j];
            if(g[i][j]=='.') flag=false;
        }
        if(flag)
        {
            cout<<n*m<<endl;
            continue;
        }
        auto inbound=[&](int x, int y) -> bool
        { return x>=1 && x<=n && y>=1 && y<=m; };
        for(int i=1; i<=n; i++) for(int j=1; j<=m; j++)
        {
            if(g[i][j]=='.') continue;
            for(int k=0; k<4; k++)
            {
                int ni=i+dx[k], nj=j+dy[k];
                if(inbound(ni, nj) && g[ni][nj]=='#')
                {
                    // assert(get(ni, nj)<=n*m);
                    int fu=find(get(i, j)), fv=find(get(ni, nj));
                    if(fu!=fv)
                    {
                        if(sz[fu]>sz[fv]) swap(fu, fv);
                        p[fu]=fv; sz[fv]+=sz[fu];
                    }
                }
            }
        }
        int ans=0;
        for(int i=1; i<=n; i++)
        {
            set<int> S;
            int res=0;
            for(int j=1; j<=m; j++)
            {
                if(g[i][j]=='.')
                {
                    res++;
                    for(int k=0; k<4; k++)
                    {
                        int ni=i+dx[k], nj=j+dy[k];
                        if(!inbound(ni, nj) || g[ni][nj]=='.') continue;
                        int id=find(get(ni, nj));
                        if(!S.count(id)) res+=sz[id], S.insert(id);
                    }
                }
            }
            cmax(ans, res);
        }
        for(int j=1; j<=m; j++)
        {
            set<int> S;
            int res=0;
            for(int i=1; i<=n; i++)
            {
                if(g[i][j]=='.')
                {
                    res++;
                    for(int k=0; k<4; k++)
                    {
                        int ni=i+dx[k], nj=j+dy[k];
                        if(!inbound(ni, nj) || g[ni][nj]=='.') continue;
                        int id=find(get(ni, nj));
                        if(!S.count(id)) res+=sz[id], S.insert(id);
                    }
                }
            }
            cmax(ans, res);
        }
        cout<<ans<<endl;
    }
    return 0;
}
// dsu, brute force