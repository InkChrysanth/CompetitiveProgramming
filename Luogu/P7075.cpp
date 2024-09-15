//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

#define int long long
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
constexpr int N=3200000, R1=3000000, R2=146097;

int months[]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
struct Node{ int d, m, y; } ans[N];

bool isLeap(int y){ return (y<=1582 ? (y>0 ? y%4==0 : y%4==-1) : (y%400==0 || (y%4==0 && y%100))); }
int DayCount(int m, int y){ return ((m==2 && isLeap(y)) ? months[m]+1 : months[m]); }

void init()
{
    int d=1, m=1, y=-4713;
    for(int i=0; i<N; i++)
    {
        ans[i]={d, m, y};
        if(d==4 && m==10 && y==1582) d=15;
        else if(d==DayCount(m, y))
        {
            d=1, m++;
            if(m==13) m=1, y++;
            if(y==0) y++;
        }
        else d++;
    }
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    init();
    int T; cin>>T;
    while(T--)
    {
        auto output=[&](int d, int m, int y)
        {
            if(y>0) cout<<d<<" "<<m<<" "<<y<<endl;
            else cout<<d<<" "<<m<<" "<<-y<<" BC\n";
        };
        int q, add=0; cin>>q;
        if(q>=N) add=((q-R1)/R2)*400, q=R1+(q-R1)%R2;
        // debug(add);
        output(ans[q].d, ans[q].m, ans[q].y+add);
    }
	return 0;
}
