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

int n, m;

void sbmH()
{
	n=int_rd, m=int_rd;
	int res=(n*m*2)/__gcd(n, m);
	cout<<res<<endl;
}

signed main()
{
	freopen("T1.in", "r", stdin);
	freopen("T1.out", "w", stdout);
	cin.tie(0); cout.tie(0);
	int T=int_rd;
	while(T--) sbmH();
	return 0;
}