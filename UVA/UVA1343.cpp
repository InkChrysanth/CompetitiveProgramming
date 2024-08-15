#include <bits/stdc++.h>
using namespace std;
constexpr int N=25;
int q[N];
int op[8][7]={
    {0, 2, 6, 11, 15, 20, 22},
    {1, 3, 8, 12, 17, 21, 23},
    {10, 9, 8, 7, 6, 5, 4},
    {19, 18, 17, 16, 15, 14, 13},
    {23, 21, 17, 12, 8, 3, 1},
    {22, 20, 15, 11, 6, 2, 0},
    {13, 14, 15, 16, 17, 18, 19},
    {4, 5, 6, 7, 8, 9, 10}
};
int opp[8]={5, 4, 7, 6, 1, 0, 3, 2};
int center[8]={6, 7, 8, 11, 12, 15, 16, 17};
int path[1000];

int est()
{
    int sum[4]={0};
    for(int i=0; i<8; i++)
        sum[q[center[i]]]++;
    int res=0;
    for(int i=1; i<4; i++)
        res=max(res, sum[i]);
    return 8-res;
}

void operate(int x)
{
    int t=q[op[x][0]];
    for(int i=0; i<6; i++)
        q[op[x][i]]=q[op[x][i+1]];
    q[op[x][6]]=t;
}

bool dfs(int u, int lm, int last)
{
    if(u+est()>lm) return false;
    if(est()==0) return true;
    for(int i=0; i<8; i++)
    {
        if(last!=opp[i])
        {
            operate(i);
            path[u]=i;
            if(dfs(u+1, lm, i)) return true;
            operate(opp[i]);
        }
    }
    return false;
}

int main()
{
    while(cin>>q[0], q[0])
    {
        for(int i=1; i<24; i++) cin>>q[i];
        int cnt=0;
        while(!dfs(0, cnt, -1)) cnt++;
        if(cnt==0) cout<<"No moves needed";
        else
        {
            for(int i=0; i<cnt; i++)
                cout<<char(path[i]+'A');
        }
        cout<<endl<<q[6]<<endl;
    }
    return 0;
}