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
// This is an interactive problem
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

void query(ll x)
{ cout<<"? "<<x<<endl; cout.flush(); }

void answer(ll x)
{ cout<<"! "<<x<<endl; cout.flush();}

signed main()
{
    int T; cin>>T;
    while(T--)
    {
        ll p1=400'000'000, p2=399'999'999;
        ll x1, x2;
        query(p1);
        cin>>x1; if(x1==-1) exit(0);
        query(p2);
        cin>>x2; if(x2==-1) exit(0);
        if(x1<=x2) answer(p1*(x2-x1)+x1);
        else answer(p1*(x2-x1+p1-1)+x1);
    }
    return 0;
}