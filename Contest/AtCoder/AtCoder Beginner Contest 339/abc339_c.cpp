// Problem: C - Perfect Bus
// Contest: AtCoder - Japan Registry Services (JPRS) Programming Contest 2024 (AtCoder Beginner Contest 339)
// URL: https://atcoder.jp/contests/abc339/tasks/abc339_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms

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

signed main()
{
	cin.tie(0); cout.tie(0);
	int n=int_rd;
	ll pre=0, tmp=0;
	for(int i=0; i<n; i++)
	{
		int x=int_rd;
		tmp+=x; if(tmp<0) pre=max(pre, abs(tmp));
	}
	cout<<pre+tmp<<endl;
	return 0;
}