// Problem: 火车进栈
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/131/
// Memory Limit: 64 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n, step=0;
basic_string<int> a;
stack<int> stk;
void dfs(int u)
{
	if(a.size()==n)
	{
		if(++step>20) return;
		for(auto x: a) cout<<x;
		cout<<endl;
		return;
	}
	if(stk.size())
	{
		a.push_back(stk.top()); stk.pop();
		dfs(u);
		stk.push(a.back()); a.pop_back();
	}
	if(u<=n)
	{
		stk.push(u);
		dfs(u+1);
		stk.pop();
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	dfs(1);
	return 0;
}