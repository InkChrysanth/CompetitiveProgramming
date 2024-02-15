#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int a[maxn],n;
void dfs(int k){
	if(k>n){ //k==n+1р╡©ирт 
	    bool ok=true;
	    for(int i=1;i<=n;i++)
	        for(int j=i+1;j<=n;j++)
	            if(a[i]==a[j]) ok=false;
	    if(ok) {
	    	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
		    cout<<endl;
		}       
		
	}
	else for(int i=1;i<=n;i++){
		a[k]=i;
		dfs(k+1);
	}
}
int main(){
	cin>>n;
	dfs(1);
}
