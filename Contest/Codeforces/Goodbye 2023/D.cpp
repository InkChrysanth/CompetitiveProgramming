// Problem: D. Mathematical Problem
// Contest: Codeforces - Good Bye 2023
// URL: https://codeforces.com/contest/1916/problem/D
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
	int x=int_rd;
	if(x==1) cout<<1<<endl;
	else
	{
		for(int i=0; i<x/2; i++)
		{
			cout<<1;
			for(int j=0; j<i; j++)
				cout<<0;
			cout<<6;
			for(int j=0; j<i; j++)
				cout<<0;
			cout<<9;
			for(int j=0; j<x-i*2-3; j++)
				cout<<0;
			cout<<endl;
		}
		cout<<196; for(int i=0; i<x-3; i++) cout<<0;
		cout<<endl;
		for(int i=0; i<x/2; i++)
		{
			cout<<9;
			for(int j=0; j<i; j++)
				cout<<0;
			cout<<6;
			for(int j=0; j<i; j++)
				cout<<0;
			cout<<1;
			for(int j=0; j<x-i*2-3; j++)
				cout<<0;
			cout<<endl;
		}
	}
}

signed main()
{
	cin.tie(0); cout.tie(0);
	int t=int_rd;
	while(t--) kumiko();
	return 0;
}