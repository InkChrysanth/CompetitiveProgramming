// Problem: KMP字符串
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/description/833/
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

#define cmin(i,j) (i)=min((i),(j))
#define cmax(i,j) (i)=max((i),(j))
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define Fi(s) freopen(s,"r",stdin)
#define Fo(s) freopen(s,"w",stdout)
#define Fre(s) Fi(s".in"),Fo(s".out")
#define all(x) x.begin(), x.end()
#define each(i,x) for(auto &i:(x))
#define fi first
#define se second
#define endl '\n'
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define eb emplace_back

using ll=long long;
using ld=long double;
using pii=pair<int, int>;
using pli=pair<ll, int>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;
constexpr int N=100010;

int t_len, p_len;
string target, pattern;
int ne[N];

void init()
{
	ne[0]=-1;
	int j=0, k=-1;
	while(j<p_len)
	{
		if(k==-1 || pattern[j]==pattern[k])
		{
			ne[++j]=++k;
			if(pattern[j]==pattern[k]) ne[j]=ne[k];
		}
		else k=ne[k];
	}
}

void kmp()
{
	int i=0, j=0;
	while(i<t_len)
	{
		if(j==-1 || target[i]==pattern[j])
			i++, j++;
		else j=ne[j];
		if(j==p_len)
		{
			cout<<i-j<<' ';
			j=ne[p_len];
		}
	}
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin>>p_len>>pattern>>t_len>>target;
	init();
	kmp();
	return 0;
}
