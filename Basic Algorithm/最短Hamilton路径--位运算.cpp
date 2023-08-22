/*
最短Hamilton路径
给定一张 n 个点的带权无向图，点从 0~n-1 标号，求起点 0 到终点 n-1 的最短Hamilton路径。 
Hamilton路径的定义是从 0 到 n-1 不重不漏地经过每个点恰好一次。
输入
第一行输入整数n。
接下来n行每行n个整数，其中第i行第j个整数表示点i到j的距离（记为a[i,j]）。
对于任意的x,y,z，数据保证 a[x,x]=0，a[x,y]=a[y,x] 并且 a[x,y]+a[y,z]>=a[x,z]。
输出格式
输出一个整数，表示最短Hamilton路径的长度。
数据范围
1≤n≤20
0≤a[i,j]≤107
输入样例：
5
0 2 4 5 1
2 0 6 5 3
4 6 0 8 3
5 5 8 0 5
1 3 3 5 0
输出样例：
18
状态假如有20个点 就是2^20*20=2*10^7符合时间要求 
*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=20,M=1<<20;
int n;
int f[M][N],weight[N][N];
int main(){
	cin>>n;
	for(int i=0;i<n;i++) //输入边
	   for(int j=0;j<n;j++)
	     cin>>weight[i][j];
	memset(f,0x3f,sizeof(f)) ;//状态初始化成无穷大 
	f[1][0]=0;//起点 
	for(int i=0;i<1<<n;i++)  //2^20种000000..0000 二十位的二进制情况 
	   for(int j=0;j<n;j++)  //20个点 20个状态 
	      if(i>>j &1) //i状态是不是包含 第j位,1则存在，0就不合法 
	          for(int k=0;k<n;k++) //枚举所有状态 
	              if(i-(1<<j)>>k&1) //除去j后，判断k位是否合法 
	                  f[i][j]=min(f[i][j],f[i-(1<<j)][k]+weight[k][j]); //k合法就更新 
	cout<<f[(1<<n)-1][n-1]<<endl; //答案是f[2^n-1][n-1]最后一种状态的最后一位 
	return 0;                  
}
