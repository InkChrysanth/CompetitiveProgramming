#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
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
constexpr int N=1000010, M=1010;

int cnt[N], b[M];

signed main()
{
	Fre("set");
	cin.tie(0)->sync_with_stdio(0);
	int n, q;
	cin>>n>>q;
	int m=sqrt(n);
	for(int i=1; i<=n; i++)
	{
		int x; cin>>x;
		cnt[x]++;
		b[(x-1)/m]++;
	}
	while(q--)
	{
		int x; cin>>x;
		if(x>0)
		{
			cnt[x]++;
			b[(x-1)/m]++;
		}
		else
		{
			x=-x;
			int pos=0;
			while(x>b[pos]) x-=b[pos++];
			for(int i=pos*m+1; i<=(pos+1)*m; i++)
			{
				if(x>cnt[i]) x-=cnt[i];
				else
				{
					cnt[i]--;
					b[(i-1)/m]--;
					break;
				}
			}
		}
	}
	for(int i=1; i<=n; i++)
		if(cnt[i])
			return cout<<i<<endl, 0;
	cout<<0<<endl;
	return 0;
}
// data structures