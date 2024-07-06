//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#include <bits/stdc++.h>
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define Fi(s) freopen(s,"r",stdin)
#define Fo(s) freopen(s,"w",stdout)
#define Fre(s) Fi(s".in"),Fo(s".out")
#define all(s) s.begin(), s.end()
#define For(i,j,k) for(int i=(j),i##_=(k);i<=i##_;i++)
#define Rep(i,j,k) for(int i=(j),i##_=(k);i>=i##_;i--)
#define fi first
#define se second
#define rd read
#define endl '\n'
#define mp make_pair
#define eb emplace_back
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl

using namespace std;

typedef long long ll;
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

const int N=200010;

int n, m;
priority_queue<int, vector<int>, greater<int>> heap;
priority_queue<pii, vector<pii>, greater<pii>> a;
ll ans[N];

signed main()
{
	cin.tie(0); cout.tie(0);
	rd(n, m);
    For(i, 1, n) heap.push(i);
    // debug(heap.top());
    For(i, 1, m)
    {
        ll t, w, s;
        rd(t, w, s);
        while(a.size())
        {
            auto v=a.top();
            if(t>=v.fi)
            {
                a.pop();
                heap.push(v.se);
            }
            else break; 
        }
        if(heap.size())
        {
            int u=heap.top();
            heap.pop();
            ans[u]+=w;
            a.push(mp(t+s, u));
        }
    }
    For(i, 1, n) cout<<ans[i]<<endl;
	return 0;
}
