#include <bits/stdc++.h>
using namespace std;
int dx[]={0, 1, 0, -1}, dy[]={1, 0, -1, 0};
const int N=810;
struct Node
{
    int x, y, d;
};
int n, m;
bool g[N][N];
int st[N][N];
Node ghost[2];
bool check(int x, int y, int t)
{
    for(int i=0; i<2; i++)
        if(abs(ghost[i].x-x)+abs(ghost[i].y-y)<=2*t)
            return true;
    return false;
}
bool _bfs(queue<Node> &q, int t, int v)
{
    while(q.size() && q.front().d<v*t)
    {
        auto u=q.front(); q.pop();
        if(check(u.x, u.y, t)) continue;
        for(int i=0; i<4; i++)
        {
            int a=u.x+dx[i], b=u.y+dy[i];
            if(a<0 || a>=n || b<0 || b>=m || g[a][b] || check(a, b, t)) continue;
            if(!st[a][b])
            {
                st[a][b]=st[u.x][u.y];
                q.push({a, b, u.d+1});
            }
            else if(st[a][b]!=st[u.x][u.y]) return true;
        }
    }
    return false;
}

int bfs(Node boy, Node girl)
{
    memset(st, 0, sizeof st);
    queue<Node> boy_q, girl_q;
    boy_q.push(boy), girl_q.push(girl);
    st[boy.x][boy.y]=1, st[girl.x][girl.y]=2;
    for(int t=1; boy_q.size() || girl_q.size(); t++)
        if(_bfs(boy_q, t, 3) || _bfs(girl_q, t, 1))
            return t;
    return -1;
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        cin>>n>>m;
        Node boy, girl;
        int cnt=0;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                char ch; cin>>ch;
                if(ch=='M') boy={i, j, 0};
                else if(ch=='G') girl={i, j, 0};
                else if(ch=='Z') ghost[cnt++]={i, j, 0};
                g[i][j]=(ch=='X');
            }
        cout<<bfs(boy, girl)<<endl;
    }
    return 0;
}