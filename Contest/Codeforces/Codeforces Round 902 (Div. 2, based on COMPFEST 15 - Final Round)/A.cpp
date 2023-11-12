// Problem: A. Goals of Victory
// Contest: Codeforces - Codeforces Round 902 (Div. 2, based on COMPFEST 15 - Final Round)
// URL: https://codeforces.com/contest/1877/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
void kumiko()
{
	int n; cin>>n;
	int sum=0;
	for(int i=1; i<n; i++)
	{
		int x; cin>>x;
		sum+=x;
	}
	cout<<-sum<<endl;
}
signed main()
{
	int t; cin>>t;
	while(t--) kumiko();
	return 0;
}