// Problem: B - Langton's Takahashi
// Contest: AtCoder - Japan Registry Services (JPRS) Programming Contest 2024 (AtCoder Beginner Contest 339)
// URL: https://atcoder.jp/contests/abc339/tasks/abc339_b
// Memory Limit: 1024 MB
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

int st[1010][1010]={0};
int dx[]={-1, 0, 1, 0}, dy[]={0, 1, 0, -1};

signed main()
{
	cin.tie(0); cout.tie(0);
	int n=int_rd, m=int_rd, t=int_rd;
	int x=0, y=0, ptr=0;
	while(t--)
	{
		
		if(!st[x][y]) st[x][y]=1, ptr++;
		else st[x][y]=0, ptr--;
		ptr=(ptr+4)%4;
		x+=dx[ptr], y+=dy[ptr];
		x=(x+n)%n, y=(y+m)%m;
	}
	for(int i=0; i<n; i++, cout<<endl)
		for(int j=0; j<m; j++)
			cout<<(st[i][j]==1?"#":".");
	return 0;
}