/*
欧拉函数：它是：对正整数n,小于或等于n的正整数中与n互质的数的数目
入1-1,8位1,3,5,7共4位 
*/
#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>s;
int gcd(int a,int b){ //求最大公约数 (推导+死记） 
	if(b==0) return a;
	return gcd(b,a%b);
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
	    if(gcd(i,n)==1) s.push_back(i);
	int k=s.size()  ;  
	cout<<k<<endl;
	for(int i=0;i<k;i++)  cout<<s[i] <<" " ;
	return 0;
}
	
