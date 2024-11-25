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
constexpr int N=10010;

int n,k,w,m,A[N];
unsigned long long seed;
unsigned long long _rand(){
    seed^=seed<<13;
    seed^=seed>>7;
    seed^=seed<<17;
    return seed;
}
void read_test(){
    cin>>k>>w>>m>>seed;
    for(int i=1;i<=n;++i) A[i]=_rand()%m;
}

int st[N];

signed main()
{
    setIO();
    cin>>n;
    auto check=[&](int x)
    {
        memset(st, 0, sizeof st);
        int res=0, cnt=0;
        int l=1, r=1;
        for(; r<=n; r++)
        {
            st[A[r]]++;
            if(st[A[r]]==1 && A[r]<=x)
            {
                cnt++;
                while(l<=r && cnt==x+1)
                {
                    st[A[l]]--;
                    if(st[A[l]]==0 && A[l]<=x) cnt--;
                    l++;
                }
            }
            res+=r-l+1;
            if(res>=k) return true;
        }
        return false;
    };
    int ans=0;
    for(int i=1; i<=n; i++)
    {
        read_test();
        int l=0, r=m, res=r;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(check(mid)) r=mid-1, res=mid;
            else l=mid+1;
        }
        cmax(ans, w+res);
    }
    cout<<ans<<endl;
    return 0;
}
// binary search