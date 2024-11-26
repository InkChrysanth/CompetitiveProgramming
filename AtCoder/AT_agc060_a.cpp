//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

#define cmin(i,j) (i)=min((i),(j))
#define cmax(i,j) (i)=max((i),(j))
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
constexpr int N=5010, mod=998244353;

int n;
string s;
int f[N][30][30];

signed main()
{
	setIO();
	cin>>n>>s; s="%"+s;
    f[0][26][26]=1;
    //f_{i,j,k} i, i-1
	for(int i=1; i<=n; i++)
        for(int j=0; j<=26; j++)
            for(int k=0; k<=26; k++)
                if(f[i-1][k][j])
                    for(int l=0; l<26; l++)
                        if((s[i]=='?' || s[i]=='a'+l) && l!=j && l!=k)
                            (f[i][l][k]+=f[i-1][k][j])%=mod;
    int ans=0;
    for(int i=0; i<26; i++) for(int j=0; j<26; j++)
        (ans+=f[n][i][j])%=mod;
    cout<<ans<<endl;
    return 0;
}
// dp