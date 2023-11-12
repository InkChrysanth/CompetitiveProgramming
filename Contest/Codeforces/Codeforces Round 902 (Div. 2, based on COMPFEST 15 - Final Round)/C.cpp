// Problem: C. Joyboard
// Contest: Codeforces - Codeforces Round 902 (Div. 2, based on COMPFEST 15 - Final Round)
// URL: https://codeforces.com/contest/1877/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
void kumiko()
{
	int n, m, k; cin>>n>>m>>k;
	int ans;
	if(k>3) ans=0;
	else if(k==3) ans=max(m-n-(m-n)/n, 0);
	else if(k==2)
	{
		if(m<=n) ans=m;
		else ans=n+(m-n)/n;
	}
	else ans=1;
	cout<<ans<<endl;
}
signed main()
{
	int t; cin>>t;
	while(t--) kumiko();
	return 0;
}