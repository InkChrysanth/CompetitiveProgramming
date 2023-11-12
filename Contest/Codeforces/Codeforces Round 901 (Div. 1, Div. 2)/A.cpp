// Problem: A. Jellyfish and Undertale
// Contest: Codeforces - Codeforces Round 901 (Div. 2)
// URL: https://codeforces.com/contest/1875/problem/0
// Memory Limit: 256 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N=110;
int a, b, n;
int t[N];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int T; cin>>T;
	while(T--)
	{
		cin>>a>>b>>n;
		for(int i=1; i<=n; i++) cin>>t[i];
		sort(t+1, t+n+1);
		int res=b-1;
		for(int i=1; i<=n; i++)
			res+=min(t[i], a-1);
		res++;
		cout<<res<<endl;
	}
	return 0;
}