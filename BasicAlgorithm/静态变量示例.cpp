/*
静态变量static示例 
*/
#include<iostream> 
using namespace std;
void Func()
{
	static int n=4; //静态变量只在第一次的时候初始化，接下来调用该函数的时候这语句没用了 
	cout<<n<<endl;
	++n;
}
int main()
{
	Func();Func();Func();
	//输出4,5,6 
}
