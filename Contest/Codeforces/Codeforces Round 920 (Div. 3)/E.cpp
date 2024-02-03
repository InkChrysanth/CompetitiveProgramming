// Problem: E. Eat the Chip
// Contest: Codeforces - Codeforces Round 920 (Div. 3)
// URL: https://codeforces.com/contest/1921/problem/E
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

signed main()
{
	cin.tie(0); cout.tie(0);
	int T=int_rd;
	while(T--)
	{
		int h=int_rd, w=int_rd, ya=int_rd, xa=int_rd, yb=int_rd, xb=int_rd;
		if(yb<=ya or h==1)
		{
			cout<<"draw"<<endl;
			continue;
		}
		int sa=(yb-ya+1)/2, sb=(yb-ya)/2;
		if((yb-ya)&1)
		{
			int mv=xa<xb ? min(w-xb, sb) : min(xb-1, sb);
			cout<<(sa-mv>=abs(xb-xa) ? "alice" : "draw")<<endl;
		}
		else
		{
			int mv=xa<xb ? min(xa-1, sa) : min(w-xa, sa);
			cout<<(sb-mv>=abs(xb-xa) ? "bob" : "draw")<<endl;
		}
	}
	return 0;
}