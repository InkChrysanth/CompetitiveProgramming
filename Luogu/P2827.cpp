// Problem: P2827 [NOIP2016 提高组] 蚯蚓
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2827
// Memory Limit: 512 MB
// Time Limit: 1000 ms

// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define int long long
#define int_rd (int)read()
#define ll_rd read()
#define endl '\n'
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

inline ll read()
{
	ll a=0; int f=0; char p=getchar();
	while(!isdigit(p)){f|=p=='-'; p=getchar();}
	while(isdigit(p)){a=(a<<3)+(a<<1)+(p^48); p=getchar();}
	return f?-a:a;
}

const int N=100010, inf=LLONG_MAX;

int n, m, p, u, v, t;
int a[N], add;
queue<int> q[4];

signed main()
{
	cin.tie(0); cout.tie(0);
	n=int_rd, m=int_rd, p=int_rd, u=int_rd, v=int_rd, t=int_rd;
	for(int i=1; i<=n; i++) a[i]=int_rd;
	sort(a+1, a+n+1, greater<int>());
	for(int i=1; i<=n; i++) q[1].push(a[i]);
	for(int i=1; i<=m; i++)
	{
		pii tmp=max({mp(q[1].size()?q[1].front():-inf, 1),
					 mp(q[2].size()?q[2].front():-inf, 2),
					 mp(q[3].size()?q[3].front():-inf, 3)});
		int len=tmp.first+add, id=tmp.second; q[id].pop();
		if(i%t==0) cout<<len<<' ';
		int x=len*u/v, y=len-x;
		q[2].push(x-p-add), q[3].push(y-p-add);
		add+=p;
	}
	cout<<endl;
	vector<int> ans;
	while(q[1].size()) ans.emplace_back(q[1].front()+add), q[1].pop();
	while(q[2].size()) ans.emplace_back(q[2].front()+add), q[2].pop(); 
	while(q[3].size()) ans.emplace_back(q[3].front()+add), q[3].pop();
	sort(ans.begin(), ans.end(), greater<int>());
	for(int i=t; i<=n+m; i+=t)
		cout<<ans[i-1]<<' ';
	cout<<endl;
	return 0;
}