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
		if(a[i] / 2 > b[0])// b[0] ������, b[1] ��Ŵδ�
			b[0] = a[i] / 2;
		if(b[0] > b[1])
			swap(b[0], b[1]);
	}
	while(true) { // ��ֹ����δ�ֵ֮�����ֵ * 3 �ִ��� ans�����Խ���ѭ�� 
		bool flag = 1;
		for(int i = 0; i <= 1; i++) {
			if(b[i] * 3 > ans) {
				flag = 0;
				int x = (3 * b[i] - ans + 1) / 2; 
				// �ҵ���С�� x ʹ�� b[i] * 3 <= ans���Ʋ����˹�ʽ����ʹ�ø����ӵķ������ۣ�����ֵ��������ȷ�� 
				b[i] -= x;
				ans -= x;
			}
		}
		if(flag)	break;
	}
	cout << min(ans / 3, sum / 9);
	return 0;
}
