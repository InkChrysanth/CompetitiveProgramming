#include<iostream>
using namespace std;
const int maxn = 100001;
int p[maxn];
int v[maxn];
int find(int u) {
  int fa = p[u];
  if (fa == 0) return u;
  int r = find(fa);
  v[u] = (v[fa] + v[u]) % 5;
  p[u] = r;
  return r;
}
int main(){
	freopen("theory.in","r",stdin);
	freopen("theory.out","w",stdout); 
	int n, m;
	cin >> n >> m;
	int ans = 0;
	while (m --> 0) {
		int a, b;
		char c;
		cin >> c >> a >> b;
		int x = find(a);
		int y = find(b);
		if (x == y) {
		   int d = (v[a] - v[b] + 10) % 5;
		   if (c == 'k' and d != 2) ans++;
		   if (c == 's' and d != 1) ans++;
		} else {
		   p[x] = y;
		   int d = (c == 'k') ? 2 : 1;
		   v[x] = (-v[a] + d + v[b]) % 5;
		}
	}
	cout << ans;
}
