#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5, M = 2e5 + 5;
int n, m, x[M], y[M], a[N][N], b[N][N];
vector<int>v[N];
void dfs(int x, int tp, int* c) {
	if (c[x]) return;
	c[x] = tp;
	for (int y : v[x]) dfs(y, tp, c);
}
signed main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
		scanf("%d%d", &x[i], &y[i]), v[x[i]].push_back(y[i]);
	for (int i = 1; i <= n; i++) {
		a[i][i] = b[i][i] = 1;
		for (int j : v[i]) dfs(j, j, a[i]);
		reverse(v[i].begin(), v[i].end());
		for (int j : v[i]) dfs(j, j, b[i]);
	}
	for (int i = 1; i <= m; i++)
		puts((a[x[i]][y[i]] != b[x[i]][y[i]]) ^ (a[y[i]][x[i]] > 0) ? "diff" : "same");
	return 0;
}
