/*
更好的理解离散化
离散化处理的问题：下标范围有负数，或者下标范围超过1e6以上，并且题目还要求按照下标的顺序做题，（即没法使用哈希表,其实也可以，但会造成处理区间只能暴力扫描无法使用前缀和）！
离散化结果：将用到的下标全部处理到 0 ~ n

1. alls数组存储的东西
alls数组存储的是插入的原始下标x及查询操作区间的左右端点的l, r下标。
这里会发现下标最多有3 * 10^5个（若下标都不一样），所以数组开辟3e5 + 10, + 10防止越界！

2. add数组存储的东西
add数组存储一个二元组pair，存储需要插入的位置以及值

3. query数组存储的东西
query数组存储要查询的区间左右端点l, r

4. 关于排序和去重
使用题目样例：

3 3
1 2
3 6
7 5
1 3
4 6
7 8
排完序后的alls数组如下：

值：  1 1 3 3 4 6 7 7 8      ----> 其实就是原始的下标  
下标：0 1 2 3 4 5 6 7 8      ----> 其实就是离散化后对应的下标（从0开始）
对应的a数组为：

值：   2 0 6 0 0 0 5         
下标： 1 2 3 4 5 6 7        ----> 为了计算前缀和方便，下标从1开始
此时的结果就是，对于x, l, r都已经一人一坑位置占满了a数组从1 ~ .... 并且最多有3e5 + 10的长度！

至于为什么去重？

先着重声明一下：去不去重都可以，去重可以提高效率，优化空间！

先看一下去重后的两个数组情况：

alls 数组
值：  1 3 4 6 7 8      ----> 其实就是原始的下标  
下标：0 1 2 3 4 5      ----> 其实就是离散化后对应的下标（从0开始）

a 数组
值：   2 6 0 0 5         
下标： 1 2 3 4 5       ----> 为了计算前缀和方便，下标从1开始
会发现其实去不去重都是对的！
- 去重可以减少a数组的占用，即减少0的位置，（对于x, l, r）会发现他们可能会有重复）
- 对于二分alls数组时，可以少循环几次，提高效率

我们二分条件alls[mid] >= x, r = mid，会发现最终二分得到的答案是第一个等于x的位置，对于a数组的计算毫无影响！

时间复杂度：
快排：O((n+2m)log(n+2m))O((n+2m)log(n+2m))
去重：O(n+2m)O(n+2m)
二分：O(log(n+2m))O(log(n+2m))，n + 2m 次二分，为O((n+2m)log(n+2m))O((n+2m)log(n+2m))
前缀和：O(n+2m)O(n+2m)
总复杂度为： O((n+2m)log(n+2m))

*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> PII;
const int N = 3e5 + 10;

int n, m, a[N], s[N];

vector<int> alls;
//alls数组存储的是插入的原始下标x及查询操作区间的左右端点的l, r下标。
vector<PII> add, query;
//add数组存储一个二元组pair，存储需要插入的位置以及值 
//query数组存储要查询的区间左右端点l, r
int find(int x){
    int l = 0, r = alls.size() - 1;
    while(l < r){
        int mid = l + r >> 1;
        if(alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});
        alls.push_back(x);
    }
    for(int i = 0; i < m; i++){
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});
        alls.push_back(l), alls.push_back(r);
    }
    sort(alls.begin(), alls.end()); //排序 
    alls.erase(unique(alls.begin(), alls.end()), alls.end());  //去重 
    for(auto item : add){ //统计坐标点上插入的值 
        int x = find(item.first);
        a[x] += item.second;
    }
    for(int i = 1; i <= alls.size(); i++) s[i] = s[i - 1] + a[i]; //求前缀和 
    for(auto x : query){
        int l = find(x.first), r = find(x.second); //映射查询的位置 
        cout << s[r] - s[l - 1] << endl; //输出结果 
    }
    return 0;
}

