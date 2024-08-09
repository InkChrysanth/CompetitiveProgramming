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
constexpr int N=16010, M=110;

int n, m;
struct Info { int l, p, s; } a[M];
int f[M][N];
int q[N];

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1; i<=m; i++)
        cin>>a[i].l>>a[i].p>>a[i].s;
    sort(a+1, a+m+1, [](Info x, Info y){ return x.s<y.s; });
    for(int i=1; i<=m; i++)
    {
        int ql=1, qr=0;
        for(int len=max(0, a[i].s-a[i].l); len<a[i].s; len++)
        {
            while(ql<=qr && f[i-1][q[qr]]-a[i].p*q[qr]<=f[i-1][len]-a[i].p*len) qr--;
            q[++qr]=len;
        }
        for(int j=1; j<=n; j++)
        {
            f[i][j]=max(f[i-1][j], f[i][j-1]);
            if(j>=a[i].s)
            {
                while(ql<=qr && a[i].l<j-q[ql]) ql++;
                if(ql<=qr) cmax(f[i][j], f[i-1][q[ql]]-a[i].p*q[ql]+a[i].p*j);
            }
        }
    }
    cout<<f[m][n]<<endl;
	return 0;
}
