#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    // 读入n次操作并将c加到x上
    map<int, int> pos_num; 
    while (n --)
    {
        int x, c;
        cin >> x >> c;
        pos_num[x] += c;
    }

    // 将值更新为前缀和
    int last = 0;
    map<int, int>::iterator it;
    for (  it = pos_num.begin(); it != pos_num.end(); ++ it)
    {
        pos_num[it->first] += last; 
        last = it->second;
    }

    // 读入m次询问并输出结果
    while(m --)
    {
        int l, r;
        cin >> l >> r;
        int l_val = (-- pos_num.lower_bound(l))->second; // 相当于前缀和s[l - 1]
        int r_val = (-- pos_num.upper_bound(r))->second; // 相当于前缀和s[r]
        cout << r_val - l_val << endl;
    }

    return 0;
}

