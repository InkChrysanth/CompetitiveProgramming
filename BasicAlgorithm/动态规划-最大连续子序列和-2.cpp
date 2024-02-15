/*
最大连续子序列和
-2 11 -4 13 -5 -2 
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int dp[maxn],a[maxn],n;
int main(){
	cin>>n;
	int i;
	for(i=1;i<=n;i++)	cin>>a[i];	
	dp[1]=a[1];
    for(i=1;i<=n;i++) dp[i]=max(a[i],dp[i-1]+a[i]);
    int maxx=-1000;
    for(i=1;i<=n;i++) maxx=max(maxx,dp[i]);
    cout<<maxx<<endl;
	return 0;
}
