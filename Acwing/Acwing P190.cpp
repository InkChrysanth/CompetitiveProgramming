#include <bits/stdc++.h>
using namespace std;
const int N=6;
int n;
string A, B;
string a[N], b[N];

int extend(queue<string> &q, unordered_map<string, int> &da, unordered_map<string, int> &db,
string a[], string b[])
{
    int d=da[q.front()];
    while(q.size() && d==da[q.front()])
    {
        auto t=q.front(); q.pop();
        for(int i=0; i<n; i++)
            for(int j=0; j<t.size(); j++)
                if(t.substr(j, a[i].size())==a[i])
                {
                    string r=t.substr(0, j)+b[i]+t.substr(j+a[i].size());
                    if(db.count(r)) return da[t]+db[r]+1;
                    if(da.count(r)) continue;
                    da[r]=da[t]+1;
                    q.push(r);
                }
    }
    return 11;
}
int bfs()
{
    int step=0;
    queue<string> qa, qb;
    unordered_map<string, int> da, db;
    qa.push(A), qb.push(B);
    da[A]=0, db[B]=0;
    while(qa.size() && qb.size())
    {
        int t;
        if(qa.size()<qb.size()) t=extend(qa, da, db, a, b);
        else t=extend(qb, db, da, b, a);
        if(t<=10) return t;
        if(++step==10) return -1;
    }
    return -1;
}

int main()
{
    cin>>A>>B;
    if(A==B)
    {
        puts("0");
        return 0;
    }
    while(cin>>a[n]>>b[n]) n++;
    int t=bfs();
    if(t==-1) puts("NO ANSWER!");
    else cout<<t<<endl;
    return 0;
}