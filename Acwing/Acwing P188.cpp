#include <bits/stdc++.h>
using namespace std;
const int N=160;
typedef pair<int, int> PII;
int n, m;
char g[N][N];
int dist[N][N];
int dx[]={-2, -1, 1, 2, 2, 1, -1, -2}, dy[]={1, 2, 2, 1, -1, -2, -2, -1};

int bfs(PII start, PII end)
{
    memset(dist, -1, sizeof dist);
    queue<PII> q;
    q.push({start.first, start.second});
    dist[start.first][start.second]=0;
    while(q.size())
    {
        auto t=q.front(); q.pop();
        if(t.first==end.first && t.second==end.second) return dist[end.first][end.second];
        for(int i=0; i<8; i++)
        {
            int x=t.first+dx[i], y=t.second+dy[i];
            if(x<1 || x>n || y<1 || y>m || dist[x][y]!=-1 || g[x][y]=='*') continue;
            dist[x][y]=dist[t.first][t.second]+1;
            q.push({x, y});
        }
    }
}
int main()
{
    cin>>m>>n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin>>g[i][j];
    PII start, end;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(g[i][j]=='K') start={i, j};
            else if(g[i][j]=='H') end={i, j};
    cout<<bfs(start, end)<<endl;
    return 0;
}