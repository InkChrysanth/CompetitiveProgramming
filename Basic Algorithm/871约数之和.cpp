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
	for(map<int,int>::iterator it=prime.begin();it!=prime.end();it++){
		LL t=1;
		int p=it->first,a=it->second;
		while(a--) t=(t*p+1)%mod;
		res=res*t%mod;
	}
	cout<<res<<endl;
	return 0;
}
