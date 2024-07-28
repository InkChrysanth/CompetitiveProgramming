//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
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
constexpr int N=501;

vector<int> g[N];

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--)
    {
        int n, m;
        cin>>n>>m;
        for(int i=1; i<=(n+1)*2; i++) g[i].clear();
        vector<int> low((n+1)*2), dfn((n+1)*2), color((n+1)*2);
        vector<int> stk((n+1)*2);
        int top=0, cnt=0, dn=0;
        vector<bool> ins((n+1)*2);
        function<void(int)> tarjan=[&](int u)
        {
            low[u]=dfn[u]=++dn;
            stk[++top]=u, ins[u]=1;
            each(v, g[u])
            {
                if(!dfn[v]) tarjan(v), cmin(low[u], low[v]);
                else if(ins[v]) cmin(low[u], dfn[v]);
            }
            if(dfn[u]==low[u])
            {
                cnt++;
                do
                {
                    u=stk[top--];
                    color[u]=cnt;
                    ins[u]=false;
                }while(dfn[u]!=low[u]);
            }
        };
        for(int i=1, va, vb; i<=m; i++)
        {
            string a, b;
            cin>>a>>b;
            int u=0, v=0, k;
            k=1; while(k<a.size()) u=u*10+a[k++]-'0';
            k=1; while(k<b.size()) v=v*10+b[k++]-'0';
            va=(a[0]=='h'), vb=(b[0]=='h');
            g[u+n*(va&1)].eb(v+n*(vb^1));
            g[v+n*(vb&1)].eb(u+n*(va^1));
        }
        for(int i=1; i<=2*n; i++)
            if(!dfn[i])
                tarjan(i);
        bool flag=0;
        for(int i=1; i<=n; i++)
            if(color[i]==color[i+n])
            {
                flag=1;
                break;
            }
        if(flag) cout<<"BAD"<<endl;
        else cout<<"GOOD"<<endl;
    }
	return 0;
}
