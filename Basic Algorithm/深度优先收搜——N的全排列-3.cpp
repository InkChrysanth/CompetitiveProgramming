#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int a[maxn],n,tot;
bool vis[maxn];
void dfs(int k){
	if(k>n){ //k==n+1р╡©ирт 	    
	    	for(int i=1;i<n;i++) cout<<a[i]<<" ";
		    cout<<a[n]<<endl;
		    tot++;
		}       		
	else for(int i=1;i<=n;i++){		
		if(!vis[i]){
		    a[k]=i;
		    vis[i]=true;
		    dfs(k+1);
			vis[i]=false;	
		}
		
	}
}
int main(){
	cin>>n;
	dfs(1);
	cout<<tot<<endl;
}
