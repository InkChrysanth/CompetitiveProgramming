/*
输入n 求出组成三角形的个数 
*/
#include<bits/stdc++.h>
using namespace std;
int a,b,c,n,total;
int main(){
	cin>>n;
	for(a=1;a<=n/3;a++){ //a,b,c按三条边从小到大排列 
		for(b=a;b<n/2;b++){//任意两边和大于第三边，固b<a+c<n/2 
			c=n-a-b;
			if(c>=b && (a+b)>c){
				cout<<a<<' '<<b<<' '<<c<<endl;
				total++;
			}
		}
	}
	cout<<total<<endl;
	return 0;
}
