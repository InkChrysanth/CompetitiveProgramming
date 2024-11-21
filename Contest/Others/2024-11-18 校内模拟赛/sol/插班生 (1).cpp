#include <iostream>
using namespace std;
const int maxn = 1e5 + 5;
#define ll long long
#define int long long
ll pre[maxn], suf[maxn], pre2[maxn], suf2[maxn], sum[maxn], a[maxn];
signed main()
{
	int n;
	cin >> n;
	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		ans += a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		if (a[i] >= n - 1)
			continue;
		ll l = i - (n - a[i] - 1), d = 0;
		if (l < 1)
		{
			d = -l + 1;
			l = 1;
		}
		pre[l]++;
		pre[i]--;
		pre2[l] += d;
		pre2[i] -= d + (i - l);
	}
	for (int i = n; i >= 1; i--)
	{
		if (a[i] >= n - 1)
			continue;
		ll r = i + (n - a[i] - 1), d = 0;
		if (r > n)
		{
			d = r - n;
			r = n;
		}
		suf[r]++;
		suf[i]--;
		suf2[r] += d;
		suf2[i] -= d + (r - i);
	}
	for (int i = 1; i <= n; i++)
	{
		pre[i] = pre[i - 1] + pre[i];
		pre2[i] += pre[i] + pre2[i - 1];
	}
	for (int i = n; i >= 1; i--)
	{
		suf[i] = suf[i + 1] + suf[i];
		suf2[i] += suf[i] + suf2[i + 1];
	}
	//	for(int i = 1; i <= n; i++){
	//		cout << suf2[i] << " ";
	//	}
	for (int i = 1; i <= n; i++)
	{
		cout << ans - a[i] - (i - 1) * i / 2 - (n - i) * (n - i + 1) / 2 + suf2[i] + pre2[i] - 2 * (n - i) * (i - 1) << " ";
	}
	return 0;
}
