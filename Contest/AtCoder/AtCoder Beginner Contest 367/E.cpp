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
#define endl '\n'
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define eb emplace_back

using ll=long long;
using ld=long double;
using pii=pair<int, int>;
using pli=pair<ll, int>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    int n; ll k;
    cin>>n>>k;
    vector<int> a(n+1);
    vector<vector<int>> p(n+1, vector<int>(64));
    for(int i=1; i<=n; i++) cin>>p[i][0];
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int j=1; j<64; j++)
        for(int i=1; i<=n; i++)
            p[i][j]=p[p[i][j-1]][j-1];
    for(int i=1; i<=n; i++)
    {
        int pos=i;
        for(int j=0; j<64; j++) if((k>>j)&1) pos=p[pos][j];
        cout<<a[pos]<<" ";
    }
	return 0;
}
