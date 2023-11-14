// Problem: D. Two Arithmetic Progressions
// Contest: Codeforces - Educational Codeforces Round 16
// URL: https://codeforces.com/problemset/problem/710/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
#define int_rd (int)read()
#define ll_rd read()
#define endl '\n'
#define mp make_pair
#define int long long

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
const int N=1260;
int a1, b1, a2, b2, l, r;
signed main()
{
	cin.tie(0); cout.tie(0);
	a1=int_rd, b1=int_rd, a2=int_rd, b2=int_rd, l=int_rd, r=int_rd;
	l=max({l, b1, b2});
	if(a2>a1)
	{
		swap(a1, a2);
		swap(b1, b2);
	}
	int lcm=a1*a2/__gcd(a1, a2);
	if(a1<N)
	{
		int ans=0;
		for(int i=l; i<=min(r, l+lcm); i++)
		{
			if((i-b1)%a1==(i-b2)%a2 && (i-b2)%a2==0)
			{
				ans=(r-i)/lcm+1;
				break;
			}
		}
		cout<<ans<<endl;
	}
	else
	{
		int x, ans=0;
		if(b1>=l) x=b1;
		else x=b1+ceil(1.0*(l-b1)/a1)*a1;
		while(x<=r)
		{
			if((x-b2)%a2==0 && (x-b2)/a2>=0) ans++;
			x+=a1;
		}
		cout<<ans<<endl;
	}
	return 0;
}