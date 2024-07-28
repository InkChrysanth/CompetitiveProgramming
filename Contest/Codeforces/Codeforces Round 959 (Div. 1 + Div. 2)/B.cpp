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

void solve()
{
    int n;
    cin>>n;
    string st, ed;
    cin>>st>>ed;
    if(st[0]=='0')
    {
        if(st[0]!=ed[0])
        {
            cout<<"NO"<<endl;
            return;
        }
        int pos1=inf, pos2=inf;
        for(int i=1; i<n; i++)
        {
            if(st[i]=='1')
            {
                pos1=i;
                break;
            }
        }
        for(int i=1; i<n; i++)
        {
            if(ed[i]=='1')
            {
                pos2=i;
                break;
            }
        }
        if(pos1>pos2) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    else cout<<"YES"<<endl;
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int T;
    cin>>T;
    while(T--) solve();
	return 0;
}
