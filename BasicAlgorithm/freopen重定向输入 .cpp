/*
freopen重定向输入 
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("c:\\tmp\\test.txt","r",stdin);
	//此后所有输入都来自文件c:\tmp\test.txt注意c:\\tmp\\test.txt这边是双//
	int n,mx=0;
	while(cin>>n) {
		if(n>mx) mx=n;
	}
	printf("%d",mx);
	return 0;
}
