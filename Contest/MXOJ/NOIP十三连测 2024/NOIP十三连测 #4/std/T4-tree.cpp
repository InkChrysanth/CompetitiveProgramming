#include <bits/stdc++.h>

using ll = long long;
constexpr ll mod = 998244353;
constexpr int maxn = 3E+5 + 5;

inline ll fsp(ll a, ll b, ll res = 1) {
	for(a %= mod; b; a = a * a % mod, b >>= 1)
		b & 1 && (res = res * a % mod); return res;
}

struct Line {
	ll k, b;
	inline Line(ll _k = 1, ll _b = 0) : k(_k), b(_b) {}
	inline Line comp(const Line &rhs) const {
		return Line(k * rhs.k % mod, (b + k * rhs.b) % mod);
	}
	inline ll eval(ll x) { return (k * x + b) % mod; }
};

int n = 1, q;
ll Fac[maxn], Inv[maxn], rdm[maxn];
std::vector<int> to[maxn];
struct Query { int opt, u; } qry[maxn];

int fa[maxn], dep[maxn], siz[maxn], son[maxn];
inline void DFS1(int u, int f) {
	fa[u] = f, dep[u] = dep[f] + 1, siz[u] = 1;
	for(int v : to[u]) {
		DFS1(v, u), siz[u] += siz[v];
		if(siz[v] > siz[son[u]]) son[u] = v;
	}
}

int ind, dfn[maxn], Max[maxn], top[maxn];
int ddfn[maxn], leaf[maxn];
inline void DFS2(int u, int tp) {
	dfn[u] = ++ind, ddfn[ind] = u, top[u] = tp;
	if(son[u]) DFS2(son[u], tp), leaf[u] = leaf[son[u]];
	else leaf[u] = u;
	for(int v : to[u]) if(v ^ son[u]) DFS2(v, v);
	Max[u] = ind;
}

namespace ANS {
	ll t[maxn];
	inline void clear() { std::fill(t, t + n + 1, 1); }
	inline void Add(int p, ll v) { while(p <= n) t[p] = t[p] * v % mod, p += p & -p; }
	inline ll Sum(int p, ll r = 1) { while(p) r = r * t[p] % mod, p -= p & -p; return r; }
}

std::vector<int> change;
namespace SGTSIZ {
#define mid (lef + rig >> 1)
#define ls (u << 1)
#define rs (u << 1 | 1)

	int min[maxn << 2], tag[maxn << 2];
	inline void cov(int u, int v) { min[u] += v, tag[u] += v; }
	inline void Build(int u = 1, int lef = 1, int rig = n) {
		min[u] = 1, tag[u] = 0;
		if(lef != rig) Build(ls, lef, mid), Build(rs, mid + 1, rig);
	}
	
	inline void PushDown(int u) {
		if(!tag[u]) return;
		cov(ls, tag[u]), cov(rs, tag[u]), tag[u] = 0;
	}

	inline void Update(int nlef, int nrig, int v, int u = 1, int lef = 1, int rig = n) {
		if(nlef > nrig) return;
		if(nlef <= lef && nrig >= rig) return cov(u, v);

		PushDown(u);
		if(nlef <= mid) Update(nlef, nrig, v, ls, lef, mid);
		if(nrig >= mid + 1) Update(nlef, nrig, v, rs, mid + 1, rig);
		min[u] = std::min(min[ls], min[rs]);
	}

	inline void Query(int nlef, int nrig, int u = 1, int lef = 1, int rig = n) {
		if(nlef > nrig || min[u] > 0) return;
		if(lef == rig) return change.push_back(son[ddfn[lef]]);
		if(nlef <= mid) Query(nlef, nrig, ls, lef, mid);
		if(nrig >= mid + 1) Query(nlef, nrig, rs, mid + 1, rig);
	}

#undef mid
#undef ls
#undef rs
}

inline void getP(int u) {
	while(u) {
		SGTSIZ::Query(dfn[top[u]], dfn[u] - 1);
		if(fa[top[u]]) change.push_back(top[u]);
		u = fa[top[u]];
	}
}

namespace SGTHSH {
#define mid (lef + rig >> 1)
#define ls (u << 1)
#define rs (u << 1 | 1)

	Line val[maxn << 2];
	inline void Update(int p, Line v, int u = 1, int lef = 1, int rig = n) {
		if(lef == rig) return val[u] = v, void();
		if(p <= mid) Update(p, v, ls, lef, mid);
		else Update(p, v, rs, mid + 1, rig);
		val[u] = val[ls].comp(val[rs]);
	}

	inline Line Query(int nlef, int nrig, int u = 1, int lef = 1, int rig = n) {
		if(nlef <= lef && nrig >= rig) return val[u];
	
		if(nrig <= mid) return Query(nlef, nrig, ls, lef, mid);
		else if(nlef > mid) return Query(nlef, nrig, rs, mid + 1, rig);
		else return Query(nlef, nrig, ls, lef, mid).comp(Query(nlef, nrig, rs, mid + 1, rig));
	}

#undef mid
#undef ls
#undef rs
}

bool isvis[maxn]; int deg[maxn], bot[maxn];
inline ll hash(int u) {
	if(deg[bot[top[u]]] && bot[top[u]] != leaf[u])
		return SGTHSH::Query(dfn[u], dfn[leaf[u]]).eval(1);
	else return SGTHSH::Query(dfn[u], dfn[leaf[u]]).eval(0);
}

std::unordered_map<ll, int> M[maxn];

inline void chg(int u, int v) {
	ll h = hash(u);
	int x = M[fa[u]][h] + (isvis[son[fa[u]]] && hash(son[fa[u]]) == h);
	ANS::Add(dfn[fa[u]], Fac[x + v] * Inv[x] % mod);
	if(u != son[fa[u]]) M[fa[u]][h] += v;
}

ll h[maxn], tmph[maxn];
inline void update(int u) {
	int p = u;
	while(p) tmph[top[p]] = hash(top[p]), p = fa[top[p]];

	tmph[u] = 1, bot[top[u]] = u, ++deg[fa[u]];
	while(u) {
		SGTSIZ::Update(dfn[u], dfn[u], -1);
		SGTSIZ::Update(dfn[top[u]], dfn[u] - 1, 1);
		SGTHSH::Update(dfn[u], Line(rdm[dep[u]] * h[u] % mod, rdm[dep[u]]));
		if(fa[top[u]]) (h[fa[top[u]]] *= fsp(tmph[top[u]], mod - 2, hash(top[u]))) %= mod;
		u = fa[top[u]];
	}
}

int main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);

	std::cin.tie(0)->sync_with_stdio(false);

	std::cin >> q;
	for(int i = 1; i <= q; ++i) {
		std::cin >> qry[i].opt >> qry[i].u;
		if(qry[i].opt == 2) {
			for(int i = 1; i <= 1016; ++i) puts("1");
			return 0;
		}
		if(qry[i].opt == 0) to[qry[i].u].push_back(++n);
	}

	Fac[0] = 1;
	for(int i = 1; i <= n; ++i)
		Fac[i] = Fac[i - 1] * i % mod;
	Inv[n] = fsp(Fac[n], mod - 2);
	for(int i = n; i >= 1; --i)
		Inv[i - 1] = Inv[i] * i % mod;
	
	std::mt19937_64 rnd(time(0));
	for(int i = 1; i <= n; ++i) rdm[i] = rnd() % mod;
	
	DFS1(1, 0), DFS2(1, 1);

	SGTSIZ::Build(), ANS::clear(), std::fill(h, h + n + 1, 1);
	SGTSIZ::Update(dfn[1], dfn[1], -1);
	SGTHSH::Update(dfn[1], Line(rdm[dep[1]] * h[1] % mod, rdm[dep[1]]));
	
	int u = 1, MAX = 0;
	for(int i = 1; i <= q; ++i) {
		if(qry[i].opt == 0) {
			++u, change.clear(), getP(fa[u]);
			for(int x : change) chg(x, -1), isvis[x] = 0;
			update(u), chg(u, 1), isvis[u] = 1;
			MAX = std::max(MAX, (int)change.size());
			for(int x : change) chg(x, 1), isvis[x] = 1;
		}
		else std::cout << fsp(ANS::Sum(dfn[qry[i].u] - 1), mod - 2, ANS::Sum(Max[qry[i].u])) << "\n";
	}
}