/*
奶牛打工, 输出有多少中组合达到83 
83 5
1
5
10 
25 
50
输出159
f[i][j]前i种硬币，总面额为i时的找零方案总数
边界条件：f(i,0)=1,f(0,j)=0;
答案f(n,total)； 
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
int a[101],s,n,f[maxn][101];
int main(){
	cin>>s>>n;
	for(int i=1;i<=n;i++) {
	    cin>>a[i];
	    f[i][0] =1;
		} 
	f[0][0]=1;
	for(int i=1;i<=n;i++)
	   for(int j=0;j<=s;j++){
	   	 for(int k=0;k*a[i]<=j;k++)
	   	    f[i][j]+=f[i-1][j-k*a[i]]; //每次都累加 
	   }
	   cout<<f[n][s]<<endl;
	return 0;
}
