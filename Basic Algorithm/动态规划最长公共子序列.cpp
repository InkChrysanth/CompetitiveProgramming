/*
f[i][j]s1="x1x2...xi"和s2="y1y2...yj"的最长公共子序列的长度 
s1长度为n,s2长度为m,则f[n][m]则为答案 
若xi=yj;则f[i][j]=f[i-1][j-1]+1 
若xi!=yj,xi和yj都可能不在最长公共子序列中
   若xi不在最长子序列中-->f[i-1][j]
   若yj不在最长子序列中-->f[i][j-1] 
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
char s1[maxn],s2[maxn];
int f[maxn][maxn],n,m;
int main(){
	cin>>s1>>s2;
	int i,j;	
	n=strlen(s1);//读取字符串长度 
	m=strlen(s2);//读取字符串长度 
	for(i=1;i<=n;i++) f[0][i]=0; //初始 
	for(i=1;i<=m;i++) f[i][0]=0; //初始 
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(s1[i]==s2[j]) f[i][j]=f[i-1][j-1]+1; //相等 
			else f[i][j]=max(f[i-1][j],f[i][j-1]);  //不相等 
		}
	}
	cout<<f[n][m]<<endl;
	return 0;
}
