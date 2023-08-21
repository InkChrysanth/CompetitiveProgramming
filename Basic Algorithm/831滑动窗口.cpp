/*
8 3
1 3 -1 -3 5 3 6 7
输出
 -1 -3 -3 -3 3 3
3 3 5 5 6 7
*/
#include<bits/stdc++.h> 
using namespace std;
const int N=1e6+10;
int n,k;
int a[N],q[N];
int main(){
	cin.tie(0);
	cin>>n>>k;
	int hh=0,tt=-1;
	for(int i=0;i<n;i++)cin>>a[i];	
	for(int i=0;i<n;i++){ //队列里对应下标的a数组是线性递增 
		if(hh<=tt && q[hh]<i-k+1) hh++;//把队列里大于k区间范围的前面的数去掉 
		while(hh<=tt &&a[q[tt]]>=a[i]) tt--; //把队列前面比a[i]大的挑出去,a[hh]始终存的最小值 
		q[++tt]=i; //存入当前编号 
		if(i>=k-1) cout<<a[q[hh]]<<" ";//当达到一个区间范围后每加一个数就输出一个最小值 
	}
	cout<<endl;
	hh=0;tt=-1;
	for(int i=0;i<n;i++){ //队列里对应下标的a数组是线性递减
		if(hh<=tt && q[hh]<i-k+1) hh++;
		while(hh<=tt &&a[q[tt]]<=a[i]) tt--;
		q[++tt]=i;
		if(i>=k-1) cout<<a[q[hh]]<<" ";
	}
	cout<<endl;
}

