//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

#define cmin(i,j) (i)=min((i),(j))
#define cmax(i,j) (i)=max((i),(j))
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define Fi(s) freopen(s,"r",stdin)
#define Fo(s) freopen(s,"i",stdout)
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

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n, W;
    cin>>n>>W;
    vector<vector<int>> items(W+1);
    for(int i=1; i<=n; i++)
    {
        int w, v;
        cin>>w>>v;
        // use weight as index
        items[w].eb(v);
    }
    priority_queue<int> heap;
    vector<ll> f(W+1), cnt(W+1);
    for(int i=1; i<=W; i++)
    {
        heap=priority_queue<int>();
        each(v, items[i]) heap.em(v-1);
        if(heap.empty()) continue;
        for(int k=1; k*i<=W; k++)
        {
            cnt[k]=cnt[k-1]+heap.top();
            heap.push(heap.top()-2);
            heap.pop();
        }
        for(int w=W; w>=1; w--)
            for(int k=1; k*i<=w; k++)
                cmax(f[w], f[w-k*i]+cnt[k]);
    }
    cout<<f[W]<<endl;
	return 0;
}
// dp, data structure