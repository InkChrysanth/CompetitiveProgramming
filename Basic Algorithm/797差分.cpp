/*
6 3
1 2 2 1 2 1
1 3 1
3 5 1
1 6 1
输出样例：
3 4 5 3 4 2
*/ 
#include<bits/stdc++.h> 
using namespace std;
const int N=1e5+10;
int n,m;
int a[N],b[N];
void insert(int l,int r,int c){
	b[l]+=c;
	b[r+1]-=c;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) insert(i,i,a[i]);
	while(m--){
		int l,r,c;
		scanf("%d%d%d",&l,&r,&c);
		insert(l,r,c);
	}
	//差分数组b的前i项和就是a【i】
	for(int i=1;i<=n;i++)b[i]=b[i-1]+b[i];//把b数组前i项求和，这时候b【i】就变成了a【i】
	for(int i=1;i<=n;i++)a[i]=b[i];
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	return 0;
}
