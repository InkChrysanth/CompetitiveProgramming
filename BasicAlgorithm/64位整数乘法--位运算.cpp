/*
 64位整数乘法
 求 a 乘 b 对 p 取模的值。
输入格式
第一行输入整数a，第二行输入整数b，第三行输入整数p。
输出格式
输出一个整数，表示a*b mod p的值。
数据范围
1≤a,b,p≤1018
输入样例：
3
4
5
输出样例：
2
*/
#include<iostream>
using namespace std;
typedef unsigned long long ULL;
int main(){
    ULL a,b,p;
    cin>>a>>b>>p;
    ULL res=0;
    while(b){
        if(b&1)res=(res+a)%p;
        b>>=1;
        a=(a+a)%p;
    }
    cout<<res<<endl;
    return 0;
}
