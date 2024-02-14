// #pragma GCC optimize(2)
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

const int N=71;
vector<int> a[N];

int solve(vector<int> a)
{
	int cur=a[0], ans=a[0];
	for(int i=1; i<a.size(); i++)
	{
		cur=floor(cur/2.0);
		if(cur>=a[i]) ;
		else ans+=(a[i]-cur), cur=a[i];
	}
	return ans;
}

signed main()
{
	freopen("magic.in", "r", stdin);
	freopen("magic.out", "w", stdout);
	cin.tie(0); cout.tie(0);
	int n=int_rd;
	for(int i=1; i<=n; i++)
	{
		int x=int_rd;
		for(int j=1; j<=n-i+1; j++)
			a[j].emplace_back(x);
	}
	for(int i=n; i>=1; i--)
		cout<<solve(a[i])<<' ';
	return 0;
}