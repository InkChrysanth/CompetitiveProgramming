//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

#define cmin(i,t) (i)=min((i),(t))
#define cmax(i,t) (i)=max((i),(t))
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
constexpr int N=310;

int n;
int w[N][N];
bool st[N][N];

signed main()
{
	setIO();
    cin>>n;
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++)
        cin>>w[i][j];
    for(int k=1; k<=n; k++) for(int i=1; i<=n; i++) for(int j=1; j<=n; j++)
    {
        if(w[i][j]>w[i][k]+w[k][j]) return cout<<-1<<endl, 0;
        if(w[i][j]==w[i][k]+w[k][j] && k!=i && k!=j)
	        st[i][j]=1;
	}
    // for(int i=1; i<=n; i++, cerr<<endl) for(int j=1; j<=n; j++) cerr<<st[i][j]<<" ";
	ll ans=0;
	for(int i=1; i<=n; i++) for(int j=i+1; j<=n; j++) if(!st[i][j]) ans+=w[i][j];
    cout<<ans<<endl;
	return 0;
}
// graphs, brute force