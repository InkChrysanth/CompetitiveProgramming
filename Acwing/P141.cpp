// Problem: 周期
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/description/143/
// Memory Limit: 64 MB
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
	int n, tc=0;
	while(cin>>n, n)
	{
		cout<<"Test case #"<<++tc<<endl;
		string s;
		cin>>s;
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
		for(int i=2; i<=n; i++)
		{
			if(i%(i-ne[i])==0 && ne[i])
				cout<<i<<' '<<(i/(i-ne[i]))<<endl;
		}
		cout<<endl;
	}
	return 0;
}
