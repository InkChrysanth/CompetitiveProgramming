#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &t) {
    t = 0;
    char ch = getchar();
    int f = 1;
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    do {
        (t *= 10) += ch - '0';
        ch = getchar();
    } while ('0' <= ch && ch <= '9');
    t *= f;
}
const int N = 500010, M = 100010;
typedef long long ll;
typedef unsigned long long ull;
mt19937_64 rnd(time(0));
int n, m, V, a[100010], b[100010], c[500010];
ll state;

int e[N];
ull f[N];
int l[N], r[N];

unordered_map<ull, ll> v;

int main() {
    freopen("cycle.in", "r", stdin);
    freopen("cycle.out", "w", stdout);
    read(n), read(m), read(V), read(state);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        state = (state * 1103515245 + 12345) % (1LL << 31);
        c[i] = 1 + ((state / 10) % V);
        sum += c[i];
        cerr << c[i] << ' ';
    }
    cerr << endl;
    for (int i = 1; i <= m; i++) {
        state = (state * 1103515245 + 12345) % (1LL << 31);
        a[i] = ((state / 10) % n);
        state = (state * 1103515245 + 12345) % (1LL << 31);
        b[i] = ((state / 10) % n);
        cerr << a[i] << ' ' << b[i] << endl;
    }

    for (int i = 1; i <= m; i++)
        if (a[i] > b[i])
            swap(a[i], b[i]);
    for (int i = 1; i <= m; i++) e[a[i]]++, e[b[i]]--;
    for (int i = 1; i <= m; i++) {
        ull u = rnd();
        f[a[i]] ^= u;
        f[b[i]] ^= u;
    }
    ll ans = 0;
    for (int i = 0, t = 0; i < n - 1; i++) {
        t += e[i];
        if (t)
            ans += c[i];
    }

    ull t = 0;
    for (int i = 0; i < n - 1; i++) {
        t ^= f[i];
        v[t] += c[i];
    }

    for (auto i : v) ans = min(ans, sum - i.second);
    cout << ans << endl;
    return 0;
}
