// Problem: P5884 [IOI2014] game 游戏
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P5884
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

const int N=1510;
int n, d[N]={-1};

signed main()
{
	cin.tie(0); cout.tie(0);
	n=int_rd;
	int T=(n*(n-1))/2;
	while(T--)
	{
		int u=int_rd, v=int_rd;
		if(u<v) swap(u, v);
		cout<<(++d[u]==u)<<endl;
	}
	return 0;
}