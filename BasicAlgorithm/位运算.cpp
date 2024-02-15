/*
位运算
a^b=c则有a^c=b,b^c=a; 
异或运算能实现不通过林世边，就能交换两个变量的值：
int a=5,b=7;
a=a^b;
b=b^a;
a=a^b; 穷举法可证 
*/
#include<bits/stdc++.h> 
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	a=a^b;
    b=b^a;
    a=a^b;
    cout<<a<<endl;
    return 0;
}
