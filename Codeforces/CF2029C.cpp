//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

#define cmin(i,j) (i)=min((i),(j))
#define cmax(i,j) (i)=max((i),(j))
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define all(x) x.begin(), x.end()
#define each(i,x) for(auto &i:(x))
#define fi first
#define se second
#define endl "\n"
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ins insert

using ll=long long;
using ull=unsigned long long;
using db=double;
using ld=long double;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

inline namespace FileIO{
void setIn(string s) { freopen(s.c_str(), "r", stdin); }
void setOut(string s) { freopen(s.c_str(), "w", stdout); }
void setIO(string s="")
{	
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	#ifndef LOCAL
        if(s.size()) setIn(s+".in"), setOut(s+".out");
	#else
        setIn("inkorange.in"), setOut("inkorange.out");
    #endif
}
}

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;

void solve1()
{
    int n; cin>>n;
    vector<int> a(n+1);
    // before/in/after skipped interval
    vector<array<int, 3>> f(n+1);
    for(int i=1; i<=n; i++) cin>>a[i];
    auto work=[](int a, int x){ return a+(x>a)-(x<a); };
    for(int i=1; i<=n; i++)
    {
        f[i][0]=work(f[i-1][0], a[i]);
        f[i][1]=max(f[i-1][1], f[i-1][0]);
        if(i>1) f[i][2]=max(work(f[i-1][1], a[i]), work(f[i-1][2], a[i]));
    }
    cout<<max(f[n][1], f[n][2])<<endl;
}

// easy to make it
void solve2()
{
    int n; cin>>n;
    vector<int> a(n+1), pre(n+1);
    auto work=[](int a, int x){ return a+(x>a)-(x<a); };
    int cur=0;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i]; cur=work(cur, a[i]);
        pre[i]=max(pre[i-1], cur);
    }
    // for(int i=1; i<=n; i++) cerr<<pre[i]<<" \n"[i==n];
    int l=0, r=n, res=0;
    auto check=[&](int x)
    {
        int t=x;
        for(int i=n; i>=1; i--)
        {
            if(pre[i-1]>=t) return true;
            if(t>a[i]) t++;
            else t--;
        }
        return false;
    };
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid)) l=mid+1, res=mid;
        else r=mid-1;
    }
    cout<<res<<endl;
}

signed main()
{
	setIO();
	int T; cin>>T;
    while(T--) solve1();
	return 0;
}
// binary search
// dp