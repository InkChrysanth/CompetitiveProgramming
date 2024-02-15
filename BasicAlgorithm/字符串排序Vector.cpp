/*
字符串排序
第一行输入一个整数n,表示有n个字符串，接下来第2到n+1行每行一个字符串 
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<string>str;
	int n;
	cin>>n;
	str.resize(n);
	for(int i=0;i<n;i++) getline(cin,str[i]);
	sort(str.begin(),str.end());
	for(int i=0;i<n;i++) cout<<str[i]<<endl;
	return 0;
}
