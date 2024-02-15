// Problem: P6136 【模板】普通平衡树（数据加强版）
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P6136
// Memory Limit: 89 MB
// Time Limit: 3000 ms

#include <bits/extc++.h>
#define int long long
#define mp make_pair
using namespace std;
using namespace __gnu_pbds;
const int INF=0x3f3f3f3f;
typedef pair<int, int> PII;
int ans=0;
int n, m, op, x, last;
tree<PII, null_type, std::less<PII>, rb_tree_tag, tree_order_statistics_node_update> rbt;
signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        int a; cin>>a;
        rbt.insert(mp(a, -i));
    }
    for(int i=1; i<=m; i++)
    {
        cin>>op>>x;
        x^=last;
        if(op==1) rbt.insert(mp(x, i));
        else if(op==2) rbt.erase(rbt.lower_bound(mp(x, -INF)));
        else if(op==3) last=rbt.order_of_key(mp(x, -INF))+1;
        else if(op==4) last=(rbt.find_by_order(x-1)->first);
        else if(op==5)
        {
            auto ptr=*(--rbt.lower_bound(mp(x, -INF)));
            last=ptr.first;
        }
        else if(op==6)
        {
            auto ptr=*(rbt.upper_bound(mp(x, INF)));
            last=ptr.first;
        }
        if(op>=3) ans^=last;
    }
    cout<<ans<<endl;
    return 0;
}