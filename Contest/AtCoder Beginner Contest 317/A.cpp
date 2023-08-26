#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, h, x; cin>>n>>h>>x;
    int a[1000];
    for(int i=0; i<n; i++)
    	cin>>a[i];
    int minx=0x3f3f3f3f;
    int res;
    for(int i=0; i<n; i++)
    	if(h+a[i]>=x && a[i]<minx)
    		minx=a[i], res=i;
    cout<<res+1;
    return 0;
}