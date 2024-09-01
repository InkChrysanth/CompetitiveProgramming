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
constexpr int N=100010;

int n, q;
int a[N], b[N];
set<int> S;

int lowbit(int x){ return x&-x; }

struct Fenwick
{
    ll a[N];
    Fenwick(){ memset(a, 0, sizeof a); }
    void add(int x, int val)
    {
        for(int i=x; i<=N; i+=lowbit(i))
            a[i]+=val;
    }
    ll query(int x)
    {
        ll res=0;
        for(int i=x; i; i-=lowbit(i))
            res+=a[i];
        return res;
    }
    ll sum(int l, int r){ return l>r ? 0 : query(r)-query(l-1); }
}tr;


signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>a[i], tr.add(i, a[i]);
    for(int i=1; i<=n; i++)
    {
        cin>>b[i];
        if(b[i]>1) S.emplace(i);
    }
    S.emplace(n+1);
    cin>>q;
    for(int x, y, opt; q--;)
    {
        cin>>opt>>x>>y;
        if(opt==1)
        {
            tr.add(x, -a[x]);
            a[x]=y;
            tr.add(x, a[x]);
        }
        else if(opt==2)
        {
            if(b[x]>1) S.erase(S.find(x)); 
            b[x]=y;
            if(b[x]>1) S.emplace(x);
        }
        else
        {
            ll res=a[x];
            auto ptr=S.lower_bound(x+1);
            int lst=x+1, p=*ptr;
            if(p>y){ cout<<res+tr.sum(lst, y)<<endl; continue; }
            while(p<=y)
            {
                res+=tr.sum(lst, p-1);
                res=max(res+a[p], res*b[p]);
                lst=p+1, ptr++, p=*ptr;
                if(p>y) res+=tr.sum(lst, y);
            }
            cout<<res<<endl;
        }
    }
	return 0;
}
