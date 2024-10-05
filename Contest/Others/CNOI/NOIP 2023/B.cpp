#include <bits/stdc++.h>
#define mp make_pair
#define endl '\n'
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N=100010;
const int T=114514, F=-114514, U=0;

int tid, t;
int n, m, ans;
int p[N];
bool st[N*2];

int find(int x)
{
	int res;
	if(x==T || x==F) res=x;
	else if(x==U || st[-x+N]) res=U;
	else if(st[x+N]) res=T;
	else if(x<0)
	{
		if(x==-p[-x]) res=x;
		else
		{
			st[x+N]=1;
			res=find(-p[-x]);
			st[x+N]=0;
		}
	}
	else
	{
		if(x==p[x]) res=x;
		else
		{
			st[x+N]=1;
			res=p[x]=find(p[x]);
			st[x+N]=0;
		}
	}
	return res;
}

void get(char op, int x, int y)
{
    if(op=='T') p[x]=T;
    if(op=='F') p[x]=F;
    if(op=='U') p[x]=U;
    if(op=='+') p[x]=p[y];
    if(op=='-') p[x]=-p[y];
}

void solve()
{
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		p[i]=i;
	int x, y; char op[3];
	for(int i=1; i<=m; i++)
	{
		cin>>op>>x;
		if(op[0]=='+' || op[0]=='-') cin>>y;
		get(op[0], x, y);
	}
	ans=0;
	for(int i=1; i<=n; i++)
		if(find(i)==U)
			ans++;
	cout<<ans<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>tid>>t;
    while(t--) solve();
    return 0;
}