/*
火柴棒灯饰（NOIP2008提高组第2题）
1、根据n<=24条件，确定枚举A和B的范围；
2、如果每次计算每个数字的火柴数，可以发现重复操作了，预处理的作用
通常是降重操作次数，本题采用将估算范围内的所有数所用的火柴数目求出；
 
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1000;
int f[2005]={6,2,5,5,4,5,6,3,7,6},n;
int main(){
	cin>>n;
	for(int i=10;i<=maxn*2;i++){
		int x=i;
		while(x>0){
			f[i]+=f[x%10];
			x/=10;
		}
	}
	int ans=0;
	n=n-4; //总火柴棒数减去'+'和'='所需的火柴棒数 
	for(int i=0;i<=maxn;i++){ //枚举A 
		if(f[i]>=n) continue ;//剪枝，继续i循环 
		for(int j=0;j<=maxn;j++) {//枚举B
			if(f[i]+f[j]>=n) continue ;//剪枝，继续j循环
			int k=i+j;
			if(f[i]+f[j]+f[k]==n) {
				cout<<i<<"+"<<j<<"="<<k<<endl;
			    ans++;	//符合条件，总数加1 
			}
		}
	}
	cout<<ans;
    return 0;
}
