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
    cout<<fixed<<setprecision(2);
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
constexpr int N=10;

struct Node
{
    ld w, x;
    Node(ld w, ld x): w(w), x(x){}
};

int n;
ld nc, nd;
ld c, d1, d2;
ld d[N], w[N];
deque<Node> q;

signed main()
{
	setIO();
    // d2: the distance can be travelled per litre of fuel
    cin>>d1>>c>>d2>>w[0]>>n;
    for(int i=1; i<=n; i++) cin>>d[i]>>w[i];
    d[n+1]=d1;
    q.push_back(Node(w[0], nc=c));
    ld ans=w[0]*c;
    for(int i=1; i<=n+1; i++)
    {
        if(d[i]-d[i-1]>c*d2) return cout<<"No Solution"<<endl, 0;
        nd=(d[i]-d[i-1])/d2;
        while(nd>0)
        {
            auto t=q.front(); q.pop_front();
            if(t.x>nd)
            {
                nc-=nd;
                q.push_front(Node(t.w, t.x-nd));
                break;
            }
            nc-=t.x, nd-=t.x;
        }
        while(q.size() && q.back().w>w[i])
        {
            auto t=q.back(); q.pop_back();
            ans-=t.x*t.w;
            nc-=t.x;
        }
        ans+=(c-nc)*w[i];
        q.push_back(Node(w[i], c-nc));
        nc=c;
    }
    while(q.size())
    {
        ans-=q.back().x*q.back().w;
        q.pop_back();
    }
    cout<<ans<<endl;
    return 0;
}
// data structures, greedy, implementation