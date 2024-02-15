#include<bits/stdc++.h>
using namespace std;
const int n=4,m=3;
int main(){
	for(int i=-n;i<=n;i++){
		int k=n-abs(i);
		cout<<setw(10-k)<<" ";
		for(int j=-k;j<=k;j++)
		   if(abs(j)>k-m) cout<<n-(i+n)/2;
		   else cout<<" ";
		cout<<endl;   
	}
	return 0;
}

