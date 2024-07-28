// Problem: B. Helmets in Night Light
// Contest: Codeforces - Codeforces Round 902 (Div. 2, based on COMPFEST 15 - Final Round)
// URL: https://codeforces.com/contest/1877/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N=100010;
int n, cost;
struct Node
{
	int w, cnt;
	bool operator<(const Node &T)
	{
		return w<T.w;
	}
}a[N];
void kumiko()
{
	cin>>n>>cost;
	for(int i=0; i<n; i++) cin>>a[i].cnt;
	for(int i=0; i<n; i++) cin>>a[i].w;
	sort(a, a+n);
	int ans=cost, cnt=1;
	for(int i=0; i<n; i++)
	{
		if(cnt+a[i].cnt<=n) ans+=min(cost, a[i].w)*a[i].cnt, cnt+=a[i].cnt;
		else
		{
			ans+=min(cost, a[i].w)*(n-cnt);
			break;
		}
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin>>t;
	while(t--) kumiko();
	return 0;
}