#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, q, lc[N], rc[N], f[N][20], ans, mx[N], mn[N], g[N];

int t[N], a[N], st[N], ed[N], dfn, b[N], id[N];

void dfs_(int u) {
    if (!u) return;

    st[u] = dfn + 1;
    dfs_(lc[u]), id[u] = ++dfn, dfs_(rc[u]);
    a[id[u]] = b[u];
    ed[u] = dfn, mx[u] = mn[u] = b[u], g[u] = 1;

    if (lc[u]) {
        g[u] &= g[lc[u]];

        if (mx[lc[u]] > b[u]) g[u] = 0;

        mx[u] = max(mx[u], mx[lc[u]]);
        mn[u] = min(mn[u], mn[lc[u]]);
    } 

    if (rc[u]) {
        g[u] &= g[rc[u]];

        if (mn[rc[u]] < b[u]) g[u] = 0;

        mx[u] = max(mx[u], mx[rc[u]]);
        mn[u] = min(mn[u], mn[rc[u]]);
    }

    ans += g[u];
}

void upd_(int x, int k) {
    for (; x <= n; x += x&-x)
        t[x] += k;
}

int ask_(int x, int res = 0) {
    for (; x; x -= x&-x)
        res += t[x];
    
    return res;
}

void work_(int x, int op) {
    if (x < n && a[x] > a[x + 1])
        upd_(x, op);
    
    if (1 < x && a[x] < a[x - 1])
        upd_(x - 1, op);
}

bool chk_(int x) {
    return ask_(ed[x] - 1) - ask_(st[x] - 1) == 0;
}

int calc_(int x, int res = 0) {
    if (!chk_(x)) return 0;

    res = 1;

    for (int k = 19; k >= 0; k--)
        if (f[x][k] && chk_(f[x][k]))
            x = f[x][k], res += 1<<k;
    
    return res;
}

int main() {
    scanf("%d%d", &n, &q);

    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &lc[i], &rc[i]);
        
        if (lc[i])
            f[lc[i]][0] = i;

        if (rc[i])  
            f[rc[i]][0] = i;
    }

    for (int k = 1; k < 20; k++)
        for (int i = 1; i <= n; i++)
            f[i][k] = f[f[i][k - 1]][k - 1];

    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]);

    dfs_(1);

    for (int i = 1; i < n; i++)
        if (a[i] > a[i + 1])
            upd_(i, 1);

    for (int x, val, i = 1; i <= q; i++) {
        scanf("%d%d", &x, &val);
        ans -= calc_(x);
        work_(id[x], -1), a[id[x]] = val, work_(id[x], 1);
        ans += calc_(x);
        printf("%d\n", ans);
    }
}