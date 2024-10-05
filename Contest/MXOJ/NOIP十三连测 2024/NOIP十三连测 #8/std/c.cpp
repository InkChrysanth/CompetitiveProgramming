#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>

using namespace std;

const int maxn = 210;
const long long INF=1ll<<60;

int n;

long long z[maxn],f[maxn][maxn];

void rerank(int p)
{
	if (!p) return;
	sort(z+1,z+p+1);
	if (!z[p]) return;
	int b=60;
	while (b>=0 && (z[p]&(1ll<<b))==0)
		b--;
	for (int a=1;a<p;a++)
		if (z[a]&(1ll<<b)) z[a]^=z[p];
	rerank(p-1);
}

long long calc(long long minv,long long nowv,int d)
{
	if (minv>=INF) return minv;
	if (minv==nowv) return nowv;
	long long l,r;
	if (minv<nowv) l=0,r=nowv;
	else l=nowv,r=INF;
	for (;d>0;d--)
	{
		long long ll=l,rr=r;
		if ((ll^z[d])>=minv) r=min(r,ll^z[d]);
		else l=max(l,ll^z[d]);
		if ((rr^z[d])>=minv) r=min(r,rr^z[d]);
		else l=max(l,rr^z[d]);
	}
	return r;
}

int solve()
{
	for (int a=0;a<=n;a++)
		for (int b=0;b<=n;b++)
			f[a][b]=INF;
	f[0][0]=-1;
	for (int a=1;a<=n;a++)
	{
		rerank(a-1);
		for (int b=0;b<=n;b++)
		{
			f[a][b]=min(f[a][b],f[a-1][b]);
			if (b) f[a][b]=min(f[a][b],calc(f[a-1][b-1]+1,z[a],a-1));
		}
	}
	for (int a=n;a>=0;a--)
		if (f[n][a]<INF) return a;

	return 0;
}

int main() {
	cin >> n;
	for (int a=1;a<=n;a++)
		cin >> z[a];
	cout << solve() << endl;

	return 0;
}

