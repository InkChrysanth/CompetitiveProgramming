// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#include <bits/stdc++.h>
#define y0 y114514
#define y1 y1919810
#define Fi(s) freopen(s,"r",stdin)
#define Fo(s) freopen(s,"w",stdout)
#define Fre(s) Fi(s".in"),Fo(s".out")
#define For(i,j,k) for(int i=(j),i##_=(k);i<=i##_;i++)
#define Rep(i,j,k) for(int i=(j),i##_=(k);i>=i##_;i--)
#define all(s) s.begin(), s.end()
#define fi first
#define se second
#define rd read
#define endl '\n'
#define mp make_pair
#define eb emplace_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;

const int inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3fll;

int dx[]={0, 1, 0, -1, 1, 1, -1, -1};
int dy[]={1, 0, -1, 0, 1, -1, 1, -1};

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

const int N=1000010;
list<int> q[N];

signed main()
{
	cin.tie(0); cout.tie(0);
	int T; rd(T);
    while(T--)
    {
        string op; cin>>op;
        if(op=="push_back")
        {
            int k, x; rd(k, x);
            q[k].push_back(x);
        }
        if(op=="pop_back")
        {
            int k; rd(k);
            if(!q[k].empty()) q[k].pop_back();
        }
        if(op=="push_front")
        {
            int k, x; rd(k, x);
            q[k].push_front(x);
        }
        if(op=="pop_front")
        {
            int k; rd(k);
            if(!q[k].empty()) q[k].pop_front();
        }
        if(op=="size")
        {
            int k; rd(k);
            cout<<q[k].size()<<endl;
        }
        if(op=="front")
        {
            int k; rd(k);
            if(!q[k].empty()) cout<<q[k].front()<<endl;
        }
        if(op=="back")
        {
            int k; rd(k);
            if(!q[k].empty()) cout<<q[k].back()<<endl;
        }
    }
	return 0;
}
