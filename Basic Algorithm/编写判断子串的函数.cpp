/*
例题：编写判断子传达 函数
编写一个函数 ：int Strstr(char s1[],char s2[]);
如果S2不是S1的子串，返回-1；
如果s2是s1的子串，返回其在s1中第一次出现的位置
空串是任何串的子串，且出现位置为0 
*/
#include<bits/stdc++.h>
using namespace std;
 char s1[105],s2[100];
int Strstr(char s1[],char s2[]){
	if(s2[0]==0) return 0; //判断空串 
	for(int i=0;s1[i];++i){ //枚举比较起点s1[i]==0表示走到最后了 
	    int k=i,j=0;
	    for(;s2[j];++j,++k){ //s2[j]==0走到末尾 
	    	if(s1[k]!=s2[j]) break; //失败退出当前循环 
		}
		if(s2[j]==0) return i; //s2[j]==0走到末尾匹配 		
	}
	return -1;
}
int main(){
	scanf("%s",s1);
	scanf("%s",s2);
	cout<<Strstr(s1,s2)<<endl;
	return 0;
}
