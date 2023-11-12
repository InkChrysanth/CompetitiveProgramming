#include <bits/stdc++.h>
using namespace std;
int a[1000];
int main()
{
    int n; cin>>n;
    for(int i=0; i<n; i++)
    	cin>>a[i];
    sort(a, a+n);
    for(int i=0; i<n; i++)
    	if(a[i+1]!=a[i]+1)
    	{
    		cout<<a[i]+1<<endl;
    		break;
    	}
    return 0;
}