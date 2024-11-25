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
constexpr int K=5, N=200010, M=31;

int exgcd(int a, int b, int &x, int &y)
{
    if(!b)
    {
        x=1, y=0;
        return a;
    }
    int res=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return res;
}

ll qmi(ll a, ll k, int mod)
{
    a%=mod;
    ll res=1;
    while(k)
    {
        if(k&1) res=res*a%mod;
        a=a*a%mod;
        k>>=1;
    }
    return res;
}

struct SegmentTree
{
    int val[K][M][N<<2];
    // the idx of mod
    // the idx of number
    // the idx of operation
    vector<int> mods;
    vector<string> opt;
    void init(vector<int> vec1, vector<string> vec2)
    {
        mods=vec1, opt=vec2;
        // each(mod, mods) debug(mod);
        // each(op, opt) debug(op);
    }
    void pushup(int u)
    {
        for(int i=0; i<(int)mods.size(); i++) for(int j=0; j<mods[i]; j++)
        {
            int nxt=val[i][j][u<<1];
            val[i][j][u]=val[i][nxt][u<<1|1];
        }
    }
    int work(int a, string op, int mod)
    {
        // debug(op.substr(1));
        if(op[0]=='+')
            return (a+stoi(op.substr(1)))%mod;
        if(op[0]=='*')
            return ((ll)a*stoi(op.substr(1)))%mod;
        return qmi(a, stoi(op.substr(1)), mod);
    }
    void build(int u, int l, int r)
    {
        if(l==r)
        {
            for(int i=0; i<(int)mods.size(); i++) for(int j=0; j<mods[i]; j++)
                val[i][j][u]=work(j, opt[l], mods[i]);
            return;
        }
        int mid=(l+r)>>1;
        build(u<<1, l, mid);
        build(u<<1|1, mid+1, r);
        pushup(u);
    }
    void modify(int u, int l, int r, int pos)
    {
        if(l==r)
        {
            for(int i=0; i<(int)mods.size(); i++) for(int j=0; j<mods[i]; j++)
                val[i][j][u]=work(j, opt[l], mods[i]);
            return;
        }
        int mid=(l+r)>>1;
        if(pos<=mid) modify(u<<1, l, mid, pos);
        else modify(u<<1|1, mid+1, r, pos);
        pushup(u);
    }
} sgt;

void debug_division(int x)
{
    cerr<<"Divisions:"<<endl;
    for(int i=2; i*i<=x; i++) if(x%i==0)
        while(x%i==0) x/=i, cerr<<i<<" ";
    if(x>1) cerr<<x<<" ";
    cerr<<endl;
}

vector<int> DivideMod(int x)
{
    set<int> S;
    vector<int> res;
    for(int i=2; i*i<=x; i++) if(x%i==0)
        while(x%i==0) x/=i, S.ins(i);
    if(x>1) S.ins(x);
    each(x, S) res.eb(x);
    return res;
}

signed main()
{
    setIO("expr");
    // debug_division(50);
    int tid; cin>>tid;
    if(1<=tid && tid<=3)
    {
        int n, q, mod; cin>>n>>q>>mod;
        vector<string> opt(n+1);
        for(int i=1; i<=n; i++) cin>>opt[i];
        auto work=[&](int x)
        {
            ll res=x;
            for(int i=1; i<=n; i++)
            {
                if(opt[i][0]=='+')
                    res=(res+stoi(opt[i].substr(1)))%mod;
                else if(opt[i][0]=='*')
                    res=(res*stoi(opt[i].substr(1)))%mod;
                else res=qmi(res, stoi(opt[i].substr(1)), mod);
            }
            return res;
        };
        while(q--)
        {
            int op; cin>>op;
            if(op==1)
            {
                int x; cin>>x;
                cout<<work(x)<<endl;
            }
            else
            {
                int x; string s; cin>>x>>s;
                opt[x]=s;
            }
        }
    }
    else
    {
        int n, q, mod; cin>>n>>q>>mod;
        vector<int> mods=DivideMod(mod);
        vector<string> opt(n+1);
        for(int i=1; i<=n; i++) cin>>opt[i];
        sgt.init(mods, opt);
        sgt.build(1, 1, n);
        vector<int> res(mods.size());
        auto excrt=[&]()
        {
            int M=mods[0], ans=res[0], x, y;
            for(int i=1; i<(int)mods.size(); i++)
            {
                int g=exgcd(M, mods[i], x, y);
                x*=(res[i]-ans)/g, y=mods[i]/g, x=(x%y+y)%y;
                ans=M*x+ans, M=M/g*mods[i], ans%=M;
            }
            int z=(ans%M+M)%M;
            return z;
        };
        while(q--)
        {
            int op; cin>>op;
            if(op==1)
            {
                int x; cin>>x;
                for(int i=0; i<(int)mods.size(); i++)
                    res[i]=sgt.val[i][x%mods[i]][1];
                cout<<excrt()<<endl;
            }
            else
            {
                int x; string s; cin>>x>>s;
                sgt.opt[x]=s;
                sgt.modify(1, 1, n, x);
            }
        }
    }
    return 0;
}
// math, excrt, exgcd, data structures, implementation, brute force, number theory