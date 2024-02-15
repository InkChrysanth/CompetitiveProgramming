// Problem: P5749 [IOI2019] 排列鞋子
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P5749
// Memory Limit: 125 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
#define int_rd (int)read()
#define ll_rd read()
#define endl '\n'
#define mp make_pair

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
const int N=400010;

int n; ll ans=0;
int a[N], tr[N];
bool vis[N];
vector<int> pos[N];

int lowbit(int x)
{
	return x&-x;
}

void add(int x, int c)
{
	for(int i=x; i<=n; i+=lowbit(i))
		tr[i]+=c;
}

ll query(int x)
{
	ll res=0;
	for(int i=x; i; i-=lowbit(i))
		res+=tr[i];
	return res;
}

signed main()
{
	cin.tie(0); cout.tie(0);
	n=int_rd; n<<=1;
	for(int i=1; i<=n; i++)
	{
		a[i]=int_rd;
		pos[a[i]+n].emplace_back(i);
		add(i, 1);
	}
	for(int i=n; i>=1; i--)
	{
		if(vis[i]) continue;
		vis[i]=true;
		pos[a[i]+n].pop_back();
		int res=pos[n-a[i]].back();
		pos[n-a[i]].pop_back();
		vis[res]=true;
		ans+=(query(i-1)-query(res))+((a[i]<0)?1:0);
		add(res, -1);
	}
	cout<<ans<<endl;
	return 0;
}