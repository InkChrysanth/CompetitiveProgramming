/*
   设有一个n级的楼梯(1<=n<=12),编号从下到上一次为1至n,其中有1级为坏的
   走时一次可走1级、2级、3级 三种走法（环级只能跨过不能踏上，但级数照算）
   问：人从楼下走到第n级，共有多少种不同的走法？ 
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int f[maxn],n,x,f1,f2,f3,f4;
int main(){
	cin>>n>>x;
	if(x==1) f1=0;
	else f1=1;
	if(x==2) f2=0;
	else f2=1+f1;
	if(x==3) f3=0;
	else f3=1+f1+f2;
	if(n==1) f4=f1;
	else if(n==2) f4=f2;
	else if(n==3) f4=f3;
	else{
		for(int i=4;i<=n;i++)
		{
			if(x==i) f4=0;
			else f4=f1+f2+f3;
			f1=f2;f2=f3;f3=f4;
		}
	}
	cout<<f4;
	return 0;
}
