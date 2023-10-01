// Problem: A - First ABC 2
// Contest: AtCoder - AtCoder Beginner Contest 322
// URL: https://atcoder.jp/contests/abc322/tasks/abc322_a
// Memory Limit: 1024 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin>>n;
	string s; cin>>s;
	int res=-1;
	for(int i=0; i<=n-2; i++)
		if(s[i]=='A' && s[i+1]=='B' && s[i+2]=='C')
			{res=i+1; break;}
	cout<<res<<endl;
	return 0;
}