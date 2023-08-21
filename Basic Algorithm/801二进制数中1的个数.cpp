#include<bits/stdc++.h> 
using namespace std;
int n;
int lowbit( int x){
	return x&-x;
}
int main(){
	cin>>n;
	while(n--){
		int x;
		cin>>x;
		int  res=0;
		while(x) {
			x-=lowbit(x);
			res++;
		}
		cout<<res<<" ";
	}
}
