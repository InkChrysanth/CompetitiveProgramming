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
constexpr int N=200010;

int n;
int f[N][3];
string s;

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    cin>>n>>s;
    s=" "+s;
    //R->0 S->1 P->2
    for(int i=1; i<=n; i++)
    {
        if(s[i]=='R')
        {
            f[i][0]=max(f[i-1][1], f[i-1][2]);
            f[i][2]=max(f[i-1][0], f[i-1][1])+1;
        }
        if(s[i]=='S')
        {
            f[i][1]=max(f[i-1][0], f[i-1][2]);
            f[i][0]=max(f[i-1][1], f[i-1][2])+1;
        }
        if(s[i]=='P')
        {
            f[i][2]=max(f[i-1][0], f[i-1][1]);
            f[i][1]=max(f[i-1][0], f[i-1][2])+1;
        }
    }
    cout<<max({f[n][0], f[n][1], f[n][2]});
	return 0;
}