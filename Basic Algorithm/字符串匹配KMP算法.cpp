/*
×Ö·û´®Æ¥ÅäBF·¨
*/ 
#include<bits/stdc++.h>
using namespace std;

const int maxn=10005;
char s[maxn],t[maxn];
int next[maxn],n,m;
void getnext(){
	next[1]=0;
	int j=0;
	for(int i=1;i<m;i++){
		while(j>0 && t[j+1]!=t[i+1]) j=next[j];
		if(t[j+1]==t[i+1]) j++;
		next[i+1]=j;
	}		
}

int KMP(){      
	int j=0;
  //int x=s.size(),y=t.size();	
	for(int i=0;i<n;i++){
		while(j>0 && t[j+1]!=s[i+1]) j=next[j];
		if(t[j+1]==s[i+1]) j++;
		if(j==m) return i-m+2;
	}
	return -1;
}

int main(){
	cin>>s+1>>t+1;
	n=strlen(s+1);
	m=strlen(t+1);
	getnext();
	cout<<KMP()<<endl;
	return 0;
}
