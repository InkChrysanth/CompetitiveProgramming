/*
4 5
M 1 2
M 3 4
Q 1 2
Q 1 3
Q 3 4
*/
#include<bits/stdc++.h> 
using namespace std;
const int N=1e6+10;
int a[N],p[N];
int find(int x){ //路径压缩 
	if(p[x]!=x) p[x]=find(p[x]);
	return p[x];
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) p[i]=i;
	while(m--){
		char c[2];int x,y;//用字符串来读字母，这样更安全 
		cin>>c>>x>>y;
		if(c[0]=='M') p[find(x)]=find(y);
		else
		{
			if(find(x)==find(y)) puts("YES");//这里为什么不能用p[x]==p[y]因为没有find()这一步的话，他祖上归并以后没通知他 
			else puts("NO");
		}
	}
	return 0;
}

