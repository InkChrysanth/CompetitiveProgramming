//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#include <bits/stdc++.h>
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define Fi(s) freopen(s,"r",stdin)
#define Fo(s) freopen(s,"w",stdout)
#define Fre(s) Fi(s".in"),Fo(s".out")
#define all(x) x.begin(), x.end()
#define For(i,j,k) for(int i=(j),i##_=(k);i<=i##_;i++)
#define Rep(i,j,k) for(int i=(j),i##_=(k);i>=i##_;i--)
#define each(i,x) for(auto &i:(x))
#define fi first
#define se second
#define rd read
#define endl '\n'
#define mp make_pair
#define mtp make_tuple
#define pb push_back
#define eb emplace_back
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3fll;

int dx[]={0, 0, 1, 0, -1, 1, 1, -1, -1};
int dy[]={0, 1, 0, -1, 0, 1, -1, 1, -1};

template <typename T>
void read(T &x)
{
	x=0; char ch=getchar(); ll f=1;
	while(!isdigit(ch))
	{
		if(ch=='-') f*=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=x*10+(ch^48);
		ch=getchar();
	}
	x*=f;
}
template <typename T, typename...Args>
void read(T &first, Args &...args)
{
	read(first);
	read(args...);
}

const int N=110, M=100010;
int n;
int col[N][N][N];
set<int> ans[M];

signed main()
{
	cin.tie(0); cout.tie(0);
	rd(n);
    For(c, 1, n)
    {
        int x1, y1, z1, x2, y2, z2;
        rd(x1, y1, z1, x2, y2, z2);
        For(i, x1, x2-1) For(j, y1, y2-1) For(k, z1, z2-1)
            col[i][j][k]=c;
    }
    For(i, 0, 100) For(j, 0, 100) For(k, 0, 100)
    {
        if((col[i][j][k]!=col[i+1][j][k]) && col[i+1][j][k] && col[i][j][k])
        {
            ans[col[i][j][k]].insert(col[i+1][j][k]);
            ans[col[i+1][j][k]].insert(col[i][j][k]);
        }
        if((col[i][j][k]!=col[i][j+1][k]) && col[i][j+1][k] && col[i][j][k])
        {
            ans[col[i][j][k]].insert(col[i][j+1][k]);
            ans[col[i][j+1][k]].insert(col[i][j][k]);
        }
        if((col[i][j][k]!=col[i][j][k+1]) && col[i][j][k+1] && col[i][j][k])
        {
            ans[col[i][j][k]].insert(col[i][j][k+1]);
            ans[col[i][j][k+1]].insert(col[i][j][k]);
        }
    }
    For(i, 1, n) cout<<ans[i].size()<<endl;
	return 0;
}