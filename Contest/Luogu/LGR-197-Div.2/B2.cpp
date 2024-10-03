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

void query(ll x)
{ cout<<"? "<<x<<endl; cout.flush(); }

void answer(ll x)
{ cout<<"! "<<x<<endl; cout.flush();}

/*
$ x_1 \equiv a \pmod m $
$ x_1-a-1 \equiv m-1 \pmod m $
*/

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int T; cin>>T;
    while(T--)
    {
        ll a, b;
        query(1000000000000000000);
        cin>>a;
        query(1000000000000000000-a-1);
        cin>>b;
        answer(b+1);
    }
	return 0;
}
