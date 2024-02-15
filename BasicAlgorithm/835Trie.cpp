/*
Trie树快速存储查找单词 
5
I abc
Q abc
Q ab
I ab
Q ab
*/
#include<bits/stdc++.h> 
using namespace std;
const int N=100010;
int son[N][26],cnt[N],idx;//idx是每一个结点的编号 
char str[N];
void insert( char str[]){
	int p=0;
	for(int i=0;str[i];i++){
		int u=str[i]-'a'; //把a-z映射到0-25 
		if(!son[p][u]) son[p][u]=++idx; //没有就创建，有就走到分支 
		p=son[p][u];
	}
	cnt[p]++;//统计这个单词出现的次数 
}
int  query(char str[]){
	int p=0;
	for(int i=0;str[i];i++){
		int u=str[i]-'a';
		if(!son[p][u]) return 0;
		p=son[p][u]; //继续往下找 
	}
	return cnt[p]; //找到尾输出单词的个数 
}
int main(){
	int n;
	cin.tie(0);
	cin>>n;
	while(n--){
		char str1,str2[N];
		cin>>str1>>str2;
		if(str1=='I') insert(str2);
		if(str1=='Q') cout<<query(str2)<<endl;
	}
	return 0;
}
