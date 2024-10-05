#include <bits/stdc++.h>
#define LL long long
#define int long long
using namespace std;
char ibuf[1 << 15], *p1, *p2;
#define getchar() (p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, 1 << 15, stdin), p1==p2) ? EOF : *p1++)
inline int read() {
  char ch = getchar();  int x = 0, f = 1;
  while (ch < '0' || ch > '9')  {  if (ch == '-')  f = -1;  ch = getchar();  }
  while (ch >= '0' && ch <= '9')  x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  return x * f;
}
void print(LL x) {
  if (x > 9)  print(x / 10);
  putchar(x % 10 + '0');
}
template<class T> bool chkmin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool chkmax(T &a, T b) { return a < b ? (a = b, true) : false; }
#define rep(i, l, r) for (int i = (l); i <= (r); i++)
#define repd(i, l, r) for (int i = (l); i >= (r); i--)
#define REP(i, l, r)  for (int i = (l); i < (r); i++)
const int N = 2e6;
int n, num, nex[N], first[N], v[N], a[N];
char s[N];
void add(int from,int to) {
  nex[++num] = first[from];  first[from] = num;  v[num] = to; 
}
int dep[N], mxdep1[N];
struct node {
  int mx, mx2, id;
  void pre() {  mx = mx2 = id = -1;  }
  void upd(int val,int now) {
    if (val > mx) {  mx2 = mx;  mx = val;  id = now;  }
    else if (val > mx2)  mx2 = val;
  }
} pt[N];
void dfs1(int x,int fa) {
  dep[x] = dep[fa] + 1;
  for (int i = first[x]; i; i = nex[i]) {
    int to = v[i];  if (to == fa)  continue;  dfs1(to, x);
  }
}
int f[N], g[N], mxdep2[N];
void dfs2(int x,int fa) {
  int son = 0;
  mxdep1[x] = 0;  g[x] = f[x] = a[x];
  pt[x].pre();  pt[x].upd(0, x);
  for (int i = first[x]; i; i = nex[i]) {
    int to = v[i];  if (to == fa)  continue;
    dfs2(to, x);  mxdep1[x] = max(mxdep1[x], mxdep1[to] + 1);  f[x] += f[to];
    pt[x].upd(mxdep1[to] + 1, to);
  }
}
void dfs3(int x,int fa) {
  int mx = 0, mx2 = 0, id = 0, id2 = 0;
  if (fa) {
    g[x] = g[fa] + f[fa] - f[x];
    if (x == pt[fa].id) {
      if (pt[fa].mx2 != -1) {
        mxdep2[x] = max(mxdep2[x], pt[fa].mx2 + 1);
        pt[x].upd(pt[fa].mx2 + 1, fa);
      }
    }  else {
      if (pt[fa].mx != -1) {
        mxdep2[x] = max(mxdep2[x], pt[fa].mx + 1);
        pt[x].upd(pt[fa].mx + 1, fa);
      }
    }
  }
  for (int i = first[x]; i; i = nex[i]) {
    int to = v[i];  if (to == fa)  continue;  dfs3(to, x);
  }
}
int ans, sum;
pair <int,int> e[N];
int solveedge(int i) {
  int x = e[i].first, y = e[i].second;
  if (dep[x] > dep[y])  swap(x, y);
  int now;
  if (pt[x].id == y)  now = pt[x].mx2;
  else  now = pt[x].mx;
  if (now == mxdep1[y]) {
    if (sum - f[y] || f[y])  return 1;
    return 0;
  }
  if (now < mxdep1[y]) {
    if (sum - f[y])  return 1;
    return 0;
  }
  if (now > mxdep1[y]) {
    if (f[y])  return 1;
    return 0;
  }
  return 1;
}
int solvever(int x) {
  int son = 0;
  for (int i = first[x]; i; i = nex[i])  son++;
  if (son <= 1)  return a[x];
  int u, d = n + 1, mx = -1, mx2 = -1;
  if (a[x])  d = 0;
  mx = mxdep2[x];
  if (mxdep2[x]  && sum - f[x])  d = min(d, mxdep2[x]);
  for (int i = first[x]; i; i = nex[i]) {
    int to = v[i];
    if (dep[to] < dep[x])  continue;
    if (f[to])  d = min(d, mxdep1[to] + 1);
    if (mxdep1[to] + 1 > mx) {
      mx2 = mx,  mx = mxdep1[to] + 1;
    }  else  if (mxdep1[to] + 1 > mx2) {
      mx2 = mxdep1[to] + 1;
    }
  }
  u = mx2;
  if (d == n + 1 || u < d)  return 0;
  return u - d + 1;
}
void solve() {
  cin >> n;
  rep (i, 2, n) {
    int x, y;  cin >> x >> y;
    add(x, y), add(y, x);
    e[i] = {x, y};
  }
  cin >> (s + 1);
  rep (i, 1, n)  a[i] = s[i] - '0', sum += a[i];
  dfs1(1, 0);  dfs2(1, 0);
  dfs3(1, 0);
  int ans = 0;
  // for (int i = 1; i <= n; i++) {
  //   cout << mxdep1[i] << " " << mxdep2[i] << " " << f[i] << " " << g[i] << " " << pt[i].mx << " " << pt[i].mx2 << " " << pt[i].id << "\n";
  // }
  // cout << "---\n";
  rep (i, 2, n)  ans += solveedge(i);
  // cout << ans << "\n" ;
  rep (i, 1, n)  ans += solvever(i);
  cout << ans << "\n";
}
signed main () {
  int T = 1;  while (T--)  solve();
  return 0;
}
