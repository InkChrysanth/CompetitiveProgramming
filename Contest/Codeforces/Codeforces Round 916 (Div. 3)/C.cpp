// Problem: C. Quests
// Contest: Codeforces - Codeforces Round 916 (Div. 3)
// URL: https://codeforces.com/contest/1914/problem/C
// Memory Limit: 256 MB
// Time Limit: 2500 ms

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

const int N=200010;
vector<int> a(N), b(N), pre(N), pre2(N);

void kumiko()
{
	a.clear(); b.clear(); pre.clear(); pre2.clear();
	int n=int_rd, k=int_rd;
	for(int i=1; i<=n; i++)
		a[i]=int_rd, pre[i]=pre[i-1]+a[i];
	for(int i=1; i<=n; i++)
		b[i]=int_rd, pre2[i]=max(pre2[i-1], b[i]);
	int ans=0;
	for(int i=1; i<=min(n, k); i++)
		ans=max(ans, pre[i]+(k-i)*pre2[i]);
	cout<<ans<<endl;
}

signed main()
{
	cin.tie(0); cout.tie(0);
	int T=int_rd;
	while(T--) kumiko();
	return 0;
}