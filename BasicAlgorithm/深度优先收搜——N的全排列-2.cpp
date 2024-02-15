#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int a[maxn],n;
void dfs(int k){
	if(k>n){ //k==n+1р╡©ирт 	    
	    	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
		    cout<<endl;
		}       		
	else for(int i=1;i<=n;i++){
		bool ok=true;
		for(int j=1;j<k;j++){
			if(a[j]==i) ok=false;
		}
		if(ok){
		    a[k]=i;
		    dfs(k+1);	
		}
		
	}
}
int main(){
	cin>>n;
	dfs(1);
}
