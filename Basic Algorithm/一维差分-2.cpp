/*
一维差分
    输入n个数a1,a2,...,an和q个操作(l,r,k):把al,al+1,...ar所有数同时加上k,
输出q次操作后的n个数。
100%，1<=n,q<=10^6
输入样例
10
37 71 98 71 84 35 21 8 58 4
10
3 8 83
3 7 -99
4 8 9
1 2 54
7 10 -41
1 6 -21
9 10 -68
6 8 -56
2 5 56
6 7 -23
输出样例
70 160 117 99 112 -72 -106 3 -51 -105	 
*/ 
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
int n,q;
int f[MAXN],a[MAXN],b[MAXN];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	    scanf("%d",&f[i]);
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		for(int j=l;j<=r;j++)
		    b[j]+=k;	
	}    
	for(int i=1;i<=n;i++){
		printf("%d ",b[i]+f[i]);
	}
	printf("\n");
	return 0;
}

