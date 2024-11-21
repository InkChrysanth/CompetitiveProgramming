#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template <typename T>
void chkmx(T &x, T y) { x = max(x, y); }
struct Cow
{
    ll w, s;
} a[50020];
int n;
int main()
{
    freopen("acro.in", "r", stdin);
    freopen("acro.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].w >> a[i].s;
    sort(a + 1, a + n + 1, [&](Cow a, Cow b)
         { return max(-a.s, a.w - b.s) < max(-b.s, b.w - a.s); });
    ll W = 0, ans = -1e9;
    for (int i = 1; i <= n; i++)
    {
        chkmx(ans, W - a[i].s);
        W += a[i].w;
    }
    cout << ans << endl;
    return 0;
}