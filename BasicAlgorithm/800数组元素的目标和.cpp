#include<iostream>
using namespace std;
const int N=100010;
int a[N],b[N];
int main()
{
    int n,m,x;
    cin>>n>>m>>x;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    //当a[i]+b[j]>=x时,随着i增加,j减少
    for(int i=0,j=m-1;i<n;i++)
    {
        while(j>=0 && a[i]+b[j]>x) j--;
        if(a[i]+b[j]==x)
        {
            cout<<i<<" "<<j;
            return 0;
        }
    }
    return 0;
}


