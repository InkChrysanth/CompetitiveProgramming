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
	int h, w, q;
	cin>>h>>w>>q;
	vector<set<int>> row(h+1), col(w+1);
	for(int i=1; i<=h; i++)
		for(int j=1; j<=w; j++)
			row[i].em(j), col[j].em(i);
	int ans=h*w;
	for(int r, c; q--;)
	{
		cin>>r>>c;
		if(row[r].count(c)) ans--, row[r].erase(c), col[c].erase(r);
		else
		{
			auto it=row[r].upper_bound(c);
			if(it!=row[r].begin())
			{
				ans--;
				int p=*prev(it);
				row[r].erase(p);
				col[p].erase(r);
			}
			if(it!=row[r].end())
			{
				ans--;
				int p=*it;
				row[r].erase(p);
				col[p].erase(r);
			}	
			it=col[c].upper_bound(r);
			if(it!=col[c].begin())
			{
				ans--;
				int p=*prev(it);
				row[p].erase(c);
				col[c].erase(p);
			}
			if(it!=col[c].end())
			{
				ans--;
				int p=*it;
				row[p].erase(c);
				col[c].erase(p);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

