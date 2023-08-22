/*
求 a 的 b 次方对 p 取模的值。
输入格式
三个整数 a,b,p ,在同一行用空格隔开。
输出格式
输出一个整数，表示a^b mod p的值。
数据范围
0≤a,b,p≤109
数据保证 p≠0
输入样例：
3 2 7
输出样例：
2
*/
#include<bits/stdc++.h>
using namespace std;
long long int  a,b,p,s=1;//s保存乘积
int main() {
	cin>>a>>b>>p;
	while(b){
		if(b&1) s=(s*a)%p;
		a=(a*a)%p;b>>=1;
	}
	cout<<s<<endl;
}
