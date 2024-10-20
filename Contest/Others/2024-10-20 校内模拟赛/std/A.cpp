#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
char s[100005];
int n, d, p, D, hsh[100005], cnt2, cnt5, t;
int f1[100005], f2[100005], sm1[1000005], sm2[1000005];
void work() {
    scanf("%s%d", s + 1, &d);
    n = strlen(s + 1);
    cnt2 = cnt5 = 0;
    D = d;
    p = 1;
    while (d % 2 == 0) d /= 2, p *= 2, cnt2++;
    while (d % 5 == 0) d /= 5, p *= 5, cnt5++;
    t = max(cnt2, cnt5);
    for (int i = n, pw = 1; i > 0; i--, pw = pw * 10 % d) hsh[i] = (hsh[i + 1] + (s[i] - '0') * pw) % d;
    f1[0] = 1;
    f2[0] = 0;
    sm1[hsh[1]] = !t;
    for (int i = 1, sum = 1; i <= n; i++) {
        f2[i] = sum;
        int v = 0;
        for (int j = 0, pw = 1; j < i && j < t; j++, pw = 10 * pw % D) {
            v = (v + pw * (s[i - j] - '0')) % D;
            if (!v) {
                f1[i] = (f1[i] + f2[i - j - 1]) % mod;
                f1[i] = (f1[i] + f1[i - j - 1]) % mod;
                f2[i] = (f2[i] + mod - f1[i - j - 1]) % mod;
            }
        }
        if (v % p == 0) {
            f1[i] = (f1[i] + sm2[hsh[i + 1]]) % mod;
            f1[i] = (f1[i] + sm1[hsh[i + 1]]) % mod;
            f2[i] = (f2[i] + mod - sm1[hsh[i + 1]]) % mod;
        }
        sum = (sum + f1[i]) % mod;
        if (i >= t) {
            sm1[hsh[i - t + 1]] = (sm1[hsh[i - t + 1]] + f1[i - t]) % mod;
            sm2[hsh[i - t + 1]] = (sm2[hsh[i - t + 1]] + f2[i - t]) % mod;
        }
    }
    printf("%d\n", (f1[n] + f2[n]) % mod);
    for (int i = 1; i <= n + 1; i++) sm1[hsh[i]] = sm2[hsh[i]] = 0, hsh[i] = f1[i] = f2[i] = 0;
}
int main() {
    freopen("digit.in", "r", stdin);
    freopen("digit.out", "w", stdout);
    int tasd;
    for (scanf("%d", &tasd), 1; tasd--;) work();
}
