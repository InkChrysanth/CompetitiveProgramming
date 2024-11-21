#include <bits/stdc++.h>
using namespace std;
int fa[200020];
set<int> s[200020];
int F(int u) { return fa[u] ^ u ? fa[u] = F(fa[u]) : u; }
void U(int u, int v)
{
    u = F(u), v = F(v);
    if (u == v)
        return;
    if (s[u].size() > s[v].size())
        swap(u, v);
    fa[u] = v;
    for (int i : s[u])
        s[v].insert(i);
    s[u].clear();
}
int n, q;
int main()
{
    freopen("find.in", "r", stdin);
    freopen("find.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        s[i].insert(i), fa[i] = i;
    while (q--)
    {
        int op, x, y;
        cin >> op >> x >> y;
        if (op & 1)
        {
            U(x, y);
        }
        else
        {
            x = F(x);
            if (s[x].size() < y)
            {
                cout << -1 << '\n';
                continue;
            }
            auto it = s[x].end();
            while (y--)
                it--;
            cout << *it << '\n';
        }
    }
    return 0;
}