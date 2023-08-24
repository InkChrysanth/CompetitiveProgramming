#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef pair<int, int> PII;
const int N=1010;
int n, m;
int dx[]={0, 1, 0, -1}, dy[]={1, 0, -1, 0};
int g[N][N], dist[N][N];
void bfs()
{
    queue<PII> q;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(g[i][j]) q.push({i, j});
    while(q.size())
    {
        auto t=q.front(); q.pop();
        for(int i=0; i<4; i++)
        {
            int x=t.x+dx[i], y=t.y+dy[i];
            if(x<1 || x>n || y<1 || y>m || dist[x][y] || g[x][y]) continue;
            dist[x][y]=dist[t.x][t.y]+1;
            q.push({x, y});
        }
    }
}
int main()
{
    cin.tie(0); cin>>n>>m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            char c; cin>>c;
            g[i][j]=c-'0';
        }
    bfs();
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
            cout<<dist[i][j]<<' ';
        cout<<endl;
    }
}