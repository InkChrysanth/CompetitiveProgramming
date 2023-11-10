#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N=110;
int dx[]={-1, -1, -1, 0, 1, 1, 1, 0}, dy[]={0, -1, 1, 1, -1, 1, 0, -1};
typedef pair<int, int> PII;
int n, m, bx, by;
char g[N][N];
int dist[N][N];
int res=-0x3f3f3f3f;
int bfs()
{
    memset(dist, -1, sizeof dist);
    queue<PII> q;
    q.push({bx, by});
    dist[bx][by]=0;
    while(q.size())
    {
        auto t=q.front(); q.pop();
        for(int i=0; i<8; i++)
        {
            int x=t.x+dx[i], y=t.y+dy[i];
            if(x>0 && x<=n && y>0 && y<=m && g[x][y]!='*' && dist[x][y]==-1)
            {
                dist[x][y]=dist[t.x][t.y]+1;
                res=max(res, dist[x][y]);
                q.push({x, y});
            }
        }
    }
    return res;
}
int main()
{
    int a, b;
    cin>>m>>n>>a>>b;
    bx=n-b+1, by=a;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin>>g[i][j];
    cout<<bfs()<<endl;
    return 0;
}