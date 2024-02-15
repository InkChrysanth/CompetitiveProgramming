#include<bits/stdc++.h>
using namespace std;
const int N=105;
const int mod=1e9+7;
map<int,int>prime;
typedef long long int LL;
void prim(int n){
	for(int i=2;i<=n/i;i++){
		if(n%i==0){
			while(n%i==0){
				prime[i]++;
				n/=i;
			}
		}
	}
	if(n>1) prime[n]++;
}
int main(){
	int n;
	cin>>n;
	while(n--){
		int x;
		cin>>x;
		prim(x);
	}
	int k=prime.size();
	LL res=1;
	for(map<int,int>::iterator it=prime.begin();it!=prime.end();it++)res=res*(it->second+1)%mod;
	//约数个数为所有质因子的个数+1后的乘积 
	cout<<res<<endl;
	return 0;
}
