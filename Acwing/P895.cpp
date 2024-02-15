// Problem: 最长上升子序列
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/897/
// Memory Limit: 64 MB
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

const int N=1010;
int n;
int a[N], f[N];

signed main()
{
	cin.tie(0); cout.tie(0);
	n=int_rd;
	for(int i=1; i<=n; i++) a[i]=int_rd;
	for(int i=1; i<=n; i++)
	{
		f[i]=1;
		for(int j=1; j<i; j++)
			if(a[j]<a[i])
				f[i]=max(f[i], f[j]+1);
	}
	int ans=1;
	for(int i=1; i<=n; i++)
	    ans=max(ans, f[i]);
	cout<<ans<<endl;
	return 0;
}