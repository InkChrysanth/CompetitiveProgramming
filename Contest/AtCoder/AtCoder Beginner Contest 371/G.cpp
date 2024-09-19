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
#define endl "\n"
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define em emplace

using ll=long long;
using ull=unsigned long long;
using ld=long double;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n; cin>>n;
	vector<int> a(n+1), p(n+1), req(n+1, -1), ans(n+1);
	for(int i=1; i<=n; i++) cin>>p[i];
	for(int i=1; i<=n; i++) cin>>a[i];
	vector<vector<int>> nums(n+1);
	for(int i=1; i<=n; i++)
		for(int j=i; j<=n; j+=i)
			nums[j].eb(i);
	vector<bool> vis(n+1, false);
	for(int i=1; i<=n; i++) if(!vis[i])
	{
		vector<int> cyc;
		int pos=i;
		while(!vis[pos])
		{
			vis[pos]=true;
			cyc.eb(pos);
			pos=p[pos];
		}
		int len=cyc.size(), steps=-1;
		for(int j=0; j<len; j++)
		{
			bool flag=true;
			each(x, nums[len])
			{
				if(req[x]!=-1 && j%x!=req[x])
				{
					flag=false;
					break;
				}
			}
			if(flag && (steps==-1 || a[cyc[steps]]>a[cyc[j]]))
				steps=j;
		}
		for(int i=0; i<len; i++) ans[cyc[i]]=a[cyc[(steps+i)%len]];
		each(x, nums[len]) req[x]=steps%x;
	}
	for(int i=1; i<=n; i++)
		cout<<ans[i]<<" ";
	return 0;
}
