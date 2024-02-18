// Problem: P7205 [COCI2019-2020#3] Drvca
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P7205
// Memory Limit: 500 MB
// Time Limit: 1000 ms

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
int n, cnt;
int a[N];
int ans1[N], ans2[N];

void dfs(int u, int len1, int len2)
{
	if(++cnt>3e5)
	{
		cout<<"-1"<<endl;
		exit(0);
	}
	if(u==n+1)
	{
		if(len1+len2==n && len1>0 && len2>0)
		{
			cout<<len1<<endl; for(int i=1; i<=len1; i++) cout<<ans1[i]<<' '; cout<<endl;
			cout<<len2<<endl; for(int i=1; i<=len2; i++) cout<<ans2[i]<<' '; cout<<endl;
			exit(0);
		}
		return;
	}
	if(len1<2 || (len1>=2 && a[u]-ans1[len1]==ans1[2]-ans1[1]))
	{
		ans1[len1+1]=a[u];
		dfs(u+1, len1+1, len2);
	}
	if(len2<2 || (len2>=2 && a[u]-ans2[len2]==ans2[2]-ans2[1]))
	{
		ans2[len2+1]=a[u];
		dfs(u+1, len1, len2+1);
	}
}
signed main()
{
	cin.tie(0); cout.tie(0);
	n=int_rd;
	for(int i=1; i<=n; i++) a[i]=int_rd;
	sort(a+1, a+n+1);
	dfs(1, 0, 0);
	cout<<"-1"<<endl;
	return 0;
}