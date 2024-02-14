// #pragma GCC optimize(2)
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


const int N=100010;

int p[N], sz[N];
int n, m, k;

int find(int x)
{
	if(x==p[x]) return x;
	return p[x]=find(p[x]);
}

signed main()
{
	freopen("profit.in", "r", stdin);
	freopen("profit.out", "w", stdout);
	cin.tie(0); cout.tie(0);
	n=int_rd, m=int_rd, k=int_rd;
	for(int i=1; i<=m; i++) p[i]=i;
	while(n--)
	{
		int a=int_rd, b=int_rd;
		a=find(a), b=find(b);
		if(a!=b) sz[b]+=sz[a], p[a]=b;
		sz[b]++;
	}
	for(int i=1; i<=m; i++)
		if(i==p[i] && sz[i]&1)
			k--;
	cout<<k<<endl;
	return 0;
}