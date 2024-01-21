// Problem: B. Two Divisors
// Contest: Codeforces - Good Bye 2023
// URL: https://codeforces.com/contest/1916/problem/B
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
	ll a=ll_rd, b=ll_rd;
	ll ans=(a*b)/__gcd(a, b);
	if(b%a==0) ans=ans*(b/a);
	cout<<ans<<endl; 
}

signed main()
{
	cin.tie(0); cout.tie(0);
	int t=int_rd;
	while(t--) kumiko();
	return 0;
}