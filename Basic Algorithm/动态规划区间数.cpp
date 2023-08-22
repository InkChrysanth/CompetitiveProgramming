/*
给定一个区间求这里不包含数字4和62的数有多少个 、
1-100中有80个 
f[i][j]表示有i位，最高位为j时它的统计数 
*/ 
#include<bits/stdc++.h>
using namespace std ;
const int maxn=1005;
int f[8][10];
int dp(int n){
	int k,w=1;
	int sum=0;
	while(n>0){//分解思路相当神奇
		k=n%10;
	    for(int i=0;i<k;i++) sum+=f[w][i];
		n/=10;
		w++;
	}
	return sum;
}
int main(){
	int a,b;	
	memset(f,0,sizeof(f));
	f[0][0]=1;//初始化
	for(int i=1;i<=7;i++){//预处理
		for(int j=0;j<=9;j++){
			if(j==4) f[i][j]=0;//最高位出现4的直接设为0 
			else{
				for(int k=0;k<=9;k++)
				if(!(j==6&&k==2))f[i][j]+=f[i-1][k]; //最高两位没有出现62这个数的继续累加 
			}
		}
	}
	cin>>a>>b;
	cout<<dp(b)-dp(a-1)<<endl;
	return 0;
}
