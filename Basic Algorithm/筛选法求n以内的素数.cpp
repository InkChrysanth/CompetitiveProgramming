/*
筛选求n以内的素数
空间换时间，加快了计算速度 
*/ 
#include<bits/stdc++.h>
using namespace std;
int isPrime[10005],n; //最终如果isPrime[i]为1，则表示i是素数 
// char isPrime[10005] 用char可以节省空间，char只占1个字节，int占4个字节 
int main(){
	int i,j;
	cin>>n;
	for(i=2;i<=n;i++) isPrime[i]=1;
	for(i=2;i<=sqrt(n);i++) //每次讲一个数的所有倍数标记为非素数 
	{
		if(isPrime[i]){//只需标记素数的倍数 
			for(j=2;j<=n/i;j++) isPrime[i*j]=0;
		}
		
	}
	for(i=2;i<=n;i++) {
		if(isPrime[i]) cout<<i<<" ";
	}
	return 0;
}
