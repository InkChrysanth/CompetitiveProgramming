#include <bits/stdc++.h>
using namespace std;
const int N=400;
int n;
bool state[N][4][4], st[N][4][4][7][7][7][7];
int dx[]={-1, 0, 1, 0, 0}, dy[]={0, 1, 0, -1, 0};
struct Node
{
    int date, x, y, s0, s1, s2, s3;
};
int bfs()
{
    if(state[1][1][1] || state[1][1][2] || state[1][2][1] || state[1][2][2]) return 0;
    queue<Node> q;
    memset(st, false, sizeof st);
    q.push({1, 1, 1, 1, 1, 1, 1});
    st[1][1][1][1][1][1][1]=1;
    while(q.size())
    {
        auto t=q.front(); q.pop();
        if(t.date==n) return 1;
        for(int i=0; i<5; i++)
        {
            for(int j=1; j<=2; j++)
            {
                int x=t.x+dx[i]*j, y=t.y+dy[i]*j;
                if(x<0 || x>=3 || y<0 || y>=3) continue;
                auto &s=state[t.date+1];
                if(s[x][y] || s[x][y+1] || s[x+1][y] || s[x+1][y+1]) continue;
                int s0=t.s0, s1=t.s1, s2=t.s2, s3=t.s3;
                if(x==0 && y==0) s0=0;
                else if(++s0>=7) continue;
                if(x==0 && y==2) s1=0;
                else if(++s1>=7) continue;
                if(x==2 && y==0) s2=0;
                else if(++s2>=7) continue;
                if(x==2 && y==2) s3=0;
                else if(++s3>=7) continue;
                if(st[t.date+1][x][y][s0][s1][s2][s3]) continue;
                st[t.date+1][x][y][s0][s1][s2][s3]=true;
                q.push({t.date+1, x, y, s0, s1, s2, s3});
            }
        }
    }
    return 0;
}
int main()
{
    cin.tie(0);
    while(cin>>n, n)
    {
        for(int i=1; i<=n; i++)
            for(int x=0; x<4; x++)
                for(int y=0; y<4; y++)
                    cin>>state[i][x][y];
        cout<<bfs()<<endl;
    }
    return 0;
}