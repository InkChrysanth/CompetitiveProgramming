#include <bits/stdc++.h>
using namespace std;
const int N=510;
typedef pair<int, int> PII;
int n, m;
char g[N][N];
int dist[N][N];
int dx[]={-1, -1, 1, 1}, dy[]={-1, 1, 1, -1};
int ix[]={-1, -1, 0, 0}, iy[]={-1, 0, 0, -1};
char cs[]="\\/\\/";
int bfs()
{
    deque<PII> dq;
    dq.push_back({0, 0});
    memset(dist, 0x3f, sizeof dist);
    dist[0][0]=0;
    while(dq.size())
    {
        auto t=dq.front(); dq.pop_front();
        int x=t.first, y=t.second;
        for(int i=0; i<4; i++)
        {
            int a=x+dx[i], b=y+dy[i];
            if(a<0 || a>n || b<0 || b>m) continue;
            int j=x+ix[i], k=y+iy[i];
            int w=0;
            if(g[j][k]!=cs[i]) w=1;
            if(dist[a][b]>dist[x][y]+w)
            {
                dist[a][b]=dist[x][y]+w;
                if(w) dq.push_back({a, b});
                else dq.push_front({a, b});
            }
        }
    }
    if(dist[n][m]==0x3f3f3f3f) return -1;
    return dist[n][m];
}
int main()
{
    int T; cin>>T;
    while(T--)
    {
        cin>>n>>m;
        for(int i=0; i<n; i++)
            cin>>g[i];
        int res=bfs();
        if(res!=-1) cout<<res<<endl;
        else puts("NO SOLUTION");
    }
    return 0;
}