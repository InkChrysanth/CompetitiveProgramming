#include <bits/stdc++.h>
#include <bits/extc++.h>
#define int_rd (int)read()
#define ll_rd read()
#define endl '\n'
#define mp make_pair
#define pbds __gnu_pbds
#define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

inline ll read()
{
	ll a=0; int f=0; char p=getchar();
	while(!isdigit(p)){f|=p=='-'; p=getchar();}
	while(isdigit(p)){a=(a<<3)+(a<<1)+(p^48); p=getchar();}
	return f?-a:a;
}

const int N=300010;

int n, m;
vector<pii> g[N];
bool vis[N];

bool sbmH(int x)
{
    memset(vis, false, sizeof vis);
    queue<pii> q;
    q.push(mp(1, 1)); vis[1]=true;
    while(q.size())
    {
    	auto t=q.front(); q.pop();
    	int u=t.first, id=t.second;
    	for(auto p: g[u])
    	{
    		int v=p.first, w=p.second;
    		if(!vis[v] && w*id<=x)
    		{
    			vis[v]=true;
    			q.push(mp(v, id+1));
    		}
    	}
    }
    return vis[n];
}

signed main()
{
	freopen("T3.in", "r", stdin);
	freopen("T3.out", "w", stdout);
    n=int_rd, m=int_rd;
    while(m--)
    {
        int u=int_rd, v=int_rd, w=int_rd;
        g[u].emplace_back(mp(v, w));
    }
    int l=1, r=3e14, ans=0;
    while(l<=r)
    {
    	int mid=(l+r)>>1;
    	if(sbmH(mid))
    	{
    		ans=mid;
    		r=mid-1;
    	}
    	else l=mid+1;
    }
    cout<<ans<<endl;
    return 0;
}