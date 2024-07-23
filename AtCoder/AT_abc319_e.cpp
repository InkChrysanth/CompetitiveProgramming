//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
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
#define sz(x) int((x).size())
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
using pll=pair<ll, ll>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n, x, y;
    cin>>n>>x>>y;
    vector<ll> ans(840), p(n), t(n);
    for(int i=1; i<n; i++) cin>>p[i]>>t[i];
    for(int i=0; i<840; i++)
    {
        ll cur=i+x;
        ans[i]=x;
        for(int j=1; j<n; j++)
        {
            while(cur%p[j]) cur++, ans[i]++;
            cur+=t[j], ans[i]+=t[j];
        }
        ans[i]+=y;
    }
    int q;
    cin>>q;
    for(int i=1; i<=q; i++)
    {
        int cur;
        cin>>cur;
        cout<<cur+ans[cur%840]<<endl;
    }
	return 0;
}
