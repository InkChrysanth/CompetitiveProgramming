#include<bits/stdc++.h>
using namespace std;
const int N=10;
int p[N],n;
bool vis[N];

void dfs(int u){
	if(u==n) { //总的位置数 
	     for(int i=0;i<n;i++) cout<<p[i]<<" ";
	     cout<<endl; 
	     return;
		  }
    for(int i=1;i<=n;i++){ //填的数字的范围 
    	if(!vis[i]) {
    		p[u]=i;
    		vis[i]=1;
    		dfs(u+1);
    		vis[i]=0;
		}		
	}		  
}
int main(){
	cin>>n;
	dfs(0);
	return 0;
}
