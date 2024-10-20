#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int B = 13;
ll gcd(ll x, ll y) { return x ? gcd(y % x, x) : y; }
ll pb[B];
bool leading_zero_needed = 0;
ll n;
int b;

namespace subt_small_n {

bool first;
bool u[B];
void ss(ll x, int y, bool lz) {
    if (y == b) {
        if (x % n == 0) {
            if (first) {
                cout << x;
                exit(0);
            } else
                first = 1;
        }
        return;
    }
    if (leading_zero_needed && y == 0) {
        ss(0, 1, 1);
    } else {
        for (int i = b - 1; i >= 0; --i) {
            if (!u[i]) {
                if (i || !lz)
                    u[i] = 1;
                ss(x + i * pb[b - y - 1], y + 1, lz && !i);
                u[i] = 0;
            }
        }
    }
}

}  // namespace subt_small_n

namespace subt_large_n {

bool first;
void ss(ll x, int y, bool lz, int u) {
    //	if(x==0)cerr<<"> "<<x<<" "<<y<<" "<<lz<<endl;
    if (y == b - 5 && n > pb[5] && (x + n - 1) / n * n - x >= pb[5])
        return;
    if (y == b - 4 && n > pb[4] && (x + n - 1) / n * n - x >= pb[4])
        return;
    //	if(x==2625)cerr<<"! "<<x<<" "<<y<<" "<<lz<<"  "<<u<<endl;
    if (y == b - 3) {
        ll z = (x + n - 1) / n * n - x;
        if (z >= b * b * b)
            return;
        ll a[3] = { z / b / b, z / b % b, z % b };
        //		cerr<<"a "<<a[0]<<" "<<a[1]<<" "<<a[2]<<"  "<<!((u>>a[0])&1)<<" "<<!((u>>a[1])&1)<<"
        //"<<!((u>>a[2])&1)<<" "<<endl;
        if (a[1] && a[1] == a[2])
            return;
        if ((a[0] || !lz) && (a[1] == a[2] || a[2] == a[0] || a[0] == a[1]))
            return;
        if ((a[0] || !lz) && !((u >> a[0]) & 1))
            return;
        if ((a[0] || a[1] || !lz) && !((u >> a[1]) & 1))
            return;
        if ((a[0] || a[1] || a[2] || !lz) && !((u >> a[2]) & 1))
            return;
        if (first) {
            cout << x + z;
            exit(0);
        } else
            first = 1;
        return;
    }
    if (leading_zero_needed && y == 0) {
        ss(0, 1, 1, (1 << b) - 1);
    } else {
        int uu = u;
        for (; u;) {
            int i = 31 - __builtin_clz(u);
            ss(x + i * pb[b - y - 1], y + 1, lz && !i, uu ^ ((i || !lz) << i));
            u ^= 1 << i;
        }
    }
}

}  // namespace subt_large_n

int main() {
    freopen("multi.in", "r", stdin);
    freopen("multi.out", "w", stdout);
    cin >> n >> b;
    int g = gcd(n, b - 1);
    int s = b * (b - 1) / 2;
    if (s % g)
        leading_zero_needed = 1;
    if (n % (b * b) == 0)
        return cout << "-1" << endl, 0;
    for (int i = pb[0] = 1; i <= b; i++) pb[i] = pb[i - 1] * b;
    if (n <= b * b * b || b <= 4) {
        subt_small_n::ss(0, 0, 1);
        cout << "-1" << endl;
    } else {
        subt_large_n::ss(0, 0, 1, (1 << b) - 1);
        cout << "-1" << endl;
    }
    exit(0);
}
