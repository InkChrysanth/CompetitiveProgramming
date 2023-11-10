#include <bits/stdc++.h>
using namespace std;

typedef pair<int, string> PIS;

int est(string s)
{
    int res=0;
    for(int i=0; i<s.size()/*9*/; i++)
    {
        if(s[i]!='x')
        {
            int t=s[i]-'1';
            res+=abs(t/3-i/3)+abs(t%3-i%3);
        }
    }
    return res;
}
string bfs(string start)
{
    string end="12345678x";
    int dx[]={-1, 0, 1, 0}, dy[]={0, 1, 0, -1};
    char op[]="urdl";
    unordered_map<string, int> dist;
    unordered_map<string, pair<char, string>> prev;
    priority_queue<PIS, vector<PIS>, greater<PIS>> heap;
    dist[start]=0;
    heap.push({est(start), start});
    while(heap.size())
    {
        auto t=heap.top();
        heap.pop();
        string state=t.second;
        if(state==end) break;
        int x, y;
        for(int i=0; i<9; i++)
            if(state[i]=='x')
                x=i/3, y=i%3;
        string backup=state;
        for(int i=0; i<4; i++)
        {
            int a=x+dx[i], b=y+dy[i];
            if(a<0 || a>=3 || b<0 || b>=3) continue;
            state=backup;
            swap(state[x*3+y], state[a*3+b]);
            if(dist.count(state)==0 || dist[state]>dist[backup]+1)
            {
                dist[state]=dist[backup]+1;
                prev[state]={op[i], backup};
                heap.push({dist[state]+est(state), state});
            }
            swap(state[x*3+y], state[a*3+b]);
        }
    }
    string res;
    while(end!=start)
    {
        res+=prev[end].first;
        end=prev[end].second;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    char c;
    string start, seq;
    while(cin>>c)
    {
        start+=c;
        if(c!='x') seq+=c;
    }
    int cnt=0;
    for(int i=0; i<8; i++)
        for(int j=i; j<8; j++)
            if(seq[i]>seq[j])
                cnt++;
    if(cnt&1) puts("unsolvable");
    else cout<<bfs(start);
    return 0;
}
