#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int s = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') s = (s << 3) + (s << 1) + ch - '0', ch = getchar();
    return s * f;
}
const int N = 1e5 + 5, inf = 1e9;
#define int long long
int prod = 0;
const int mod = 2.5e9 + 1;
inline int quick_pow(int a, int b) {
    int ret = 1;
    for (; b; b >>= 1, a = a * a % mod)
        if (b & 1)
            ret = ret * a % mod;
    return ret;
}
inline void Min(int &a, int b) {
    if (a > b)
        a = b;
}
int T, n, m, k;
int sum[N], d[2][N], bucx[N], bucy[N], lshy[N];
struct Node {
    int x, y;
} a[N];
signed main() {
    freopen("cannon.in", "r", stdin);
    freopen("cannon.out", "w", stdout);
    T = read();
    while (T--) {
        n = read(), m = read();
        k = read();
        memset(sum, 0, (m + n) << 3);
        for (int i = 1; i <= k; ++i) {
            a[i].x = read();
            a[i].y = read();
            bucx[i] = a[i].x;
            bucy[i] = a[i].y;
        }
        sort(bucx + 1, bucx + 1 + k);
        int kx = unique(bucx + 1, bucx + 1 + k) - bucx - 1;
        sort(bucy + 1, bucy + 1 + k);
        int ky = unique(bucy + 1, bucy + 1 + k) - bucy - 1;
        bucy[ky + 1] = 0;
        int cur = 1, pre = 0;
        for (int i = 1, x; i <= kx; ++i, cur ^= 1, pre ^= 1) {
            memset(d[cur] + 1, 0x3f, m << 3);
            x = bucx[i];
            for (int j = 1; j <= k; ++j) Min(d[cur][a[j].y], abs(a[j].x - x));
            int r = 1;
            d[cur][0] = inf;
            for (int j = ky - 1; j >= 1; --j)
                Min(d[cur][bucy[j]], d[cur][bucy[j + 1]] + bucy[j + 1] - bucy[j]);
            for (int j = 1; j <= ky; ++j) {
                while (abs(bucy[j] - r) + d[cur][bucy[j]] < abs(bucy[j + 1] - r) + d[cur][bucy[j + 1]] &&
                       r <= m) {
                    Min(d[cur][r], abs(bucy[j] - r) + d[cur][bucy[j]]);
                    ++r;
                }
            }
            if (i == 1) {
                for (int j = 1; j <= m; ++j) {
                    ++sum[d[cur][j]];
                    --sum[d[cur][j] + x];
                }
            } else {
                int b = bucx[i] + bucx[i - 1];
                for (int j = 1, p; j <= m; ++j) {
                    p = (b + d[cur][j] - d[pre][j]) >> 1;
                    ++sum[d[pre][j] + 1];
                    --sum[d[pre][j] + p - bucx[i - 1] + 1];
                    ++sum[d[cur][j]];
                    --sum[d[cur][j] + bucx[i] - p];
                }
            }
            if (i == kx && x != n) {
                for (int j = 1; j <= m; ++j) {
                    ++sum[d[cur][j] + 1];
                    --sum[d[cur][j] + n - x + 1];
                }
            }
        }
        int inv = 1, bs = n * m, ans = 1, s = 0, t = 0;
        for (int i = 0; i < n + m && i < n * m; ++i) {
            inv = 1ull * inv * (bs - i) % mod;
            s += sum[i];
            t += s;
            ans = 1ull * ans * (t - i) % mod;
        }
        printf("%llu\n", 1ull * quick_pow(inv, mod - 2) * ans % mod);
    }
    return 0;
}
