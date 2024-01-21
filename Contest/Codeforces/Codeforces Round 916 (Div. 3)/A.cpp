// Problem: A. Problemsolving Log
// Contest: Codeforces - Codeforces Round 916 (Div. 3)
// URL: https://codeforces.com/contest/1914/problem/0
// Memory Limit: 256 MB
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

void kumiko()
{
	int a[30]={0};
	int n=int_rd;
	string s; cin>>s;
	for(int i=0; i<n; i++)
		a[s[i]-'A'+1]++;
	int ans=0;
	for(int i=1; i<=26; i++)
		if(a[i]>=i)
			ans++;
	cout<<ans<<endl;
}

signed main()
{
	cin.tie(0); cout.tie(0);
	int T=int_rd;
	while(T--) kumiko();	
	return 0;
}