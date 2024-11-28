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
    int n, q; cin>>n>>q;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++) cin>>a[i];
    // subtask 1
    if(q==1)
    {
        int opt; cin>>opt;
        if(opt==1)
        {
            int x, v; cin>>x>>v;
            a[x]=v;
        }
        else
        {
            vector<int> cnt(600001);
            for(int i=1; i<=n; i++) cnt[a[i]]++;
            for(int i=1; i<=500000; i++)
            {
                while(cnt[i]>2)
                {
                    cnt[i]-=2;
                    cnt[i+1]++;
                }
            }
            int res=0;
            for(int i=1; i<=600000; i++)
                res+=(cnt[i]!=0);
            cout<<res<<endl;
        }
        return 0;
    }
    // subtask 2
    if(n<=2000 && q<=2000)
    {
        while(q--)
        {
            int op; cin>>op;
            if(op==1)
            {
                int x, v; cin>>x>>v;
                a[x]=v;
            }
            else
            {
                multiset<int> S;
                for(int i=1; i<=n; i++) S.ins(a[i]);
                label: ;
                each(x, S)
                {
                    // debug(x);
                    // debug(S.count(x));
                    if(S.count(x)>2)
                    {
                        S.erase(S.find(x));
                        S.erase(S.find(x));
                        S.ins(x+1);
                        goto label;
                    }
                }
                set<int> _S;
                each(x, S) _S.ins(x);
                cout<<_S.size()<<endl;
            }
        }
        return 0;
    }
    // subtask 4
    // ?
    return 0;
}
