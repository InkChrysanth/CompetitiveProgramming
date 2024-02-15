/*
输入样例：
8 3
aabbaabb
1 3 5 7
1 3 6 8
1 2 1 2
输出样例：
Yes
No
Yes
*/
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int P=131;//131或者13331是最好的 
const int N=1e5+10;
int n,m;
char str[N];
ULL h[N],p[N];
ULL get(int l,int r){
	return h[r]-h[l-1]*p[r-l+1];//123=123-1*10^2;
}
int main(){
	cin.tie(0);
	cin>>n>>m>>str+1;
	p[0]=1;//p^0等于1，这步不能忘
	for(int i=1;i<=n;i++) {
		p[i]=p[i-1]*P;
		h[i]=h[i-1]*P+str[i];
	}
	while(m--){
		int l1,r1,l2,r2;
		cin>>l1>>r1>>l2>>r2;
		if(get(l1,r1)==get(l2,r2)) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
