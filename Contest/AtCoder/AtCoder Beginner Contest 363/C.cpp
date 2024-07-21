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

bool check(string s)
{
	string t(s.rbegin(), s.rend());
	return s==t;
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    int n, k;
    string s;
    cin>>n>>k>>s;
    int ans=0;
    sort(all(s));
    do
    {
        bool flag=1;
        for(int i=0; i<=n-k; i++)
        {
            if(check(s.substr(i, k)))
            {
                flag=0;
                break;
            }
            
            // i=1
            // j=0 i+j=1
            // k-j-1=1 i+k-j-1=2
            // l<r
            /*
            bool pal=1;
            for(int j=0; j<k-1-j; j++)
            {
                if(s[i+j]!=s[i+k-1-j])
                {
                    pal=0;
                    break;
                }
            }
            if(pal)
            {
                flag=0;
                break;
            }
            */
        }
        if(flag) ans++;
    }while(next_permutation(all(s)));
    
    cout<<ans<<endl;
	return 0;
}
