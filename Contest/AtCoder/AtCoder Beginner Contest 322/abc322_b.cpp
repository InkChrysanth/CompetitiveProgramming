// Problem: B - Prefix and Suffix
// Contest: AtCoder - AtCoder Beginner Contest 322
// URL: https://atcoder.jp/contests/abc322/tasks/abc322_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
string a, b;
int n, m;
bool check1()
{
	for(int i=0; i<n; i++)
		if(a[i]!=b[i])
			return false;
	return true;
}
bool check2()
{
	for(int i=n-1, j=m-1; i>=0; i--, j--)
		if(a[i]!=b[j])
			return false;
	return true;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin>>n>>m>>a>>b;
	if(check1() && check2())
	{
		cout<<0<<endl;
		return 0;
	}
	if(check1())
	{
		cout<<1<<endl;
		return 0;
	}
	if(check2())
	{
		cout<<2<<endl;
		return 0;
	}
	cout<<3<<endl;
	return 0;
}