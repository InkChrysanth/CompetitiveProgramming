#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, a[100009], sum, ans, b[2];
signed main() {
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		sum += a[i];
	}
	for(int i = 1; i <= n; i++) {
		if(a[i] * 3 > sum){
			cout << -1;
			return 0;
		}
		ans += a[i] / 2;
		if(a[i] / 2 > b[0])// b[0] 存放最大, b[1] 存放次大
			b[0] = a[i] / 2;
		if(b[0] > b[1])
			swap(b[0], b[1]);
	}
	while(true) { // 防止减完次大值之后，最大值 * 3 又大于 ans，所以进行循环 
		bool flag = 1;
		for(int i = 0; i <= 1; i++) {
			if(b[i] * 3 > ans) {
				flag = 0;
				int x = (3 * b[i] - ans + 1) / 2; 
				// 找到最小的 x 使得 b[i] * 3 <= ans，推不出此公式可以使用更复杂的分类讨论，并代值验算其正确性 
				b[i] -= x;
				ans -= x;
			}
		}
		if(flag)	break;
	}
	cout << min(ans / 3, sum / 9);
	return 0;
}
