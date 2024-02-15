#include<cstdio>
using namespace std;
int n, m;
int a[100], b[100];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        a[i] = b[i] = 0;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (a[x] < y && b[y] < x) {
            if (a[x] > 0)
                b[a[x]] = 0;
            if (b[y] > 0)
                a[b[y]] = 0;
            a[x] = y;
            b[y] = x;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == 0)
            ++ans;
        if (b[i] == 0)
            ++ans;
    }
    printf("%d", ans);
    return 0;
}
/*
假设输入的n和m都是正整数，x和y都是在［1, n］的范围内的整数，完成下面的判断题和单选题：
判断题:
1.当m>0时，输出的值一定小于2n。（true）
2.执行完第27行的"++ans"时，ans —定是偶数。（false）
3.a［i］和b［i］不可能同时大于0。（false） 
4.右程序执行到第13行时，x总是小于y,那么第15行不会被执行。（false）
选择题:
1.若m个x两两不同，且m个y两两不同，则输出的值为（2n-2m）//小范围数据模拟 
2.若m个x两两不同，且m个y都相等，则输出的值为（2n-2）//小范围数据模拟 
*/
