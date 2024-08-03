// Problem: P4391 [BOI2009] Radio Transmission 无线传输
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4391
// Memory Limit: 125 MB
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

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n;
	string s;
	cin>>n>>s;
	vector<int> ne(n+1, 0);
	int k=-1, j=0;
	ne[0]=-1;
	while(j<n)
	{
		if(k==-1 || s[j]==s[k])
		{
			j++, k++;
			ne[j]=k;
		}
		else k=ne[k];
	}
	cout<<n-ne[n]<<endl;
	return 0;
}
