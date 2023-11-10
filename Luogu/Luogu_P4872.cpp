// Problem: P4872 OIer们的东方梦
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4872
// Memory Limit: 128 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
const int N=1010, INF=0x3f3f3f3f;
int n, m;
char g[N][N];
int dist[N][N][4];
bool used[4];
PII st, ed;
struct Node
{
    int d; PII p;
    bool sw, fl;
    bool operator <(const Node &T)const
    {
        return d>T.d;
    }
};
priority_queue<Node> q;
int getState(Node v)
{
    if(v.sw) return 2;
    if(v.fl) return 1;
    return 0;
}

void check(Node v)
{
    int state=getState(v);
    if(dist[v.p.first][v.p.second][state]>v.d)
    {
        dist[v.p.first][v.p.second][state]=v.d;
        q.push(v);
    }
}

void tp(Node v)
{
    int state=getState(v);
    if(used[state]) return;
    used[state]=1;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            if(g[i][j]!='X') continue;
            Node vv={v.d+1, {i, j}, v.sw, v.fl};
            check(vv);
        }
}

int bfs()
{
    memset(dist, 0x3f, sizeof dist);
    q.push({0, st, 0, 0});
    while(q.size())
    {
        auto v=q.top(); q.pop();
        if(v.p.first==ed.first && v.p.second==ed.second)
            return v.d;
        for(int i=0; i<4; i++)
        {
            Node vv;
            vv.sw=v.sw, vv.fl=v.fl, vv.p.first=v.p.first+dx[i], vv.p.second=v.p.second+dy[i];
            int state=getState(vv);
            /**/if(vv.p.first<0 || vv.p.first>n || vv.p.second<0 || vv.p.second>m) continue;
            char t=g[vv.p.first][vv.p.second];
            if(t=='1')
            {
                vv.d=v.d+1;
                if(state==2) check(vv);
            }
            if(t=='0' || t=='X')
            {
                vv.d=v.d+1;
                check(vv);
            }
            if(t=='2')
            {
                if(state!=0) vv.d=v.d+1;
                else vv.d=v.d+4;
                check(vv);
            }
            if(t=='3')
            {
                if(state!=0) vv.d=v.d+1;
                else vv.d=v.d+9;
                check(vv);
            }
            if(t=='4')
            {
                vv.d=v.d+1; vv.fl=1;
                check(vv);
            }
            if(t=='5')
            {
                vv.d=v.d+1;
                check(vv);
                if(!vv.sw) vv.sw=1, vv.d+=5;
                check(vv);
            }
        }
        if(g[v.p.first][v.p.second]=='X') tp(v);
    }
    return -1;
}

int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin>>g[i][j];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            if(g[i][j]=='M') g[i][j]='0';
            if(g[i][j]=='S') st={i, j}, g[i][j]='0';
            if(g[i][j]=='E') ed={i, j}, g[i][j]='0';
        }
    int res=bfs();
    if(res==-1) puts("We want to live in the TouHou World forever");
    else cout<<res<<endl;
    return 0;
}