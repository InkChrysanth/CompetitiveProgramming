#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int MAXN = 5010,mod = 998244353;
void add(ll& x,ll y){x = (x+y>=mod)?(x+y-mod):(x+y);}

int n,b[MAXN],tag[MAXN],top[MAXN],par[MAXN];
vector<int>e[MAXN];

ll dp[MAXN][2],g[2];

int fa[4];
void init(){fa[0]=0,fa[1]=1,fa[2]=2,fa[3]=3;}
int find(int x){return (fa[x]^x)?(fa[x]=find(fa[x])):(x);}
int mg(int x,int y){
	x=find(x),y=find(y);if(x==y)return 0;
	return fa[x]=y,1;
}
int chk(int x,int y){return find(x)==find(y);}

void merge(int u,int v){ //合并dp数组
	g[0] = g[1] = 0;

	rep(x,0,1)if(dp[u][x])rep(y,0,1)if(dp[v][y]){
		ll vx=dp[u][x],vy=dp[v][y];
		int bi = tag[u] && tag[v],ci = tag[u] && !tag[v],di = !tag[u] && tag[v];
		rep(a,0,1)rep(b,0,bi)rep(c,0,ci)rep(d,0,di){
			//既不能出现环,也不能出现不连通
			init();
			if(x)mg(0,1); if(y)mg(2,3);
			if(a && !mg(0,2))continue;
			if(b && !mg(1,3))continue;
			if(c && !mg(1,2))continue;
			if(d && !mg(0,3))continue;

			if(!chk(2,0) && !chk(2,1))continue;
			if(tag[v] && !chk(3,0) && !chk(3,1))continue;

			g[chk(0,1)] += vx*vy;
		}
	}

	dp[u][0] = g[0]%mod,dp[u][1] = g[1]%mod;
}

void calc(int u){
	dp[u][0] = 1;dp[u][1] = 0;
	for(auto v:e[u])if(v^par[u])merge(u,v);
}

void dfs(int u){
	for(auto v:e[u])if(v^par[u]){
		par[v]=u,dfs(v);
	}
	calc(u);
}


int main(){
	cin>>n;
	rep(i,1,n-1){
		int u,v;cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	rep(i,1,n-1)cin>>b[i];

	dfs(1);

	rep(i,1,n-1){
		tag[b[i]] = 1;

		for(int p=b[i];p;p=par[p])calc(p);

		ll ans = dp[1][tag[1]];
		cout<<ans<<"\n";
	}

    return 0;
}
