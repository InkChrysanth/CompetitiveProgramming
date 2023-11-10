// Problem: 递归实现指数型枚举
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/description/94/
// Memory Limit: 256 MB
// Time Limit: 5000 ms

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N=30;
int n;
bool st[N];
void dfs(int u)
{
	if(u>n)
	{ 
		for(int i=1; i<=n; i++)
			if(st[i])
				cout<<i<<' ';
		cout<<endl;
		return;
	}
	st[u]=true;
	dfs(u+1);
	st[u]=false;
	dfs(u+1);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	dfs(1);
	return 0;
}