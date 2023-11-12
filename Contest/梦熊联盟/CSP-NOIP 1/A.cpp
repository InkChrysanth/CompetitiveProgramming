#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N=5000010;
int n;
int m[N];
signed main()
{
	freopen("unija.in", "r", stdin);
	freopen("unija.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		int r, c; cin>>r>>c;
		r/=2, c/=2;
		m[r]=max(m[r], c);
	}	
	int ans=0, h=0;
	for(int i=N-1; i>=1; i--)
		h=max(h, m[i]), ans+=h;
	cout<<ans*4<<endl;
	return 0;
}