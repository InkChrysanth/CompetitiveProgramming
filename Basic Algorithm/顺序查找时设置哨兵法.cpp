/*
查找时设置哨兵法 
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=100;
int n;
int a[maxn];
int find(int x){
	a[0]=x;
	int i ;
	for( i=n;a[i]!=x;i--);
	return i;
}
int main(){
	
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int x;
	cin>>x;
	cout<<find(x)<<endl;
	return 0;
}
