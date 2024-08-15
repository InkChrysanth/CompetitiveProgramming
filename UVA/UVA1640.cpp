#include <bits/stdc++.h>
using namespace std;

int get(vector<int> num, int l, int r)
{
    int res=0;
    for(int i=l; i>=r; i--)
        res=res*10+num[i];
    return res;
}

int count(int n, int x)
{
    if(n==0) return 0;
    vector<int> num;
    while(n)
    {
        num.push_back(n%10);
        n/=10;
    }
    n=num.size();
    int res=0;
    for(int i=n-1-!x; i>=0; i--)
    {
        if(i<n-1)
        {
            res+=get(num, n-1, i+1)*pow(10, i);
            if(!x) res-=pow(10, i);
        }
        if(num[i]==x) res+=get(num, i-1, 0)+1;
        else if(num[i]>x) res+=pow(10, i);
    }
    return res;
}

int main()
{
    int a, b;
    while(cin>>a>>b, a||b)
    {
        if(a>b) swap(a, b);
        for(int i=0; i<10; i++)
            cout<<count(b, i)-count(a-1, i)<<" \n"[i==9];
    }
    return 0;
}