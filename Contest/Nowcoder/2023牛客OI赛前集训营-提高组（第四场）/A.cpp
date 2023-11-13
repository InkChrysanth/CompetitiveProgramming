// Problem: 同色三角形
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/65195/A
// Memory Limit: 524288 KB
// Time Limit: 2000 ms

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

const int N=300010;

int n, sum=0;

signed main()
{
	ios::sync_with_stdio(false); cout.tie(0);
	n=int_rd;
	for(int i=1; i<=n; i++)
		sum+=(int_rd*int_rd);
	int ans=((n*(n-1)*(n-2))/6)-(sum/2);
	cout<<ans<<endl;
	return 0;
}