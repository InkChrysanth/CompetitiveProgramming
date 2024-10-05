#include <bits/stdc++.h>
using namespace std;

int n, m;
int u[8005], v[8005], w[8005], dis[8005];

inline bool bf() { // minus ring
    for (int i = 1; i <= n; i++) dis[i] = 0x3f3f3f3f;
    dis[1] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (dis[v[j]] > dis[u[j]] + w[j]) {
                dis[v[j]] = dis[u[j]] + w[j];
                if (i == n) return true;
            }
        }
    }
    return false;
}

int main() {
//	freopen("1.in","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    char c;
    for (int i = 1; i <= m; i++) {
        cin >> u[i] >> v[i] >> c;
        if (c == '(') w[i] = 1;
        else w[i] = -1;
    }
    bool a = bf();
    for (int i = 1; i <= m; i++) w[i] = -w[i];
    bool b = bf();
    if ((a && b) || (!a && !b)) puts("Yes");
    else puts("No");
    return 0;
}
