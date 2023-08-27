// Problem: 起床困难综合症
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1000/
// Memory Limit: 64 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N=100010;
int ans;
int t[N], op[N];
int n, m;
bool calc(bool state, int x)
{
	for(int i=0; i<n; i++)
		if(op[i]==1) state|=t[i]>>x&1;
		else if(op[i]==2) state^=t[i]>>x&1;
		else state&=t[i]>>x&1;
	return state;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=0; i<n; i++)
	{
		string s;
		cin>>s>>t[i];
		if(s=="OR") op[i]=1;
		else if(s=="XOR") op[i]=2;
		else if(s=="AND") op[i]=3;
	}
	for(int i=29; i>=0; i--)
	{
		if(1<<i<=m)
		{
			bool x=calc(0, i), y=calc(1, i);
			if(x>=y) ans|=x<<i;
			else ans|=y<<i, m-=1<<i;
		}
		ans|=calc(0, i)<<i;
	}
	cout<<ans<<endl;
	return 0;
}