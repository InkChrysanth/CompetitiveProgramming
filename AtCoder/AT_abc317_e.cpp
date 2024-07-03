//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#include <bits/stdc++.h>
#define Fi(s) freopen(s,"r",stdin)
#define Fo(s) freopen(s,"w",stdout)
#define Fre(s) Fi(s".in"),Fo(s".out")
#define all(s) s.begin(), s.end()
#define For(i,j,k) for(int i=(j),i##_=(k);i<=i##_;i++)
#define Rep(i,j,k) for(int i=(j),i##_=(k);i>=i##_;i--)
#define fi first
#define se second
#define rd read
#define endl '\n'
#define mp make_pair
#define eb emplace_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3fll;

int dx[]={0, 0, 1, 0, -1, 1, 1, -1, -1};
int dy[]={0, 1, 0, -1, 0, 1, -1, 1, -1};

template <typename T>
void read(T &x)
{
	x=0; char g=getchar(); ll f=1;
	while(!isdigit(g))
	{
		if(g=='-') f*=-1;
		g=getchar();
	}
	while(isdigit(g))
	{
		x=x*10+(g^48);
		g=getchar();
	}
	x*=f;
}
template <typename T, typename...Args>
void read(T &first, Args &...args)
{
	read(first);
	read(args...);
}
const int N=2010;
int h, w;
pii st, ed;
char g[N][N];
int dist[N][N];

void bfs()
{
    queue<pii> q;
    q.push(st);
    while(q.size())
    {
        int x=q.front().fi, y=q.front().se;
        q.pop();
        For(i, 1, 4)
        {
            int xx=x+dx[i], yy=y+dy[i];
            if(dist[xx][yy]==0 && g[xx][yy]=='.' && xx>0 && xx<=h && yy>0 && yy<=w)
            {
                dist[xx][yy]=dist[x][y]+1;
                q.push(mp(xx, yy));
            }
        }
    }
}

signed main()
{
	cin.tie(0); cout.tie(0);
	rd(h, w);
    For(i, 1, h) For(j, 1, w)
    {
        cin>>g[i][j];
        if(g[i][j]=='S') st=mp(i, j), g[i][j]='.';
        if(g[i][j]=='G') ed=mp(i, j), g[i][j]='.';
    }
    For(i, 1, h) For(j, 1, w)
    {
        if(g[i][j]=='<')
        {
            int ii=i, jj=j-1;
            while((g[ii][jj]=='.' || g[ii][jj]=='*') && jj>0) 
                g[ii][jj--]='*';
        }
        if(g[i][j]=='>')
        {
            int ii=i, jj=j+1;
            while((g[ii][jj]=='.' || g[ii][jj]=='*') && jj<=w) 
                g[ii][jj++]='*';
        }
        if(g[i][j]=='v')
        {
            int ii=i+1,jj=j;
            while((g[ii][jj]=='.' || g[ii][jj]=='*') && ii<=h) 
                g[ii++][jj]='*';
        }
        if(g[i][j]=='^')
        {
            int ii=i-1, jj=j;
            while((g[ii][jj]=='.' || g[ii][jj]=='*') && ii>0) 
                g[ii--][jj]='*';
        }
    }
    bfs();
    cout<<((dist[ed.fi][ed.se]==0)?-1:dist[ed.fi][ed.se])<<endl;
    return 0;
}
