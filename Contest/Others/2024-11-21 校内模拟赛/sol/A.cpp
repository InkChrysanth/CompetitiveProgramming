#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<tuple<ll, ll, ll>> vt[100010];
bool tf[100010];
int main(void) {
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < m; i++) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        vt[a].push_back({ b,c,d });
        vt[b].push_back({ a,c,d });
    }
    priority_queue<pair<ll, ll>> pq;
    pq.push({ 0,1 });
    while (!pq.empty()) {
        ll t, a;
        tie(t, a) = pq.top();
        pq.pop();
        if (a == n) {
            cout << -t << endl;
            return 0;
        }
        if (tf[a]) {
            continue;
        }
        tf[a] = true;
        t = -t;
        for (auto [b, c, d] : vt[a]) {
            ll num = 1e18;
            for (ll i = max(t, (ll)sqrt(d) - 2); i <= max(t, (ll)sqrt(d) + 2); i++) {
                num = min(num, i - t + d / (i + 1));
            }
            pq.push({ -t - c - num,b });
        }
    }
    cout << -1 << endl;
    return 0;
}
