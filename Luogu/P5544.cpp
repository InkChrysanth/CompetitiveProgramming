//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

#define y0 y114514
#define y1 y1919810
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
#define urd uniform_real_distribution

using ll=long long;
using ld=long double;
using pii=pair<int, int>;
using pli=pair<ll, int>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;
constexpr int N=11, M=1010;
constexpr ld st=3000, ed=1e-8, dlt=0.997;//Parameters
random_device seed;
mt19937_64 sd(seed());

int n, m; ld R;
struct Node{ ld x, y, r; } a[N], b[M];
ld x0=0, y0=0;

ld dist(ld x1, ld y1, ld x2, ld y2)
{ return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)); }

int calc(ld x, ld y)
{
    int cnt=0; ld r_max=R;
    for(int i=1; i<=n; i++)
        cmin(r_max, dist(a[i].x, a[i].y, x, y)-a[i].r);
    if(r_max<0) return 0;
    for(int i=1; i<=m; i++)
        if(dist(b[i].x, b[i].y, x, y)<=r_max)
            cnt++;
    return cnt;
}

int ans=0;
void SA()
{
    ld x=0, y=0; int res=calc(x, y);
    for(ld T=st; T>=ed; T*=dlt)
    {
        ld new_x=x+urd<>(-10, 10)(sd)*T;
        ld new_y=y+urd<>(-10, 10)(sd)*T;
        int cnt=calc(new_x, new_y);
        int diff=cnt-res;
        // debug(diff);
        if(diff>0) x=new_x, y=new_y, x0=new_x, y0=new_y, res=cnt;
        else if(exp(-1.0*diff/T)<urd<>(0, 1)(sd)) x=new_x, y=new_y;
        cmax(ans, res);
    }
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m>>R;
    for(int i=1; i<=n; i++)
        cin>>a[i].x>>a[i].y>>a[i].r;
    for(int i=1; i<=m; i++)
        cin>>b[i].x>>b[i].y, x0+=b[i].x, y0+=b[i].y;
    x0/=m, y0/=m;
    while(clock()<=CLOCKS_PER_SEC*0.95) SA();
    cout<<ans<<endl;
	return 0;
}
