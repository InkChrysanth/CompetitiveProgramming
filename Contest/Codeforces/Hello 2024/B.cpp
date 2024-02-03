// Problem: B. Plus-Minus Split
// Contest: Codeforces - Hello 2024
// URL: https://codeforces.com/contest/1919/problem/B
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

void mian()
{
	int n=int_rd;
	string s; cin>>s;
	int ans=0;
	for(int i=0; i<n; i++)
		ans+=s[i]=='+'?1:-1;
	cout<<abs(ans)<<endl;
}

signed main()
{
	cin.tie(0); cout.tie(0);
	int T=int_rd;
	while(T--) mian();
	return 0;
}