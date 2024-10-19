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

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n; cin>>n;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n-1; i++) cin>>b[i];
    sort(all(a)); sort(all(b));
    int l=1, r=1e9+1, ans=r; 
    auto check=[&](int x)
    {
        bool used=false;
        for(int i=n-1, j=n-1; i>=0; i--, j--)
        {
            if(a[i]>b[j] && used) return false;
            if(a[i]>b[j] && a[i]>x) return false;
            if(a[i]>b[j]) used=true, j++;
        }
        return true;
    };
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid)) r=mid-1, ans=mid;
        else l=mid+1;
    }
    cout<<(ans==1e9+1 ? -1 : ans)<<endl;
	return 0;
}
// binary search