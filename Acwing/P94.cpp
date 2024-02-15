// Problem: 递归实现排列型枚举
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/96/
// Memory Limit: 256 MB
// Time Limit: 5000 ms

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N=10;
int n;
int a[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1; i<=n; i++)
		a[i]=i;
	do
	{
		for(int i=1; i<=n; i++)
			cout<<a[i]<<' ';
		cout<<endl;
	}while(next_permutation(a+1, a+1+n));
	return 0;
}