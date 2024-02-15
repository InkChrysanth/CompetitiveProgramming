/*
25 5 2
2
11
14
17
21
*/
#include<bits/stdc++.h>
using namespace std;
int L,n,m,a[50005];
bool check(int mid){
	int last=0,tot=0;
	for(int i=1;i<=n;i++){
		if(a[i]-last<mid) 
			tot++; //搬掉这块石头 
		else 
		   last=a[i];
		
	}
	return tot<=m;
}
int main(){
	cin>>L>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	a[++n]=L;
	int lft=0,rft=L;
	while(lft<=rft){
		int mid=lft+(rft-lft)/2;
		if(check(mid)) lft=mid+1; //满足条件可以加大石头的间距 
		else rft=mid-1; //不满足条件缩小石头的间距 
	}
	cout<<rft<<endl;
}
