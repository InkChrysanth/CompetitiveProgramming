#include <bits/stdc++.h>
using namespace std;
const int N=510;
struct Node
{
    int x, y, state;
};
int n, m;
char g[N][N];
int dx[3][4] = {{-2, 0, 1, 0}, {-1, 0, 2, 0}, {-1, 0, 1, 0}};
int dy[3][4] = {{0, -2, 0, 1}, {0, -1, 0, 1}, {0, -1, 0, 2}};
int ds[3][4] = {{1, 2, 1, 2}, {0, 1, 0, 1}, {2, 0, 2, 0}};
int dist[N][N][3];
int ed_x, ed_y;
int bfs(int x, int y, int state)
{
    queue<Node> q;
    q.push({x, y, state});
    memset(dist, -1, sizeof dist);
    dist[x][y][state]=0;
    while(q.size())
    {
        auto t=q.front(); q.pop();
        x=t.x, y=t.y, state=t.state;
        if(x==ed_x && y==ed_y && state==0) return dist[x][y][state];
        for(int i=0; i<4; i++)
        {
            int cur_x=x+dx[state][i], cur_y=y+dy[state][i], cur_state=ds[state][i];
            if(cur_x<1 || cur_x>n || cur_y<1 || cur_y>m) continue;
            if(g[cur_x][cur_y]=='#' || (cur_state==0 && g[cur_x][cur_y]=='E') || (cur_state==1 && g[cur_x+1][cur_y]=='#') || (cur_state==2 && g[cur_x][cur_y+1]=='#')) continue;
            if(dist[cur_x][cur_y][cur_state]!=-1) continue;
            dist[cur_x][cur_y][cur_state]=dist[x][y][state]+1;
            q.push({cur_x, cur_y, cur_state});
        }
    }
    return -1;
}
int main()
{
    while(cin>>n>>m, n&&m)
    {
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                cin>>g[i][j];
        int x, y, state;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
            {
                if(g[i][j]=='X')
                {
                    x=i, y=j, g[i][j]='.';
                    if(g[i+1][j]=='X')
                        state=1, g[i+1][j]='.';
                    else if(g[i][j+1]=='X')
                        state=2, g[i][j+1]='.';
                    else state=0;
                }
                if(g[i][j]=='O')
                    ed_x=i, ed_y=j;
            }
        int res=bfs(x, y, state);
        if(res==-1) puts("Impossible");
        else cout<<res<<endl;
    }
    return 0;
}