// Problem: A. 2023
// Contest: Codeforces - Good Bye 2023
// URL: https://codeforces.com/contest/1916/problem/A
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

int tmp[]={2023, 289, 119, 17, 7, 1};
vector<int> ans;

void kumiko()
{
	ans.clear();
	int n=int_rd, k=int_rd;
	int sum=1, st=0;
	for(int i=1; i<=n; i++)
	{
		int x=int_rd; sum*=x;
		if(sum>2023) st=1;
	}
	if(st) cout<<"NO"<<endl;
	else
	{
		int tt=sum;
		for(int i=1; i<=k; i++)
			for(auto x: tmp)
				if(tt*x<=2023){tt*=x, ans.emplace_back(x); break;}
		int chk=sum;
		for(auto x: ans) chk*=x; 
		if(chk==2023)
		{
			cout<<"YES"<<endl;
			for(auto x: ans) cout<<x<<' ';
			cout<<endl;
		}
		else cout<<"NO"<<endl;
	}
}

signed main()
{
	cin.tie(0); cout.tie(0);
	int t=int_rd;
	while(t--) kumiko();
	return 0;
}