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
时间复杂度：O(s*n)
空间复杂度:O(s*n); 
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
//	   	 if(j<a[i]) f[i][j]=f[i-1][j]; 
//	   	 else f[i][j]=f[i-1][j]+f[i][j-a[i]]; //这个状态转移非常重要 
	   	 //相当于完全背包问题 
	   	  f[i][j]=f[i-1][j]+(j>=a[i])*f[i][j-a[i]];
	   }
	   cout<<f[n][s]<<endl;
	return 0;
}
