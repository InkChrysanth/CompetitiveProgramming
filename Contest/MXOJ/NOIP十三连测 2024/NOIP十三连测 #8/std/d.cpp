#include<cstdio>
#include<cstdlib>
#include<cstring>
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

const int mn = 251;
const long long INF=0x3f3f3f3f3f3f3f3fll;

int n,w,x[3][mn],y[3][mn];

long long f[mn][mn][mn],z[3][mn];

bool cmp(int a,int b)
{
	return z[w][a]<z[w][b];
}

long long work()
{
	for (w=0;w<3;w++)
	{
		for (int a=1;a<=n;a++)
			y[w][a]=a;
		sort(y[w]+1,y[w]+n+1,cmp);
		for (int a=1;a<=n;a++)
			x[w][y[w][a]]=a;
	}
	memset(f,0x3f,sizeof(f));
	f[0][0][0]=0;
	for (int a=0;a<=n;a++)
		for (int b=0;b<=n;b++)
			for (int c=0;c<=n;c++)
				if (f[a][b][c]!=INF)
				{
					if (a!=n)
					{
						int p = y[0][a+1];
						if (x[1][p] <= b && x[2][p]<=c) f[a+1][b][c]=min(f[a+1][b][c],f[a][b][c]+z[1][y[1][b]]+z[2][y[2][c]]-z[1][p]-z[2][p]);
						else f[a+1][b][c] = min(f[a+1][b][c],f[a][b][c]);
					}
					if (b!=n)
					{
						int p = y[1][b+1];
						if (x[0][p] <= a && x[2][p]<=c) f[a][b+1][c]=min(f[a][b+1][c],f[a][b][c]+z[0][y[0][a]]+z[2][y[2][c]]-z[0][p]-z[2][p]);
						else f[a][b+1][c] = min(f[a][b+1][c],f[a][b][c]);
					}
					if (c!=n)
					{
						int p = y[2][c+1];
						if (x[0][p] <= a && x[1][p]<=b) f[a][b][c+1]=min(f[a][b][c+1],f[a][b][c]+z[0][y[0][a]]+z[1][y[1][b]]-z[0][p]-z[1][p]);
						else f[a][b][c+1] = min(f[a][b][c+1],f[a][b][c]);
					}
				}
	return f[n][n][n];
}

int main()
{
	scanf("%d",&n);
	for (int a=1;a<=n;a++)
		for (int b=0;b<3;b++)
			scanf("%lld",&z[b][a]);
	printf("%lld\n",work());

	return 0;
}
