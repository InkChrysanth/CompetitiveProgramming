#include <bits/stdc++.h>
int n, p, sq[10000007], mod = 1e9 + 7;

typedef long long ll; typedef __int128 lll;
struct FastMod { int m; ll b; void init(int _m) { m = _m; b = ((lll)1<<64) / m; } int operator() (ll a) {ll q = ((lll)a * b) >> 64; a -= q * m; if (a >= m) a -= m; return a; } } Mod;
int add(int a, int b) { return (a += b) >= mod ? a - mod : a; } int mul(int a, int b) { return Mod(1ll * a * b); } template <typename ...Args> int mul(int a, Args ...b) { return mul(a, mul(b...)); }

int qp(int a, int b = mod - 2) { 
    int ret = 1; 
    while (b) { 
        if (b & 1) ret = mul(ret, a); 
        a = mul(a, a); 
        b >>= 1; 
    } return ret; 
}

signed main() {
    std::cin >> p >> n; int ans = 1;
    sq[0] = 1; Mod.init(mod);
    for (int i = 1; i <= n; i++) sq[i] = mul(sq[i-1], p);
    for (int i = 0; i < n; i++) ans = mul(ans, sq[n] - sq[i] + mod);
    std::cout << add(mul(ans, qp(p-1)), 1);
}
// https://www.cnblogs.com/joke3579/p/editorial221004.html