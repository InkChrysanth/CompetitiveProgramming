/*
炮弹问题的动态规划 
8 389 207 155 300 299 170 158 65
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
int a[maxn],d[maxn],c[maxn],n;
int main(){
	cin>>n;
	int i,j,k,p=0;
	memset(c,0,sizeof(c));
	for(i=1;i<=n;i++) {
		cin>>a[i];
		d[i]=1;
	}
	for(i=n-1;i>=1;i--){
	    k=0;
		for(j=i;j<=n;j++)
			if(a[i]>=a[j] && d[j]>d[k]) k=j;								
		d[i]=d[k]+1;c[i]=k;
	}
	int maxx=0;
	for(i=1;i<=n;i++) {
		if(d[i]>maxx) {
			maxx=d[i];p=i;
		}
	}
	cout<<maxx<<endl;

/*
	while(p>0){
		cout<<a[p]<<" ";
		p=c[p];
	}
*/
	return 0;
}
