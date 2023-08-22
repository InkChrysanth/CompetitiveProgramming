#include<bits/stdc++.h>
using namespace std;
int count(int x){
	if(x==1) return 0;
	if(x%2==0) return count(x/2)+1;
	return count(x*3+1)+1;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cout<<count(i)<<endl;
	return 0;
}
