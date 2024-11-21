#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int dx[] = {0,0,-1,1}, dy[] = {1,-1,0,0};
int n, m, T, f[maxn*maxn], g[maxn*maxn], h[maxn][maxn];
vector<pair<int,int>>ve[maxn*maxn];
int GF(int x) {
	return f[x] == x ? x : f[x] = GF(f[x]);
}
#define dot(x,y) (x-1)*m+y
void mrg(int x, int y) {
	f[GF(x)] = GF(y);
}
int main() {
	cin >> T;
	while(T--) {
		cin >> n >> m; 
		int ans = 0;
		for(int i = 1; i <= n * m; i++) 
			ve[i].clear(), f[i] = i, g[i] = 0;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++){
				cin >> h[i][j];
				ve[h[i][j]].push_back(make_pair(i,j));
			}
		for(int i = n * m; i; i--) {
			for(auto z : ve[i]) {
				int x = z.first, y = z.second;
				for(int j = 0; j < 4; j++) {
					int nx = x + dx[j], ny = y + dy[j];
					if(nx && ny && nx <= n && ny <= m && h[nx][ny] == h[x][y]){
						mrg(dot(nx, ny), dot(x, y)); 
					}
				}
			}
			for(auto z : ve[i]) {
				int x = z.first, y = z.second, w = GF(dot(x,y));
				for(int j = 0; j < 4; j++) {
					int nx = x + dx[j], ny = y + dy[j];
					if(nx && ny && nx <= n && ny <= m && h[nx][ny] > h[x][y]){
						g[w] = max(g[w], g[GF(dot(nx,ny))]+1);
					} 
				}
				ans = max(ans, g[w]);
			}
		}
		cout << ans << endl;
	}
}

