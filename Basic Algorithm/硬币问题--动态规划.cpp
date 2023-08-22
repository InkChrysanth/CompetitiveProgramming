/*
硬币问题，相当于完全背包问题 
能用递推绝不用递归 
0、1背包f(i,j)=max{f(i-1,j),f(i-1,j-v[i])+w[i]} 这里i-1 ;
0/1背包中的每种物品只有一个，放一个，就没有了，只有返回上一个物品，所以要i-1 
完全背包f(i,j)=max{f(i-1,j),f(i,j-v[i]+w[i]}  这里i不需要-1; 
完全背包物品有多个，只要保证j>=v[i]就可以继续放 
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
int minv[maxn],maxv[maxn];
int s,n,v[101];
int main(){
	cin>>s>>n;
	minv[0]=maxv[0]=0;
	for(int i=1;i<=s;i++){
		minv[i]=0x7f;maxv[i]=-0x7f;
	}
	for(int i=1;i<=n;i++) cin>>v[i];
	sort(v+1,v+n+1);
	for(int i=1;i<=s;i++) //s为阶段 
	   for(int j=1;j<=n;j++)//j为状态 
	      if(i>=v[j]){
	      	minv[i]=min(minv[i],minv[i-v[j]]+1);
	      	maxv[i]=max(maxv[i],maxv[i-v[j]]+1);
		  }
    printf("%d %d\n",minv[s],maxv[s])	;	  
}
