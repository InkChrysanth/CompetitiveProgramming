#include<bits/stdc++.h>
using namespace std;
const int N=200010;
typedef long long ll;
int m, p;
int tr[N];
int lowbit(int x){return x&-x;}
void add(int n, int x)
{
    for(int i=n; i<=m; i+=lowbit(i))
        tr[i]=max(tr[i], x);
}
int query(int n)
{
    int res=0;
    for(int i=n; i; i-=lowbit(i))
        res=max(res, tr[i]);
    return res;
}

int main()
{
    cin>>m>>p;
    int last=0, len=m;
    for(int i=0; i<m; i++)
    {
        int x; char op[2];
        cin>>op>>x;
        if(*op=='Q')
        {
            last=query(len+x);
            cout<<last<<endl;
        }
        else
        {
            add(len--, ((ll)last+x)%p);
        }
    }
    return 0;
}