/*
有两个int型的变量a和n(0<=n<=31),
要求写一个表达式，使该表达式的值和a的第n位相同 
*/
#include<bits/stdc++.h> 
using namespace std;
int main(){
	int a,n,x;
	cin>>a>>n;
	x=(a>>n) &1;
    //(a&(1<<n))>>n; //当n<31时，假如n=31则可能出现符号位为1使它变成负数 
	cout<<x<<endl;
	return 0;
	
}
