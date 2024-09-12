// Problem: C. Jellyfish and Green Apple
// Contest: Codeforces - Codeforces Round 901 (Div. 2)
// URL: https://codeforces.com/contest/1875/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int T; cin>>T;
	while(T--)
	{
		int n, m; cin>>n>>m; n%=m;
		int a=n/__gcd(n, m), b=m/__gcd(n, m);
		if(__builtin_popcountll(b)>1) cout<<"-1"<<endl;
		else cout<<__builtin_popcountll(a)*m-n<<endl;
	}
	return 0;
}