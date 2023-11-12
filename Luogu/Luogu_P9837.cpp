// Problem: P9837 汪了个汪
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P9837
// Memory Limit: 512 MB
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
const int N=4010;
int n, k;

signed main()
{
	ios::sync_with_stdio(false); cout.tie(0);
	n=int_rd, k=int_rd;
	int t=n;
	for(int i=1; i<=n; i++)
	{
		int x=i%2 ? t-- : i/2;
		for(int j=1, len=1; j<=i; j++, len++)
		{
			cout<<x<<' ';
			if(j%2) x+=len;
			else x-=len;
		}
		cout<<endl;
	}
	return 0;
}