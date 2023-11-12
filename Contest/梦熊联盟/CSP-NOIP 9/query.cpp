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
int n, k;
int a[N], b[N], c[N];

int get(int mid)
{
	int cnt=0;
	for(int i=1; i<=n; i++)
		cnt+=upper_bound(c+1, c+n+1, (mid-a[i])/b[i])-c-1;
	return cnt;
}

signed main()
{
	freopen("query.in", "r", stdin);
    freopen("query.out", "w", stdout);
	n=ll_rd;
	for(int i=1; i<=n; i++) a[i]=ll_rd;
	for(int i=1; i<=n; i++) b[i]=ll_rd;
	for(int i=1; i<=n; i++) c[i]=ll_rd;
	k=ll_rd;
	sort(c+1, c+n+1);
	int l=2, r=1000000001000000000, res;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(get(mid)>=k)
		{
			res=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	cout<<res<<endl;
	return 0;
}