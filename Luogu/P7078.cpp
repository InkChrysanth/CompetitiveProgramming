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
constexpr int N=1000010;

int n, w[N];
pii qa[N], qb[N];
int ha, ta, hb, tb;

pii getMax()
{
    auto res=mp(-inf, -inf);
    if(ha<=ta) res=qa[ta];
    if(hb<=tb && qb[tb]>res) res=qb[tb];
    if(ha<=ta && res==qa[ta]) ta--;
    else tb--;
    return res;
}
pii getMin(bool op=true)
{
    auto res=mp(inf, inf);
    if(ha<=ta) res=qa[ha];
    if(hb<=tb && qb[hb]<res) res=qb[hb];
    if(!op) return res;
    if(ha<=ta && res==qa[ha]) ha++;
    else hb++;
    return res;
}

void solve()
{
    ha=1, ta=0, hb=n, tb=n-1;
    for(int i=1; i<=n; i++) qa[++ta]=mp(w[i], i);
    int res=n;
    while(true)
    {
        auto mx=getMax(), mn=getMin();
        mx.fi-=mn.fi; res--;
        qb[--hb]=mx;
        if(mx==getMin(false)) break;
    }
    function<bool(int)> check=[&](int cnt)
    {
        if(cnt==1) return false;
        if(cnt==2) return true;
        auto mx=getMax(), mn=getMin();
        mx.fi-=mn.fi;
        if(mx>getMin(false)) return true;
        qb[--hb]=mx;
        return !check(cnt-1);
    };
    cout<<(check(res) ? res+1 : res)<<endl;
}

signed main()
{
    // Fre("test");
	cin.tie(0)->sync_with_stdio(0);
    int T;
    cin>>T>>n;
    T--;
    for(int i=1; i<=n; i++) cin>>w[i];
    solve();
    while(T--)
    {
        int q; cin>>q;
        for(int i=1, x, v; i<=q; i++)
        {
            cin>>x>>v;
            w[x]=v;
        }
        solve();
    }
	return 0;
}
