#include <bits/stdc++.h>
#define int_rd (int)read()
#define ll_rd read()
#define endl '\n'
#define mp make_pair
#define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

inline ll read()
{
	ll a=0; int f=0; char p=getchar();
	while(!isdigit(p)){f|=p=='-'; p=getchar();}
	while(isdigit(p)){a=(a<<3)+(a<<1)+(p^48); p=getchar();}
	return f?-a:a;
}

const int N=1000010;
int n, k, ans;

struct Node
{
	int a[10], sum;
	bool operator<(const Node &T)const
	{
		return sum>T.sum;
	}
}pts[N];

int calc(int x, int y)
{
	int res=0;
	for(int i=1; i<=k; i++)
		res+=abs(pts[x].a[i]-pts[y].a[i]);
	return res;
}

signed main()
{
	freopen("data3.in", "r", stdin);
	freopen("T3.out", "w", stdout);
	srand(time(NULL));
	cin.tie(0); cout.tie(0);
	n=int_rd, k=int_rd;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=k; j++)
			cin>>pts[i].a[j], pts[i].sum+=abs(pts[i].a[j])+rand();
	sort(pts+1, pts+n+1);
	for(int i=1; i<=n; i++)
	{
		if((double)clock()/CLOCKS_PER_SEC>11.8) break;
		for(int j=i+1; j<=n; j++)
			ans=max({ans, calc(i, j), calc(i, n-j+1)});
	}
	cout<<ans<<endl;
	return 0;
}