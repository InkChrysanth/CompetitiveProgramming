#include <bits/stdc++.h>
using namespace std;
const int N=2010;
typedef pair<int, int> PII;
int n, m;
int dx[]={1, 0, -1, 0}, dy[]={0, -1, 0, 1};
char g[N][N];
bool f[N][N];
int dist[N][N];
int bfs(PII start, PII end)
{
	memset(dist, -1, sizeof dist);
	dist[start.first][start.second]=0;
	queue<PII> q;
	q.push(start);
	while(q.size())
	{
		auto t=q.front(); q.pop();
		if(t.first==end.first && t.second==end.second) return dist[end.first][end.second];
		for(int i=0; i<4; i++)
		{
			int x=t.first+dx[i], y=t.second+dy[i];
			if(x<1 || x>n || y<1 || y>m || f[x][y] || dist[x][y]!=-1) continue;
			dist[x][y]=dist[t.first][t.second]+1;
			q.push({x, y});
		}
	}
	return -1;
}
int main()
{
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			cin>>g[i][j];
	PII start, end;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
		{
			if(g[i][j]=='S') start={i, j};
			if(g[i][j]=='G') end={i, j};
			if(g[i][j]=='v')
			{
				f[i][j]=true;
				int k=i;
				while(k++<=n && g[k][j]=='.')
					f[k][j]=true;
			}
			if(g[i][j]=='>')
			{
				f[i][j]=true;
				int k=j;
				while(k++<=m && g[i][k]=='.')
					f[i][k]=true;
			}
			if(g[i][j]=='<')
			{
				f[i][j]=true;
				int k=j;
				while(k-->0 && g[i][k]=='.')
					f[i][k]=true;
			}
			if(g[i][j]=='^')
			{
				f[i][j]=true;
				int k=i;
				while(k-->0 && g[k][j]=='.')
					f[k][j]=true;
			}
			if(g[i][j]=='#') f[i][j]=true;
		}
	cout<<bfs(start, end)<<endl;
	return 0;
}