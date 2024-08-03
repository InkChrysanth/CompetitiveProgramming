//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define cmin(i,j) (i)=min((i),(j))
#define cmax(i,j) (i)=max((i),(j))
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define Fi(a) freopen(a,"r",stdin)
#define Fo(a) freopen(a,"w",stdout)
#define Fre(a) Fi(a".in"),Fo(a".out")
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

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    string a, b;
    while(cin>>a>>b)
    {
        int n=a.size();
        a=" "+a; b=" "+b;
        vector<vector<int>> f(n+1, vector<int>(n+1));
        for(int len=1; len<=n; len++)
            for(int l=1; l+len-1<=n; l++)
            {
                int r=l+len-1;
                // debug(l); debug(r);
                if(l==r) f[l][r]=1;
                else
                {
                    f[l][r]=inf;
                    for(int k=l; k<=r-1; k++)
                        cmin(f[l][r], f[l][k]+f[k+1][r]);
                    if(b[l]==b[r]) f[l][r]--;
                }
            }
        vector<int> g(n+1);
        for(int i=1; i<=n; i++)
        {
            g[i]=f[1][i];
            if(a[i]==b[i]) g[i]=g[i-1];
            else
            {
                for(int j=1; j<i; j++)
                    cmin(g[i], g[j]+f[j+1][i]);
            }
        }
        cout<<g[n]<<endl;
    }
    
	return 0;
}