// Problem: P7960 [NOIP2021] 报数
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P7960
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
const int N=10010000;
int st[N];
vector<int> ans;
void process(int x)
{
    int bp=x;
    if(st[x]==0) return;
    bool flag=false;
    if(x%7==0) flag=true;
    while(x)
    {
        int t=x%10;
        if(t==7)
        {
            flag=true;
            break;
        }
        x/=10;
    }
    if(flag)
        for(int i=bp; i<=N-10; i+=bp)
            st[i]=0;
}
int main()
{
    for(int i=1; i<=N-10; i++)
        st[i]=1;
    for(int i=1; i<=N-10; i++)
        process(i);
    for(int i=1; i<=N-10; i++)
        if(st[i]) ans.push_back(i);
    int T; cin>>T;
    while(T--)
    {
        int x; cin>>x;
        if(!st[x]) puts("-1");
        else
        {
        	auto pos=upper_bound(ans.begin(), ans.end(), x);
        	if(pos!=ans.end()) cout<<*pos<<endl;
            else puts("-1");
        }
    }
    return 0;
}