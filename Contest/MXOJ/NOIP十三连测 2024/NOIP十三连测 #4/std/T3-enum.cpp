#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = (1<<4) + 5;

int n, a[N], c[N], cur, pre;

ll f[2][9][9][9][9];

void max_(ll &x, ll y) {
    x = max(x, y);
}

void calc1_(int k) {
    cur ^= 1, pre ^= 1;
    memset(f[cur], -0x3f, sizeof(f[cur]));
    int b[4];
    b[0] = (a[0]>>k)&1;
    b[1] = (a[1]>>k)&1;
    b[2] = (a[2]>>k)&1;
    b[3] = (a[3]>>k)&1;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                for (int l = 0; l < 4; l++) {
                    max_(f[cur][i*2 + b[0]][j*2 + b[1]][k*2 + b[2]][l*2 + b[3]], f[pre][i][j][k][l]);
                }
            }
        }
    }
}

void calc2_(int p, int x) {
    cur ^= 1, pre ^= 1;
    memset(f[cur], -0x3f, sizeof(f[cur]));

    for (int i = 0; i < 8; i++) {
        int i1 = x&1;

        for (int j = 0; j < 8; j++) {
            int j1 = (x>>1)&1;
        
            for (int k = 0; k < 8; k++) {
                int k1 = (x>>2)&1;

                for (int l = 0; l < 8; l++) {
                    int l1 = (x>>3)&1;
                    max_(f[cur][i][j][k][l], f[pre][i][j][k][l]);

                    if (i >= i1 && j >= j1 && k >= k1 && l >= l1) {
                        max_(f[cur][i - i1][j - j1][k - k1][l - l1], f[pre][i][j][k][l] + (1ll<<p)*c[x]);
                    }
                }
            }
        }
    }
}

void work_() {
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    memset(c, 0, sizeof(c));

    for (int i = 1; i < (1<<n); i++) {
        scanf("%d", &c[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    memset(f, -0x3f, sizeof(f));
    cur = 0, pre = 1;
    f[cur][0][0][0][0] = 0;

    for (int i = 30; i >= 0; i--) {
        calc1_(i);

        for (int j = 1; j < 16; j++) {
            calc2_(i, j);
        }
    }

    printf("%lld\n", f[cur][0][0][0][0]);
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        work_();
    }
}