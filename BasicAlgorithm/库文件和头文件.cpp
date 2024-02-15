/*
库文件和头文件 
int abs(int x) 求整型数X的绝对值 
double fabs(double x) 求浮点数X的绝对值
int ceil(double x) 求不小于X的最小整数 
double cos(double x) 求X弧度的余弦 
double sin(double x) 求X弧度的正弦 
double sqrt(double x) 求X的平方根 
字符处理函数
int isdigit(int c) 判断C是否是数字字符 
int isalpha(int c) 判断C是否是一个字母 
int isalnum(int c)  判断C是否是一个数字或字母 
int islower(int c) 判断C是否是一个小写字母 
int isupper(int c) 判断C是否是一个大写字母 
int toupper(int c) 如果C是一个小写字母，则返回对应大写字母 
int tolower(int c) 如果C是一个大写字母，则返回对应小写字母 
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b;
	cin>>a;
	if(a<0){
		cout<<"No";
		return 0;
	}
	cout<<int (sqrt(a))<<endl;
	return 0;
}
