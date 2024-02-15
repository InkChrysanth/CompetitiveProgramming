/*
3
aba
5
ababa
Êä³ö
 0 2
*/ 
#include<bits/stdc++.h> 
using namespace std;
const int N=10010,M=100010;
char s[M],p[N];
int m,n;
int ne[M];//Ä£°å´®
int main() {
	cin>>m>>p+1>>n>>s+1;
    for(int i=2,j=0;i<=m;i++){
    	while(j && p[i]!=p[j+1]) j=ne[j];
    	if(p[i]==p[j+1]) j++;
    	ne[i]=j;
	}
	for(int i=1,j=0;i<=n;i++){
		while(j && s[i]!=p[j+1]) j=ne[j];
		if(s[i]==p[j+1]) j++;
		if(j==m){
			cout<<i-m<<" ";
			j=ne[j];
		}
	}
	return 0;
}
