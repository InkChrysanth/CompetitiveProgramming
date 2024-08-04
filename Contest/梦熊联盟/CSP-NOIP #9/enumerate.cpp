#include <bits/stdc++.h>
#define int_rd (int)read()
#define ll_rd read()
#define endl '\n'
#define mp make_pair
#define int long long

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

const int N=100010;

int n, n0, n1, n2, n3, p, cnt=0;

pair<int, pii> ans[N];
vector<int> num[2*N];
vector<int> pre(2*N);

signed main()
{
	freopen("enumerate.in", "r", stdin);
	freopen("enumerate.out", "w", stdout);
	n=int_rd, n3=int_rd, p=int_rd; n0=n*n+1;
	for(int c=n3+1; c<=p; c++)
		for(n2=n3; n2<=2*p-1; n2+=c)
			num[n2].emplace_back(c);
	for(int i=1; i<=2*p-1; i++)
		pre[i]=pre[i-1]+num[i].size();
	for(int a=1; a<=p; a++)
	{
		n1=n0%a;
		if(cnt<100000)
		{	
			for(int b=0; b<=p; b++)
			{
				n2=n1+b;
				if(cnt<100000)
				{
					for(auto c: num[n2])
						if(++cnt<=100000)
							ans[cnt]=mp(a, mp(b, c));
				}
				else cnt+=num[n2].size();
			}
		}
		else cnt+=(pre[n1+p]-pre[max(0ll, n1-1)]);
	}
	cout<<cnt<<endl;
	for(int i=1; i<=min(100000ll, cnt); i++)
		cout<<ans[i].first<<' '<<ans[i].second.first<<' '<<ans[i].second.second<<endl;
	return 0;
}