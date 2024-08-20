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
constexpr int N=3, mod=1e9+7;

struct matrix
{
    int n, m;
    ll a[N][N];
    void clear(){ memset(a, 0, sizeof a); }
    matrix operator *(const matrix &T)const
    {
        matrix res; res.clear();
        res.n=n, res.m=T.m;
        for(int i=0; i<res.n; i++) for(int j=0; j<res.m; j++) for(int k=0; k<res.m; k++) 
            res.a[i][j]=(res.a[i][j]+a[i][k]*T.a[k][j])%mod;
        return res;
    }
};

matrix a={1, 3, {{1, 1, 1}}};
matrix b={3, 3, {{1, 0, 1}, {1, 0, 0}, {0, 1, 0}}};
matrix qmi(int k)
{
    matrix res=a, mul=b;
    while(k)
    {
        if(k&1) res=res*mul;
        mul=mul*mul;
        k>>=1;
    }
    return res;
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    int T;
    cin>>T;
    for(int k; T>=1; T--)
    {
        cin>>k;
        if(k<=3) cout<<1<<endl;
        else cout<<qmi(k-3).a[0][0]<<endl;
    }
	return 0;
}
