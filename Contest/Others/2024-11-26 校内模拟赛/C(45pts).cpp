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

vector<int> getDivision(int x)
{
    vector<int> res;
    for(int i=2; i*i<=x; i++) if(x%i==0)
        while(x%i==0) x/=i, res.eb(i);
    if(x>1) res.eb(x);
    return res;
}

bool check(int x)
{
    int sqr=sqrt(x);
    if(sqr*sqr==x) return true;
    return false;
}

int mx=0;
bool check2(vector<int> vec)
{
    for(int i=2; i<=mx; i++)
        if(vec[i]&1)
            return false;
    return true;
}

signed main()
{
    setIO();
    int n; cin>>n;
    vector<vector<int>> f(n);
    vector<int> cnt(1000001);
    bool flag=false;
    for(int i=0; i<n; i++)
    {
        int x; cin>>x; cnt[x]++;
        if(check(x)) return cout<<1<<endl, 0;
        if(cnt[x]==2) flag=true;
        f[i]=getDivision(x);
        each(fac, f[i]) cmax(mx, fac);
    }
    if(flag) return cout<<2<<endl, 0;
    if(n>100) return cout<<3<<endl, 0;
    int ans=n+1;
    while((double)clock()/CLOCKS_PER_SEC<=4.9)
    {
        vector<int> buc(1001);
        random_shuffle(all(f));
        for(int i=0; i<n; i++)
        {
            each(fac, f[i]) buc[fac]++;
            if(check2(buc))
            {
                cmin(ans, i+1);
                break;
            }
        }
    }
    cout<<(ans==n+1 ? -1 : ans)<<endl;
    return 0;
}
// number theory