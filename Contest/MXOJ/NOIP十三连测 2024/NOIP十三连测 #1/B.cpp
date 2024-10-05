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
#define endl "\n"
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define em emplace

using ll=long long;
using ull=unsigned long long;
using ld=long double;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;

signed main()
{
    Fre("Btree");
    cin.tie(0)->sync_with_stdio(0); 
    int n, k;
    cin>>n>>k;
    if(!(n&1)) return cout<<"-1"<<endl, 0;
    int h=__gcd(n, k), w=n/h;
    vector<vector<int>> g(h+1, vector<int>(w+1));
    for(int i=1; i<=h; i++)
    {
        g[i][1]=i-1;
        for(int j=2; j<=w; j++)
            g[i][j]=(g[i][j-1]+k)%n;
    }
    cout<<(n-1)/2<<endl;
    for(int i=1; i<h; i++)
        for(int j=1; j<w; j+=2)
            cout<<g[i][j]<<" "<<g[i+1][j]<<endl;
    for(int i=1; i<=w-2; i+=2) cout<<g[1][i]<<" "<<g[1][i+1]<<endl;
    for(int i=2; i<h; i+=2) cout<<g[i][w]<<" "<<g[i+1][w-1]<<endl;
	return 0;
}
