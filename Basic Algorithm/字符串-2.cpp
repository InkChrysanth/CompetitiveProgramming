/*
字符串s与char s1[]的区别 
读入：字符串getline(cin,s)字符数组gets(s);
求长度：字符串s.length(),s.size();
        字符数组strlen(s1), 
isalpha(ch) ch是字母，返回true否则false
ispunct(ch) ch是标点符号（除数字、字母或空白字符以外的字符），返回true否则 false
isspace(ch) ch是空白字符，返回true否则 false 
isdigit(ch) ch是数字，返回true否则 false
islower(ch) ch是小写字母，返回true否则 false
isupper(ch) ch是大写字母，返回true否则 false 
     
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
string s;
char s1[maxn];
int main(){
	getline(cin,s); //字符串输入 
	gets(s1);       //字符数组输入 
	int y=strlen(s1); //字符数组 
	int p=sizeof(s1); //有问题 
	int z=s.length();	//字符串 
	int x=s.size();
	cout<<x<<" "<<z<<endl;
	cout<<y<<" "<<p<<endl;
	s.push_back('a');
	x=s.size();
	cout<<x<<endl;
	return 0;
}
