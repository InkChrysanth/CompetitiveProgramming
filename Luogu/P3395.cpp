// Problem: P3395 路障
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3395
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int N=1010;
int n;
int g[N][N];
int dist[N][N];
int ba[N][N];
int dx[]={-1, 0, 1, 0}, dy[]={0, 1, 0, -1};

bool bfs()
{
    memset(dist, -1, sizeof dist);
    dist[1][1]=0;
    queue<PII> q;
    q.push({1, 1});
    while(q.size())
    {
        auto t=q.front(); q.pop();
        if(t.first==n && t.second==n) return true;
        for(int i=0; i<4; i++)
        {
            int x=t.first+dx[i], y=t.second+dy[i];
            if(x<1 || x>n || y<1 || y>n || dist[t.first][t.second]+1>ba[x][y] || dist[x][y]!=-1) continue;
            dist[x][y]=dist[t.first][t.second]+1;
            q.push({x, y});
        }
    }
    return false;
}
int main()
{
    int t; cin>>t;
    while(t--)
    {
        memset(ba, 0x3f, sizeof ba);
        cin>>n;
        for(int i=1; i<=2*n-2; i++)
        {
            int x, y; cin>>x>>y;
            ba[x][y]=i;
        }
        if(bfs()) puts("Yes");
        else puts("No");
    }
    return 0;
}