// Problem: 放弃测试
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/236/
// Memory Limit: 64 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N=1010;
int n, k;
int a[N], b[N];
double c[N];

bool check(double x)
{
	for(int i=1; i<=n; i++)
		c[i]=100.0*a[i]-x*b[i];	
	sort(c+1, c+n+1);
	double res=0;
	for(int i=k+1; i<=n; i++)
		res+=c[i];
	return res>=0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	while(cin>>n>>k, n||k)
	{
		for(int i=1; i<=n; i++) cin>>a[i];
		for(int i=1; i<=n; i++) cin>>b[i];
		double l=0, r=1e5;
		while(fabs(r-l)>1e-4)
		{
			double mid=(l+r)/2;
			if(check(mid)) l=mid;
			else r=mid;
		}
		double ans=int(l+0.5);
		cout<<ans<<endl;
	}
	return 0;
}