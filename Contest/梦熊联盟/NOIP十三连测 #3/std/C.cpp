#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define R(i, l, r) for (int i = (l); i <= (r); ++i)
#define int ll
const int N = 2e5 + 5, P = 1e9 + 7;
int n, dis1[N], dis2[N], pw[N] = {1}, cnt[N], ans;
vector <int> E[N];
void dfs(int x, int *dis, int fa)
{
    for (auto v : E[x])
    {
        if (v == fa) continue;
        dis[v] = dis[x] + 1;
        dfs(v, dis, x);
    }
}
int rt1 = -1, rt2 = -1;
void solve1()
{
    int t = 0;
    R(i, 1, n)
    {
        if (i == rt1 || i == rt2) continue;
        t = max(t, min(dis1[i], dis2[i]));
        cnt[max(dis1[i], dis2[i])]++;
    }
    R(i, 1, n) cnt[i] += cnt[i - 1];
    R(i, t, dis2[rt2])
    {
        ans += i * (pw[cnt[i]] - (i == t ? 0 : pw[cnt[i - 1]]) + P) % P;
        ans %= P;
    }
    (ans *= 2) %= P;
    (ans += dis2[rt2] * pw[n - 1] % P) %= P;
}
void solve2()
{
    int t = 0;
    R(i, 1, n)
    {
        t = max(t, min(dis1[i], dis2[i]));
        cnt[max(dis1[i], dis2[i])]++;
    }
    R(i, 1, n) cnt[i] += cnt[i - 1];
    R(i, 0, t - 1) (ans += pw[n]) %= P;
    R(i, t, dis2[rt2] - 1)
    {
        ans += (pw[n] - pw[cnt[i] + 1] + P) % P; // cnt[i]+1等于提前乘了最后的2
        ans %= P;
    }
}
signed main()
{
    cin >> n;
    R(i, 1, n) pw[i] = pw[i - 1] * 2 % P;
    R(i, 1, n - 1) 
    {
        int u, v; cin >> u >> v;
        E[u].push_back(v), E[v].push_back(u);
    }
    dfs(1, dis1, 0);
    R(i, 1, n) if (rt1 == -1 || dis1[i] > dis1[rt1]) rt1 = i;
    dfs(rt1, dis2, 0);
    R(i, 1, n) if (rt2 == -1 || dis2[i] > dis2[rt2]) rt2 = i;
    dis1[rt2] = 0;
    dfs(rt2, dis1, 0);
    // solve1,2 分别表示两种方式
    solve1(); 
    // solve2();
    cout << ans << endl;
    return 0;
}
