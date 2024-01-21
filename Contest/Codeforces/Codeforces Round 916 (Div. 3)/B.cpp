// Problem: B. Preparing for the Contest
// Contest: Codeforces - Codeforces Round 916 (Div. 3)
// URL: https://codeforces.com/contest/1914/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms

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

void kumiko()
{
	vector<int> ans;
	int n=int_rd, k=int_rd;
	for(int i=1; i<=k; i++)
		ans.push_back(i);
	for(int i=n; i>=k+1; i--)
		ans.push_back(i);
	for(auto x: ans) cout<<x<<' ';
	cout<<endl;
}

signed main()
{
	cin.tie(0); cout.tie(0);
	int T=int_rd;
	while(T--) kumiko();
	return 0;
}