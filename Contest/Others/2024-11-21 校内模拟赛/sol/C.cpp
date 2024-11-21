#include<bits/stdc++.h>
#define node pair<int,int>
#define x second
#define dis first
#define int long long
using namespace std;
int const N = 233333, MOD = 1000000007, INF = 0x3f3f3f3f3f3f3f3fll;
int n, m, s, t, ans, d1[N], d2[N], f1[N], f2[N], vis[N];
struct edge { int x, y, w; };
vector<edge>v;
vector<int>e[N], w[N];
priority_queue<node, vector<node>, greater<node> >q;
inline void solve(int s, int* d, int* f) {
	for (int i = 1; i <= n; i++)
		d[i] = INF, f[i] = vis[i] = 0;
	q.push({ d[s] = 0,s }), f[s] = 1;
	while (!q.empty()) {
		node t = q.top(); q.pop();
		vis[t.x] = 1;
		for (int i = 0; i < e[t.x].size(); i++) {
			int y = e[t.x][i], k = w[t.x][i];
			if (d[y] == t.dis + k)
				f[y] = (f[y] + f[t.x]) % MOD;
			if (d[y] > t.dis + k) {
				f[y] = f[t.x];
				if (!vis[y])
					q.push({ d[y] = t.dis + k,y });
			}
		}
	}
}
signed main() {
	ios::sync_with_stdio(0);
	cin >> n >> m >> s >> t;
	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		e[a].push_back(b);
		e[b].push_back(a);
		w[a].push_back(c);
		w[b].push_back(c);
		v.push_back({ a,b,c });
		v.push_back({ b,a,c });
	}
	solve(s, d1, f1);
	solve(t, d2, f2);
	ans = f1[t] * f1[t] % MOD;
	for (int i = 1; i <= n; i++)
		if (d1[i] + d2[i] == d1[t] && d1[i] == d2[i])
			ans = (ans - f1[i] * f1[i] % MOD * f2[i] % MOD * f2[i] % MOD + MOD) % MOD;
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].x, y = v[i].y, d = v[i].w;
		if (d1[x] + d + d2[y] == d1[t] && d1[x] + d > d2[y] && d1[x] < d + d2[y])
			ans = (ans - f1[x] * f1[x] % MOD * f2[y] % MOD * f2[y] % MOD + MOD) % MOD;
	}
	cout << ans << "\n";
}
