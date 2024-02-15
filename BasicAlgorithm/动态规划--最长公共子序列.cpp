/*
最长公共子序列
sadstory
adminsorry 
*/
#include<bits/stdc++.h>
using namespace std;
string str1,str2;
const int maxn=1005;
int f[maxn][maxn];
int main(){
	cin>>str1>>str2;
	int x=str1.length();
	int y=str2.length();
//	for(int i=0;i<x;i++) f[i][0]=0;
//	for(int i=0;i<y;i++) f[0][i]=0;
	for(int i=1;i<=x;i++){ //i,j都从1循环到n代表循环的次数 
		for(int j=1;j<=y;j++){
			if(str1[i-1]==str2[j-1]) f[i][j]=f[i-1][j-1]+1;
			else f[i][j]=max(f[i][j-1],f[i-1][j]);
		}
	}
	cout<<f[x][y]<<endl;	      
	return 0;
}
