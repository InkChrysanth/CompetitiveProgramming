/*
输出一个区间中距离最近和最远的一对相邻的素数 
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
int main(){
	int L,R;
	cin>>L>>R;
	IsPrime(L-1);
	int k=prime.size();
	prime.clear();
	IsPrime(R);
	int k2=prime.size();
	if(k2-k<1) {
		cout<<-1<<endl;
		return 0;
	}
	int r1=k,r2=k;//r1记录最小的，r2记录最大的 
	int minn=prime[k+1]-prime[k];
	int maxn=prime[k+1]-prime[k];
	for(int i=k;i<k2;i++){
		if(prime[i+2]-prime[i+1]<minn) {
			r1=i+1;minn=prime[i+2]-prime[i+1];
		}
		if(prime[i+2]-prime[i+1]>maxn){
			r2=i+1;maxn=prime[i+2]-prime[i+1];
		}
	}
	cout<<prime[r1]<<" "<<prime[r1+1]<<" "<<prime[r2]<<" "<<prime[r2+1]<<endl;
	return 0;
}
