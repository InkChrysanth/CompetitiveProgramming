#include<bits/stdc++.h>
using namespace std;
int n,ans[1010];
void dfs(int x){
  if(ans[x]>0)	 return;
  ans[x]=1;
  for(int i=1;i<=x/2;i++){
  	dfs(i);
  	ans[x]+=ans[i];
  }
}
int main()
{
	cin>>n;
	dfs(n);
	cout<<ans[n]<<endl;
	return 0;
}
