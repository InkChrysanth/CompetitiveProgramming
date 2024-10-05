#include <bits/stdc++.h>
using namespace std;

const int N = 18;

int w[N][N], c[N][N], n, m, W[1<<N][N], C[1<<N][N], S;
int answ = 1e9, ansid[N], id[N], p[N];

void dfs(int s, int k, int pw, int pc) {
    int t = (S^s)|(1<<id[k]);

    if (pw + W[t][id[k]] > answ || pc + C[t][id[k]] > m) {
        return;
    }

    if (k == n - 1) {
        if (pw < answ) {
            answ = pw;

            for (int i = 0; i < n; i++) {
                ansid[i] = id[i];
            }
        } else if (pw == answ) {
            for (int i = 0; i < n; i++) {
                if (id[i] < ansid[i]) {
                    for (int j = 0; j < n; j++) {
                        ansid[j] = id[j];
                    }

                    return;
                } else if (id[i] > ansid[i]) {
                    return;
                }
            }
        }

        return;
    }

    for (int i = 0; i < n; i++) {
        if (!(s&(1<<p[i]))) {
            id[k + 1] = p[i];
            dfs(s|(1<<p[i]), k + 1, pw + w[id[k]][p[i]], pc + c[id[k]][p[i]]);
        }
    }
}

int main() {
    cin>>n>>m;
    S = (1<<n) - 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin>>w[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin>>c[i][j];
        }
    }

    memset(W, 0x3f, sizeof(W));
    memset(C, 0x3f, sizeof(C));

    for (int i = 0; i < n; i++) {
        W[1<<i][i] = C[1<<i][i] = 0;
        p[i] = i;
    }

    for (int t, s = 1; s < (1<<n); s++) {
        for (int u = 0; u < n; u++) {
            if (s&(1<<u)) {
                for (int v = 0; v < n; v++) {
                    t = s|(1<<v);
                    W[t][v] = min(W[t][v], W[s][u] + w[v][u]);
                    C[t][v] = min(C[t][v], C[s][u] + c[v][u]);
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        random_shuffle(p, p + n);
        id[0] = i;
        dfs(1<<i, 0, 0, 0);
    }

    if (answ == 1e9) {
        cout<<-1<<'\n';
    } else {
        cout<<answ<<'\n';

        for (int i = 0; i < n; i++) {
            cout<<ansid[i] + 1<<' ';
        }
    }
}