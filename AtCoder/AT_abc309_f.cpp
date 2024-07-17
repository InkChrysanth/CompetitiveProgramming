#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
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
#define sz(x) int((x).size())
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
using pll=pair<ll, ll>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n;
    cin>>n;
    vector<array<int, 3>> box(n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<3; j++)
        {
            cin>>box[i][j];
        }
        sort(all(box[i]));
    }
    sort(all(box), [](array<int, 3> a, array<int, 3> b){
        return a[1]<b[1];
    });
    int tot=0;
    map<int, int> hs;
    hs[box[0][1]]=++tot;
    for(int i=1; i<n; i++)
    {
        if(box[i][1]!=box[i-1][1])
            hs[box[i][1]]=++tot;
    }
    for(int i=0; i<n; i++)
        box[i][1]=hs[box[i][1]];
    sort(all(box), [](array<int, 3> a, array<int, 3> b){
        return a[0]<b[0];
    });
    vector<int> tr(n, inf);
    auto lowbit=[&](int x) -> int{ return x&-x; };
    auto query=[&](int x) -> int
    {
        int res=tr[0];
        for(int i=x; i>0; i-=lowbit(i))
            cmin(res, tr[i]);
        return res;
    };
    auto update=[&](int x, int val) -> void
    {
        for(int i=x; i<=tot; i+=lowbit(i))
            cmin(tr[i], val);
    };
    for(int i=0; i<n; i++)
    {
        int l=i, r=i;
        while(r<n && box[l][0]==box[r][0]) r++;
        for(int j=l; j<r; j++)
		{
			if(query(box[j][1]-1)<box[j][2])
			{
				cout<<"Yes"<<endl;
				return 0;
			}
		}
		for(int j=l; j<r; j++)
		{
			update(box[j][1], box[j][2]);
		}
        i=r-1;
    }
    cout<<"No"<<endl;
	return 0;
}
