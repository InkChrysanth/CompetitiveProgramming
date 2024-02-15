/*
时间复杂度o(n); 
欧拉线性筛选素数 
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
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
	int n;
	cin>>n;
	IsPrime(n);
	for(int i=0;i<prime.size();i++) cout<<prime[i]<<" ";
	cout<<endl;
	cout<<prime.size()<<endl;
	return 0;
}

