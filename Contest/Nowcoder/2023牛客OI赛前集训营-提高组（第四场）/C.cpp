// Problem: 加法方案
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/65195/C
// Memory Limit: 524288 KB
// Time Limit: 2000 ms

#include <bits/stdc++.h>
#define int_rd (int)read()
#define ll_rd read()
#define endl '\n'
#define mp make_pair
#define int unsigned long long

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

inline int read()
{
	int a=0; int f=0; char p=getchar();
	while(!isdigit(p)){f|=p=='-'; p=getchar();}
	while(isdigit(p)){a=(a<<3)+(a<<1)+(p^48); p=getchar();}
	return f?-a:a;
}

const int MOD=998244353;
string num;
int qmi(int a, int k)
{
	int res=1;
	while(k)
	{
		if(k&1) res=res*a%MOD;
		a=a*a%MOD;
		k>>=1;
	}
	return res;
}
signed main()
{
	
	ios::sync_with_stdio(false); cout.tie(0);
	getline(cin, num);
	int sum=0, ans=0;
	for(int i=0; i<num.size(); i++)
	{
		int x=num[i]-'0';
		sum=(sum*10+x)%MOD;
		ans=((ans*11)%MOD+(qmi(2, i)%MOD*x)%MOD)%MOD;
	}
	cout<<(ans*2-sum+MOD)%MOD<<endl;
	return 0;
}