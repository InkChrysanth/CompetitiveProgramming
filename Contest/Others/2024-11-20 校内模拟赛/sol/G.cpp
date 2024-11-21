#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
const int maxn = 2e5 + 5;
#define ll long long
ll F[maxn], Finv[maxn], inv[maxn], a[maxn], n, k, ans = 0, premax[maxn];
void init(){
    inv[1] = 1;
    for(int i = 2; i < maxn; i ++){
        inv[i] =(mod - mod / i) * 1ll * inv[mod % i] % mod;
    }
    F[0] = Finv[0] = 1;
    for(int i = 1; i < maxn; i ++){
        F[i] = F[i-1] * 1ll * i % mod;
        Finv[i] = Finv[i-1] * 1ll * inv[i] % mod;
    }
}
ll comb(int n, int m){//comb(n, m)¾ÍÊÇC(n, m) 
    if(m < 0 || m > n) return 0;
    return F[n] * 1ll * Finv[n - m] % mod * Finv[m] % mod;
}

ll A(int n, int m){
	if(m < 0 || m > n) return 0;
    return F[n] * 1ll * Finv[n-m] % mod;
}
int main(){
	init();
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+1+n);
	for(int i = 1; i <= n; i++){
		premax[i] = premax[i-1] + a[i];
	}
	for(int i = 1; i <= n; i++){
		ans = (ans + (a[i] * (i - 1) - premax[i-1]) % mod * comb(n-2, k-2)) % mod;
	}
	cout << ans << endl;
	return 0;
}
