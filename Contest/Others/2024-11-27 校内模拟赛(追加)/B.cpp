//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

#define cmin(i,j) (i)=min((i),(j))
#define cmax(i,j) (i)=max((i),(j))
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define all(x) x.begin(), x.end()
#define each(i,x) for(auto &i:(x))
#define fi first
#define se second
#define endl "\n"
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ins insert

using ll=long long;
using ull=unsigned long long;
using db=double;
using ld=long double;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

inline namespace FileIO{
void setIn(string s) { freopen(s.c_str(), "r", stdin); }
void setOut(string s) { freopen(s.c_str(), "w", stdout); }
void setIO(string s="")
{	
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	#ifndef LOCAL
        if(s.size()) setIn(s+".in"), setOut(s+".out");
	#else
        setIn("inkorange.in"), setOut("inkorange.out");
    #endif
}
}

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;

struct Node
{
    int cnt, num;
    vector<int> v;
    bool operator<(const Node &T)const
    { return cnt>T.cnt; }
};

signed main()
{
	setIO();
	int n, m, q; cin>>n>>m>>q;
    vector<int> a(m+1), tmp(m+1);
    for(int i=1; i<=m; i++) cin>>a[i], tmp[i]=a[i];
    sort(tmp.begin()+1, tmp.end());
    tmp.erase(unique(tmp.begin()+1, tmp.end()), tmp.end());
    unordered_map<int, int> id;
    for(int i=1; i<=m; i++)
    {
        int to=lower_bound(tmp.begin()+1, tmp.end(), a[i])-tmp.begin();
        id[to]=a[i], a[i]=to;
    }
    // for(int i=1; i<=m; i++) cerr<<a[i]<<" ";
    vector<Node> s(n+1);
    for(int i=1; i<=m; i++)
    {
        s[a[i]].v.eb(i);
        s[a[i]].cnt++;
        s[a[i]].num=a[i];
    }
    sort(s.begin()+1, s.end());
    vector<int> cnt(n+1);
    while(q--)
    {
        int l, r; cin>>l>>r;
        int len=r-l+1;
        vector<int> ans;
        if(len<=(int)sqrt(m))
        {
            for(int i=l; i<=r; i++) cnt[a[i]]++;
            for(int i=l; i<=r; i++)
            {
                if(cnt[a[i]]*3>len) ans.eb(id[a[i]]);
                cnt[a[i]]=0;
            }
            if(ans.empty()) cout<<"sbmH"<<endl;
            else{ sort(all(ans)); each(x, ans) cout<<x<<" "; cout<<endl; }
        }
        else
        {
            for(int i=1; i<=n && s[i].cnt*3>len; i++)
            {
                int up=-1, dn=-1;
                int lo=0, hi=s[i].cnt-1;
                while(lo<=hi)
                {
                    int mid=(lo+hi)>>1;
                    if(l<=s[i].v[mid]) dn=mid, hi=mid-1;
                    else lo=mid+1;
                }
                lo=0, hi=s[i].cnt-1;
                while(lo<=hi)
                {
                    int mid=(lo+hi)>>1;
                    if(r>=s[i].v[mid]) up=mid, lo=mid+1;
                    else hi=mid-1;
                }
                if(up!=-1 && dn!=-1 && (up-dn+1)*3>len)
                    ans.eb(id[s[i].num]);
            }
            if(ans.empty()) cout<<"sbmH"<<endl;
            else{ sort(all(ans)); each(x, ans) cout<<x<<" "; cout<<endl; }
        }   
    }
	return 0;
}
// divide and conquer, data structures