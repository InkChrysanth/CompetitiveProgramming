#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int a[N],s[N],n;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	int res=0;
	for(int i=0,j=0;i<n;i++){
		s[a[i]]++;
		while(s[a[i]]>1){
			s[a[j]]--; //j往后走的时候，前面的数据不用了，把里面的数据清零 
			j++;
		}
		res=max(res,i-j+1);
	}
	cout<<res<<endl;
}
