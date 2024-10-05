#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N=3010;
int n, ans=0x3f3f3f3f;
int f[N][2*N+1], a[N], b[N];
signed main()
{
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i]>>b[i];
	memset(f, 0x3f, sizeof f);
	f[0][N]=0;
	for(int i=1; i<=n; i++) 
		for(int j=0; j<=2*N; j++)
		{
			if(j>=N)
			{
				f[i][N+a[i]]=min(f[i][N+a[i]], f[i-1][j]+a[i]);
				f[i][j-b[i]]=min(f[i][j-b[i]], f[i-1][j]);
			}
			else
			{
				f[i][N-b[i]]=min(f[i][N-b[i]], f[i-1][j]+N-j);
				f[i][j+a[i]]=min(f[i][j+a[i]], f[i-1][j]+a[i]);
			}
		}
	for(int i=0; i<=2*N; i++)
		ans=min(ans, f[n][i]+max(0, N-i));
	cout<<ans<<endl;
	return 0;
}