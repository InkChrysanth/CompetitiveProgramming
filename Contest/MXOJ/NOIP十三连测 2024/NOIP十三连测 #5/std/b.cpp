#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353, MAXN = 600;
int qpow(int a, int b) {
	int ans = 1;
	while (b) {
		if (b & 1ll) ans = ans * a % mod;
		a = a * a % mod;
		b = b / 2ll;
	}
	return ans;
}
int n;
int l[MAXN + 5], r[MAXN + 5];
int re[MAXN * 2 + 5], rcnt;
int dp[MAXN + 5][MAXN * 2 + 5], C[MAXN * 2 + 5];
signed main() {
	scanf("%lld", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%lld%lld", &l[i], &r[i]);
		re[++ rcnt] = l[i];
		re[++ rcnt] = ++ r[i];
	}
	sort(re + 1, re + rcnt + 1);
	rcnt = unique(re + 1, re + rcnt + 1) - re - 1;
	for (int i = 1; i <= n; i ++) {
		l[i] = lower_bound(re + 1, re + rcnt + 1, l[i]) - re;
		r[i] = lower_bound(re + 1, re + rcnt + 1, r[i]) - re;
	}
    dp[0][rcnt] = 1; re[rcnt + 1] = 114514;
    for (int i = 1; i < rcnt; i ++) dp[0][i] = 1;
    for (int i = 1; i <= n; i ++) {
        for (int j = l[i]; j < r[i]; j ++) {
            int len = re[j + 1] - re[j];
            C[1] = len;
            for (int k = 2; k <= i; k ++)
                C[k] = C[k - 1] * (len + k - 1) % mod * qpow(k, mod - 2) % mod;
            for (int k = i - 1; k >= 0; k --) {
                dp[i][j] = (dp[i][j] + dp[k][j + 1] * C[i - k] % mod) % mod;
                if (j < l[k] || j >= r[k]) break;
            }
        }
        for (int j = rcnt - 1; j >= 1; j --) dp[i][j] = (dp[i][j] + dp[i][j + 1]) % mod;
    }
    int ans = dp[n][1];
    cout<<ans;
	return 0;
}
