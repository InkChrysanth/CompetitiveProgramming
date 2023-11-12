// Problem: B. Jellyfish and Game
// Contest: Codeforces - Codeforces Round 901 (Div. 2)
// URL: https://codeforces.com/contest/1875/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
vector<int> a, b;
int n, m, k;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int T; cin>>T;
	while(T--)
	{
		cin>>n>>m>>k;
		a.clear(); b.clear();
		int suma=0;
		for(int i=1; i<=n; i++) {int x; cin>>x; a.push_back(x); suma+=x;}
		for(int i=1; i<=m; i++) {int x; cin>>x; a.push_back(x); b.push_back(x);}
		sort(a.begin(), a.begin()+n); sort(b.begin(), b.end());
		if(k&1)
		{
			if(a[0]<b[m-1]) suma+=b[m-1]-a[0];
			cout<<suma<<endl;
		}
		else
		{
			if(a[0]<b[m-1]) suma+=b[m-1]-a[0];
			suma-=max({a[n-1]-a[0], a[n-1]-b[0], b[m-1]-a[0], b[m-1]-b[0]});
			cout<<suma<<endl;
		}
	}
	return 0;
}