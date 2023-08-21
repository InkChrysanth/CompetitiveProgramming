#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

int bfs(string state)
{
    queue<string> q;
    unordered_map<string, int> d;

    q.push(state); //初始状态入队列 
    d[state] = 0; //初始步数为0 

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}; //改变的4个方向 

    string end = "12345678x"; //目标状态 
    while (q.size())
    {
        auto t = q.front(); 
        q.pop();

        if (t == end) return d[t]; //找到输出 

        int distance = d[t]; //d[t]表示第几步 
        int k = t.find('x'); //找到x在哪一位 
        int x = k / 3, y = k % 3; //根据k提炼出目前字符x的下标x,y 
        for (int i = 0; i < 4; i ++ ) //4个交换的方向 
        {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < 3 && b >= 0 && b < 3) //边界判断 
            {
                swap(t[a * 3 + b], t[k]); //交换后形成新的字符串 
                if (!d.count(t)) //判断新的字符串在map数组d中是否出现过 
                {
                    d[t] = distance + 1; //没出现过，步数加1，且入列 
                    q.push(t);
                }
                swap(t[a * 3 + b], t[k]); //还原字符串t 
            }
        }
    }
    return -1;
}

int main()
{
    char s[2];

    string state;
    for (int i = 0; i < 9; i ++ )
    {
        cin >> s;
        state += *s;
    }

    cout << bfs(state) << endl;

    return 0;
}
