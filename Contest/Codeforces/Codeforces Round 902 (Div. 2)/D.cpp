// Problem: D. Effects of Anti Pimples
// Contest: Codeforces - Codeforces Round 902 (Div. 2, based on COMPFEST 15 - Final Round)
// URL: https://codeforces.com/contest/1877/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N=100010, MOD=998244353;
int a[N], b[N];
void kumiko()
{
	int n; cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=1; i<=n; i++)
		for(int j=i; j<=n; j+=i)
			a[i]=max(a[i], a[j]);
	sort(a+1, a+n+1);
	b[0]=1;
	for(int i=1; i<N; i++)
		b[i]=(b[i-1]*2)%MOD;
	int ans=0;
	for(int i=1; i<=n; i++)
		ans=(ans+a[i]*b[i-1])%MOD;
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	kumiko();
	return 0;
}