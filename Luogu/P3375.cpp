// Problem: P3375 【模板】KMP
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3375
// Memory Limit: 512 MB
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
	string t, p;
	cin>>t>>p;
	vector<int> ne(p.size()+1, 0);
	function<void()> init=[&]()
	{
		int k=-1, j=0;
		ne[0]=-1;
		while(j<p.size())
		{
			if(k==-1 || p[j]==p[k])
			{
				j++, k++;
				ne[j]=k;
			}
			else k=ne[k];
		}
	};
	function<void()> kmp=[&]()
	{
		int i=0, j=0;
		while(i<t.size())
		{
			if(j==-1 || t[i]==p[j])
				i++, j++;
			else j=ne[j];
			if(j==p.size())
			{
				cout<<i-j+1<<endl;
				j=ne[j];
			}
		}
	};
	init();
	kmp();
	for(int i=1; i<=p.size(); i++)
		cout<<ne[i]<<" \n"[i==p.size()];
	return 0;
}