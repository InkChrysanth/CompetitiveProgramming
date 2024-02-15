#include <iostream>
using namespace std;
const int maxn = 10000;
int n;
int a[maxn];
int b[maxn];
int f(int l, int r, int depth) {
    if (l > r)
        return 0;
    int min = maxn, mink;
    for (int i = l; i <= r; ++i) {
        if (min > a[i]) {
            min = a[i];
            mink = i;
        }
    }
    int lres = f(l, mink - 1, depth + 1);
    int rres = f(mink + 1, r, depth + 1);
    return lres + rres + depth * b[mink];
}
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
//        cin >> a[i];
        a[i]=i+1;
    for (int i = 0; i < n; ++i)
//        cin >> b[i];
          b[i]=1;
    cout << f(0, n - 1, 1) << endl;
    return 0;
}
/*
题目解析：将数组b根据数组a值构造成一棵二叉树，每次在序列中选择a值最小且最靠前的元素作为根，
根之前的序列构建左子树，根之后的序列构建右子树。最后求每个节点值b[i]乘深度deep的和。
判断题:
1.如果a数组有重复的数字，则程序运行时会发生错误。（false）
2.如果b数组全为0,则输出为0。（true）

选择题:
3.当n=100时，最坏情况下，与第12行的比较运算执行的次数最接近的是：（5000）。
最坏情况为每次的min都在最左或最右，一次只能构建单侧子树，每层只少一个点。则总比较次数为100+99+98+……+1 = 5050。
4.当n=100时，最好情况下，与第12行的比较运算执行的次数最接近的是：（600）。
最好情况是每次min都在序列中间，刚好平分两个子树，则深度大致为log（100）≈6，每层大概执行100次。
5.当n=10时，若b数组满足，对任意0<=i<n,都有b［i］ = i + 1,那么输出最大为（385）。
最大值为权值最大的深度最深，结果为10*10+9*9+8*8+……2*2+1*1=385。
6.（4分）当n=100时，若b数组满足，对任意0 <= i <n,都有b［i］=1,那么输出最小为（580）。
即构造一个100节点的二叉树，想要值最小则尽可能弄成完全二叉树。
1+2*2+4*3+8*4+16*5+32*6+（100-63）*7=580 
*/
