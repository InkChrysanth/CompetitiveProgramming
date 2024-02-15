#include <bits/stdc++.h>
#define int_rd (int)read()
#define ll_rd read()
#define endl '\n'
#define mp make_pair
#define int __int128_t
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

inline int read()
{
	int a=0; int f=0; char p=getchar();
	while(!isdigit(p)){f|=p=='-'; p=getchar();}
	while(isdigit(p)){a=(a<<3)+(a<<1)+(p^48); p=getchar();}
	return f?-a:a;
}

inline void print(__int128_t x)
{
    if(x<0)
	{
        putchar('-');
        x=-x;
    }
    if(x>9) print(x/10);
    putchar(x%10+'0');
}

const int N=100010;

struct Node
{
    int m, s;
}a[N];

Node add(Node a, Node b)
{
	if(a.m==0) return b;
	Node ans;
	int gb=a.m*b.m/__gcd(a.m,b.m);
	ans.s=(b.s*(gb/b.m)+a.s*(gb/a.m)),ans.m=gb;
	int ga=__gcd(ans.s,ans.m);
	ans.s/=ga,ans.m/=ga;
	return ans;
}

int n, m;
int d[N];
vector<int> g[N];
vector<int> in;
set<int> out;
bool vis[N];


void bfs()
{
    queue<int> q;
    for(auto id: in) q.push(id), a[id].m=1, a[id].s=1, vis[id]=true;
    while(q.size())
    {
        auto u=q.front(); q.pop();
        if(out.count(u)) continue;
        for(auto v: g[u])
        {
            Node sum;
            sum.m=a[u].m*g[u].size(); sum.s=a[u].s;
            a[v]=add(a[v], sum);
            d[v]--;
            if(!d[v])
            {
				vis[v]=1;
				q.push(v);
			}
        }
    }
}
signed main()
{
	n=ll_rd, m=ll_rd;
    for(int i=1; i<=m; i++) in.push_back(i);
    for(int i=1; i<=n; i++)
    {
        int sz=ll_rd;
        if(sz==0) out.insert(i);
        for(int j=1; j<=sz; j++)
        {
            int v=ll_rd;
            g[i].emplace_back(v);
            d[v]++;
        }
    }
    bfs();
    for(auto x: out)
    {
		int t=__gcd(a[x].s, a[x].m);
		a[x].s/=t; a[x].m/=t;
		print(a[x].s);
		cout<<' ';
		print(a[x].m);
		cout<<endl;
	}
	return 0;   
}