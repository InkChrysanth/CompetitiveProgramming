/*
字符串 
strlen常见糟糕用法
char s[100]="test" ;
for(int i=0;i<strlen(s);++i{
s[i]=s[i]+1;
strlen函数的执行是需要时间的，且时间和字符串的长度成正比
每次循环，都调用strlen函数，这是效率上的很大浪费 
改为 
char s[100]="test" ;
int len=strlen(s); 
for(int i=0;i<len;++i{
s[i]=s[i]+1;
或
for(int i=0;s[i];i++{ //s[i]==0即'\0' 
s[i]=s[i]+1;
}
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
	char buf[10];
	cin.getline(buf,sizeof(buf));//自动添加'\0' 
//	getline(cin,buf);
	cout<<buf;
	char s[110];
	while(gets(s)){
		printf("%s\n",s);
	}
	return 0;
}
