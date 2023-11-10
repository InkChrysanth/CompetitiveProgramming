// Problem: P4964 绫小路的特别考试
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4964
// Memory Limit: 250 MB
// Time Limit: 3000 ms

#include <bits/stdc++.h>
using namespace std;
const int N=2000010;
struct Node
{
	int w, pos;
}p[N];
bool cmp(Node a, Node b)
{
	return a.w>b.w;
}
unsigned long long seed;
int n, m, c, mfq, mind, maxd, k, w[2000001], d[2000001];
int ans[2][N], l[N], r[N], cnt;
bool vis[N];
stack<int> stk;

inline int randInt() { seed = 99999989 * seed + 1000000007; return seed >> 33; } 

void generate()
{
	// 在读入种子后生成初始的 w 数组和 d 数组.
    for (int i = 1; i <= n; i++) { w[i] = randInt() % n; }
    for (int i = 1; i <= n; i++) { d[i] = randInt() % (maxd - mind + 1) + mind; }
}

void getOperation(int lastans, int &opt, int &x)
{
    // 生成一次操作的参数 opt 和 x, lastans 表示上一次询问的答案, 初始值为 0.
    if ((0ll + randInt() + lastans) % mfq) { opt = 1; } else { opt = 2; }
    x = (0ll + randInt() + lastans) % n;
}

void dfs(int u)
{
	if(vis[u] || !u) return;
	vis[u]=true;
	cnt++;
	dfs(l[u]); dfs(r[u]);
}

int main()
{
    scanf("%d %d %d", &n, &m, &c);
    scanf("%llu %d %d %d %d", &seed, &mind, &maxd, &mfq, &k);
    generate();
    for (int i = 1; i <= k; i++)
    {
        int p, t;
        scanf("%d %d", &p, &t);
        d[p] = t;
    }
    int ayanokouji=w[c];
    for(int i=1; i<=n; i++)
    {
    	p[i].w=w[i];
    	p[i].pos=i;
    }
    for(int i=1; i<=n; i++)
    {
        while(stk.size() && stk.top()+d[stk.top()]<i)
            stk.pop();
        if(stk.size()) l[i]=stk.top();
        stk.push(i);
    }
    stk=stack<int>();
    for(int i=n; i>=1; i--)
    {
    	while(stk.size() && stk.top()-d[stk.top()]>i)
            stk.pop();
        if(stk.size()) r[i]=stk.top();
        stk.push(i);
    }
    sort(p+1, p+n+1, cmp);
    for(int i=n-1, j=1; i>=0; i--)
    {
    	for(; j<=n && p[j].w==i; j++)
			if(p[j].pos!=c) dfs(p[j].pos);
		ans[0][i]=cnt;
	}
	memset(vis, false, sizeof vis);
	cnt=0; dfs(c);
	for(int i=n-1,j=1; i>=0; i--)
    {
    	for(; j<=n && p[j].w==i; j++)
			if(p[j].pos!=c) dfs(p[j].pos);
		ans[1][i]=cnt;
	}
    int lastans = 0, finalans = 0;
    for (int i = 1; i <= m; i++)
    {
        int opt, x;
        getOperation(lastans, opt, x);
        if (opt == 1)
        {
            finalans = (finalans * 233ll + ans[ayanokouji>=x][x]) % 998244353;
            lastans = ans[ayanokouji>=x][x];
        }
        else
        {
            ayanokouji=x;
        }
    }
    printf("%d\n", finalans);
    return 0;
}