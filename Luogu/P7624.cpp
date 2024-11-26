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

ll mid;
struct Node
{
    ll t, k;
    Node(ll t=0, ll k=0): t(t), k(k){}
    Node operator+(const Node &T)const{ return Node(t+T.t, k+T.k); }
    Node operator-(const Node &T)const{ return Node(t-T.t, k-T.k); }
    bool operator<(const Node &T)const{ return t+k*mid<T.t+T.k*mid; }
    bool operator>(const Node &T)const{ return t+k*mid>T.t+T.k*mid; }
};

signed main()
{
	setIO();
	int n, m; cin>>n>>m;
    vector<vector<pair<int, Node>>> g(n+2);
    for(int i=1; i<=m; i++)
    {
        int type, s, t, l;
        cin>>type>>s>>t>>l;
        if(type==1)
        {
            if(s<t) g[t].eb(mp(s, Node(-l, 0)));
            else g[t].eb(mp(s, Node(-l, 1)));
        }
        else
        {
            if(s<t) g[s].eb(mp(t, Node(l, 0)));
            else g[s].eb(mp(t, Node(l, -1)));
        }
    }
    for(int i=1; i<n; i++) g[i+1].eb(mp(i, Node(-1, 0)));
    g[1].eb(mp(n, Node(-1, 1)));
    int S=n+1;
    for(int i=1; i<=n; i++) g[S].eb(mp(i, Node(0, 0)));
    auto spfa=[&]()
    {
        queue<int> q;
        vector<Node> dist(n+2, Node(llinf, 0));
        vector<bool> vis(n+2, false);
        vector<int> cnt(n+2, 0);
        vector<pair<int, Node>> pre(n+2);
        auto get_cycle=[&](int u)
        {
            vector<bool> vis2(n+2, false);
            vector<Node> dist2(n+2, Node(0, 0));
            int cur=u;
            while(true)
            {
                vis2[cur]=true;
                int nxt=pre[cur].fi;
                Node tmp=dist2[cur]+pre[cur].se;
                if(vis2[nxt]) return tmp-dist2[nxt];
                cur=nxt; dist2[cur]=tmp;
            }
        };
        q.push(S);
        vis[S]=true; cnt[S]=1; dist[S]=Node(0, 0);
        while(q.size())
        {
            int u=q.front(); q.pop();
            vis[u]=false;
            each(t, g[u])
            {
                int v=t.fi; Node w=t.se;
                if(dist[v]>dist[u]+w)
                {
                    dist[v]=dist[u]+w;
                    pre[v]=mp(u, w);
                    if(!vis[v])
                    {
                        q.push(v);
                        vis[v]=true;
                        if(++cnt[v]>n+2)
                        {
                            Node p=get_cycle(v);
                            if(p.k>0) return 1;
                            if(p.k<0) return -1;
                            cout<<-1<<endl; exit(0);
                        }
                    }
                }
            }
        }
        return 0;
    };
    ll lo=0, hi=0;
    ll l=1, r=1e12;
    while(l<=r)
    {
        mid=(l+r)>>1;
        int st=spfa();
        if(st==0) hi=mid, l=mid+1;
        else if(st==1) l=mid+1;
        else if(st==-1) r=mid-1;
    }
    if(hi>=9e11) return cout<<-1<<endl, 0;
    l=1, r=1e12;
    while(l<=r)
    {
        mid=(l+r)>>1;
        int st=spfa();
        if(st==0) lo=mid, r=mid-1;
        else if(st==-1) r=mid-1;
        else if(st==1) l=mid+1;
    }
    cout<<hi-lo+1<<endl;
	return 0;
}
// graphs(spfa), binary search