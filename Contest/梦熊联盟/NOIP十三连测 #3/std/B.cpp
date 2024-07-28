#include<bits/stdc++.h>
const int MAXN = 4e5 + 10;
using namespace std;
inline int read() {
	char c = getchar(); int x = 0, f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}
int N;
int a[MAXN], b[MAXN], ta[MAXN], tb[MAXN], sa, sb, tot = 0, date[MAXN], fa[MAXN];
map<int, bool> ti;
int find(int x) {
	return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
}
int unionn(int x, int y) {
	fa[x] = y;
}
int main() {
	N = read();
	for(int i = 1; i <= N; i++) a[i] = read(), sa ^= a[i]; a[N + 1] = sa;
	for(int i = 1; i <= N; i++) b[i] = read(), sb ^= b[i]; b[N + 1] = sb;
	N++;
	memcpy(ta, a, sizeof(a)); memcpy(tb, b, sizeof(b));
	sort(ta + 1, ta + N + 1); sort(tb + 1, tb + N + 1);
	for(int i = 1; i <= N - 1; i++) if(ta[i] != tb[i]) return puts("-1"), 0;
 
	int ans = 0, num = 0;
	for(int i = 1; i <= N; i++) 
		if(a[i] != b[i] || (i == N)) {
			date[++num] = a[i]; date[++num] = b[i];
			if(i < N)ans++;//最后一块单独考虑
		}
	if(ans == 0) return puts("0"), 0;
 
	sort(date + 1, date + num + 1);
	num = unique(date + 1, date + num + 1) - date - 1;
	for(int i = 1; i <= num; i++) fa[i] = i;
	for(int i = 1; i <= N; i++)
		if(a[i] != b[i]) {
			a[i] = lower_bound(date + 1, date + num + 1, a[i]) - date,
			b[i] = lower_bound(date + 1, date + num + 1, b[i]) - date;
			if(!ti[a[i]]) ti[a[i]] = 1;
			if(!ti[b[i]]) ti[b[i]] = 1;
			unionn(find(a[i]), find(b[i]));
		}
		
	for(int i = 1; i <= num; i++)
		if(fa[i] == i) ans++;
	printf("%d", ans - 1);
 
	return 0;
}
