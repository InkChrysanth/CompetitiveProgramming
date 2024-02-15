#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int N=22;
struct Node
{
    int x, y, dir;
};
int n, m;
char g[N][N];
int dx[]={1, -1, 0, 0}, dy[]={0, 0, 1, -1};
char ops[]="nswe";
PII dist[N][N][4];
vector<int> path[N][N][4];
bool p_st[N][N], b_st[N][N][4];
int p_prev[N][N];
Node b_prev[N][N][4];
bool check(int x, int y)
{
    if(x<1 || x>n || y<1 || y>m || g[x][y]=='#') return false;
    return true;
}

int p_bfs(PII st, PII ed, PII box, vector<int> &s)
{
    memset(p_st, false, sizeof p_st);
    memset(p_prev, -1, sizeof p_prev);
    p_st[st.first][st.second]=true, p_st[box.first][box.second]=true;
    queue<PII> q;
    q.push(st);
    while(q.size())
    {
        auto t=q.front(); q.pop();
        int x=t.first, y=t.second;
        if(t==ed)
        {
            s.clear();
            while(~p_prev[x][y])
            {
                int dir=p_prev[x][y];
                s.push_back(dir);
                x+=dx[dir], y+=dy[dir];
            }
            return s.size();
        }
        for(int i=0; i<4; i++)
        {
            int a=x-dx[i], b=y-dy[i];
            if(p_st[a][b] || !check(a, b)) continue;
            q.push({a, b});
            p_st[a][b]=true;
            p_prev[a][b]=i;
        }
    }
    return -1;
}

bool b_bfs(PII st, PII box, Node &ed)
{
    memset(b_st, false, sizeof b_st);
    queue<Node> q;
    for(int i=0; i<4; i++)
    {
        int a=box.first+dx[i], b=box.second+dy[i], c=box.first-dx[i], d=box.second-dy[i];
        if(!check(a, b) || !check(c, d)) continue;
        vector<int> s;
        int len=p_bfs(st, {a, b}, box, s);
        if(len==-1) continue;
        q.push({c, d, i});
        b_st[c][d][i]=true;
        path[c][d][i]=s;
        dist[c][d][i]={1, len};
        b_prev[c][d][i]={box.first, box.second, -1};
    }
    PII res={0x3f3f3f3f, 0x3f3f3f3f};
    while(q.size())
    {
        auto t=q.front(); q.pop();
        PII t_d=dist[t.x][t.y][t.dir];
        if(g[t.x][t.y]=='T' && t_d<res)
            ed=t, res=t_d;
        for(int i=0; i<4; i++)
        {
            int a=t.x+dx[i], b=t.y+dy[i], c=t.x-dx[i], d=t.y-dy[i];
            if(!check(a, b) || !check(c, d)) continue;
            vector<int> s;
            int len=p_bfs({t.x+dx[t.dir], t.y+dy[t.dir]}, {a, b}, {t.x, t.y}, s);
            if(len==-1) continue;
            PII distance={t_d.first+1, t_d.second+len};
            if(!b_st[c][d][i])
            {
                q.push({c, d, i});
                path[c][d][i]=s;
                dist[c][d][i]=distance;
                b_st[c][d][i]=true;
                b_prev[c][d][i]=t;
            }
            else if(dist[c][d][i]>distance)
            {
                dist[c][d][i]=distance;
                path[c][d][i]=s;
                b_prev[c][d][i]=t;
            }
        }
    }
    return res.first!=0x3f3f3f3f;
}


int main()
{
    int t=0;
    while(cin>>n>>m, n&&m)
    {
        printf("Maze #%d\n", ++t);
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                cin>>g[i][j];
        PII st, box;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                if(g[i][j]=='S') st={i, j};
                else if(g[i][j]=='B') box={i, j};
        Node ed; string res;
        if(!b_bfs(st, box, ed)) res="Impossible.";
        else
        {
            while(~ed.dir)
            {
                res+=ops[ed.dir]-32;
                for(int i=0; i<path[ed.x][ed.y][ed.dir].size(); i++)
                    res+=ops[path[ed.x][ed.y][ed.dir][i]];
                ed=b_prev[ed.x][ed.y][ed.dir];
            }
            reverse(res.begin(), res.end());
        }
        cout<<res<<endl<<endl;
    }
    return 0;
}