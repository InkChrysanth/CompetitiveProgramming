#include <bits/stdc++.h>
#define mp make_pair
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N=3010;

int n, m;
vector<int> ans;

struct Node1
{
    string s;
    void init(){sort(s.begin(), s.end());}
}swords[N];

struct Node2
{
    string s; int id;
    void init(){sort(s.begin(), s.end(), greater<char>());}
    bool operator<(const Node2 &T)const
    {return s<T.s;}
}bwords[N];

signed main()
{
    // freopen("dict.in", "r", stdin);
    // freopen("dict.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>m;
    if(n==1)
    {
    	cout<<1<<endl;
    	return 0;
	}
    for(int i=1; i<=n; i++)
    {
        cin>>swords[i].s; 
        bwords[i].s=swords[i].s; bwords[i].id=i;
        swords[i].init();
        bwords[i].init();
    }
    sort(bwords+1, bwords+n+1);
    for(int i=1; i<=n; i++)
    {
        string tmp1=swords[i].s;
        string tmp2=(bwords[1].id==i)?bwords[2].s:bwords[1].s;
        if(tmp1<tmp2) ans.emplace_back(1);
        else ans.emplace_back(0);
    }
    for(auto x: ans) cout<<x;
    return 0;
}