#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

#define cmin(i,n) (i)=min((i),(n))
#define cmax(i,n) (i)=max((i),(n))
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
constexpr int N=200010, T=450;

int n, q;
ll a[N];
int lb[T], rb[T], p[N], tot;
ll sum[T], add[T];

signed main()
{
    setIO();
    cin>>n>>q;
    for(int i=0; i<n; i++) cin>>a[i];
    rb[0]=-1;// use 0-indexed
    while(++tot)
	{
		lb[tot]=rb[tot-1]+1;
		rb[tot]=min(T*tot, n-1);
		for(int i=lb[tot]; i<=rb[tot]; i++)
            sum[tot]+=a[i], p[i]=tot;
		if(rb[tot]==n-1) break;
	}
    while(q--)
    {
        int opt; cin>>opt;
        if(opt==1)
        {
            int x, y, k; cin>>x>>y>>k;
            if(y>=x-1){ for(int i=1; i<=tot; i++) add[i]+=k; continue; }
            for(int i=0; i<n; i+=x)
            {
                int l=i, r=i+y; cmin(r, n-1);
                int pl=p[l], pr=p[r];
                if(pl==pr)
                {
                    for(int j=l; j<=r; j++)
                        a[j]+=k, sum[p[j]]+=k;
                    continue;
                }
                for(int j=l; j<=rb[pl]; j++)
                    a[j]+=k, sum[p[j]]+=k;
                for(int j=lb[pr]; j<=r; j++)
                    a[j]+=k, sum[p[j]]+=k;
                for(int j=pl+1; j<=pr-1; j++)
                    add[j]+=k;
            }
        }
        else
        {
            int l, r; cin>>l>>r; l--, r--;// use 0-indexed
            int pl=p[l], pr=p[r];
            if(pl==pr)
            {
                ll res=0;
                for(int i=l; i<=r; i++)
                    res+=(a[i]+add[pl]);
                cout<<res<<endl;
                continue;
            }
            ll res=0;
            for(int i=l; i<=rb[pl]; i++)
                res+=(a[i]+add[pl]);
            for(int i=lb[pr]; i<=r; i++)
                res+=(a[i]+add[pr]);
            for(int i=pl+1; i<=pr-1; i++)
                res+=(sum[i]+1ll*(rb[i]-lb[i]+1)*add[i]);
            cout<<res<<endl;
        }
    }
    return 0;
}