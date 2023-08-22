/*
时间复杂度o(n); 不懂原理的可以推演一遍 
欧拉线性筛选素数 
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=100000005;
bool a[maxn]={1,1}; //a[i]=false表示i是素数
vector<int>prime;
void IsPrime(int n){
	for(int i=2;i<=n;i++){ //枚举最大非平凡因数 
		if(a[i]==false) prime.push_back(i);//保存小于等于i的素数，方便后面枚举 
		for(int j=0;j<prime.size() &&prime[j]*i<=n;j++){//枚举小于等于i的素数 
			a[prime[j]*i]=true;
			if(i%prime[j]==0) break; //prime[j]能够整除i,则往后枚举的素数大于i的最小素因数了 
		}
	}
}//结束后，prime保存了小于等于n的所有素数；a数组记录了n以内的素数表 
int main() {
	int n,m;
	cin>>n>>m;
	IsPrime(n);
	int x;
	for(int i=1;i<=m;i++){
		cin>>x;
		cout<<prime[x-1]<<endl;
	}
	
//	cout<<endl;
//	cout<<prime.size()<<endl;
	return 0;
}

