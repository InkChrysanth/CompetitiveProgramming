// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
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

signed main()
{
    setIO();
    int T; cin>>T;
    while(T--)
    {
        int n; cin>>n;
        vector<int> a(n+1), f(2*n+1, -inf);
        for(int i=1; i<=n; i++) cin>>a[i];
        f[n]=f[n+n]=inf;
        for(int i=n; i>1; i--)
        {
            if(a[i-1]<f[i])
                f[i-1+n]=max(f[i-1+n], -a[i]);
            if(a[i-1]<-a[i])
                f[i-1+n]=max(f[i-1+n], f[i]);
            if(a[i-1]<f[i+ n])
                f[i-1+n]=max(f[i-1+n], a[i]);
            if(a[i-1]<a[i])
                f[i-1+n]=max(f[i-1+n], f[i+n]);
            if(-a[i-1]<f[i])
                f[i-1]=max(f[i-1], -a[i]);
            if(-a[i-1]<-a[i])
                f[i-1]=max(f[i-1], f[i]);
            if(-a[i-1]<f[i+n])
                f[i-1]=max(f[i-1], a[i]);
            if(-a[i-1]<a[i])
                f[i-1]=max(f[i-1], f[i+n]);
        }
        if(f[1]==-inf && f[1+n]==-inf) cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
            int x=-inf, y=-inf;
            for(int i=1; i<=n; i++)
            {
                if(f[i]!=-inf)
                {
                    if(-a[i]>x && f[i]>y)
                    {
                        x=a[i]=-a[i];
                        continue;
                    }
                    if(-a[i]>y && f[i]>x)
                    {
                        y=a[i]=-a[i];
                        continue;
                    }
                }
                if(f[i+n]!=-inf)
                {
                    if(a[i]>x && f[i+n]>y)
                    {
                        x=a[i];
                        continue;
                    }
                    if(a[i]>y && f[i+n]>x)
                    {
                        y=a[i];
                        continue;
                    }
                }
                if(x<y) swap(x, y);
            }
            for(int i=1; i<=n; i++) cout<<a[i]<<" ";
            cout<<endl;
        }
    }
    return 0;
}