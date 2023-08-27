// Problem: 递归实现组合型枚举
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/95/
// Memory Limit: 256 MB
// Time Limit: 5000 ms

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N=30;
int n, m;
int a[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1; i<=m; i++)
		a[i]=1;
	do
	{
		for(int i=1; i<=n; i++)
			if(a[i])
				cout<<i<<' ';
		cout<<endl;
	}while(prev_permutation(a+1, a+1+n));
	return 0;
}