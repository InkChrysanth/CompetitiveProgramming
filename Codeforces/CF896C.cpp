//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define cmin(i,j) (i)=min((i),(j))
#define cmax(i,j) (i)=max((i),(j))
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define Fi(s) freopen(s,"r",stdin)
#define Fo(s) freopen(s,"w",stdout)
#define Fre(s) Fi(s".in"),Fo(s".out")
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
constexpr int N=100010;

int n, m, seed, vmax;
int a[N];

struct Node
{
	int l, r;
	mutable int v;
	Node(int l): l(l) {}
	Node(int l, int r, int v): l(l), r(r), v(v) {}
	bool operator<(const Node &T)const { return l<T.l; }
};

set<Node> odt;

auto split(int pos)
{
	auto it=prev(odt.upper_bound(Node(pos)));
	if(it->l==pos) return it;
	int l=it->l, r=it->r, v=it->v;
	odt.erase(it);
	odt.emplace(Node(l, pos-1, v));
	return odt.emplace(Node(pos, r, v)).fi;
}

void assign(int l, int r, int v)
{
	auto itr=split(r+1), itl=split(l);
	odt.erase(itl, itr);
	odt.emplace(Node(l, r, v));
}

void add(int l, int r, int v)
{
	auto itr=split(r+1), itl=split(l);
	for(; itl!=itr; ++itl) itl->v+=v;
}

int rank_k(int l, int r, int k)
{
	vector<pii> vec;
	auto itr=split(r+1), itl=split(l);
	for(; itl!=itr; ++itl) vec.emplace_back(mp(itl->v, itl->r-itl->l+1));
	sort(all(vec));
	each(i, vec) if((k-=i.se)<=0) return i.fi;
	return -1;
}

int qmi(int a, int k, int p)
{
	a%=p;
	int res=1;
	while(k)
	{
		if(k&1) res=res*a%p;
		a=a*a%p;
		k>>=1;
	}
	return res;
}

int query(int l, int r, int k, int p)
{
	auto itr=split(r+1), itl=split(l);
	int res=0;
	for(; itl!=itr; ++itl)
		(res+=qmi(itl->v, k, p)*(itl->r-itl->l+1)%p)%=p;
	return res;
}

int rnd()
{
	int ret=seed;
	seed=(seed*7+13)%1000000007;
	return ret;
}


signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>seed>>vmax;
	for(int i=1; i<=n; i++)
	{
		a[i]=(rnd()%vmax)+1;
		odt.emplace(Node(i, i, a[i]));
	}
	for(int i=1, opt, l, r, x, y; i<=m; i++)
	{
		opt=(rnd()%4)+1, l=(rnd()%n)+1, r=(rnd()%n)+1;
		if(l>r) swap(l, r);
		if(opt==3) x=(rnd()%(r-l+1))+1;
		else x=(rnd()%vmax)+1;
		if(opt==4) y=(rnd()%vmax)+1;
		switch(opt)
		{
			case 1:
				add(l, r, x);
				break;
			case 2:
				assign(l, r, x);
				break;
			case 3:
				cout<<rank_k(l, r, x)<<endl;
				break;
			case 4:
				cout<<query(l, r, x, y)<<endl;
				break;
			default: break;
		}
	}
	return 0;
}
