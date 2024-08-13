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
#define endl '\n'
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define eb emplace_back

using ll=long long;
using ld=long double;
using pii=pair<int, int>;
using pli=pair<ll, int>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;
constexpr int N=200010;

struct Node
{
    int l, r, w;
    bool operator<(const Node &T)const { return w<T.w; }
}q[N];

int n, m; ll ans=0;
int p[N];

int find(int x){ return x==p[x] ? x : p[x]=find(p[x]); }

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1; i<=m; i++)
        cin>>q[i].l>>q[i].r>>q[i].w;
    sort(q+1, q+m+1);
    for(int i=1; i<=n; i++) p[i]=i;
    for(int i=1; i<=m; i++)
    {
        int l=q[i].l, r=q[i].r, w=q[i].w;
        ans+=w;
        while(find(l)!=find(r)) p[find(l)]=find(l)+1, ans+=w;
    }
    cout<<(find(1)!=find(n) ? -1 : ans)<<endl;
	return 0;
}
