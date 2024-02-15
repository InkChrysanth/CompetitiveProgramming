#include<bits/stdc++.h>
using namespace std;
char a[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
const int maxn=100;
int s[maxn];
stack<int>Q;
void zhuan(int N,int k){
	while(N!=0){
		Q.push(N%k);
		N/=k;
	}
    while(!Q.empty()){
    	cout<<a[Q.top()];
    	Q.pop();
	}
}
void zhuansu(int N,int k){
	int top=0;
	while(N!=0){
		s[++top]=N%k;
		N/=k;
	}
	for(int i=top;i>=1;i--) cout<<a[s[i]];
}
int main(){
	int N,k;
	cin>>N>>k;
	zhuansu(N,k);
	cout<<endl;
	zhuan(N,k);
	return 0;
}
