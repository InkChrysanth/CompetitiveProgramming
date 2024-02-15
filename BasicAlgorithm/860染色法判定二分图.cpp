#include<bits/stdc++.h>
using namespace std;
const int N=100010,M=200020;
int n,m;
int color[N];
int e[M],ne[M],h[N],idx;
void add(int a,int b){
	e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
bool dfs(int x,int c){
	color[x]=c;
	for(int i=h[x];i!=-1;i=ne[i]){
		int j=e[i];
		if(!color[j]) {
			if(!dfs(j,3-c)) return false;
		}		
		else if(color[j]==c)  return false;		
	}
	return true;
}
int main(){
	memset(h,-1,sizeof h);
	cin.tie(0);
	cin>>n>>m;
	while(m--){
		int a,b;
		cin>>a>>b;
		add(a,b),add(b,a);
	}
	bool flag=true;
	for(int i=1;i<=n;i++){
		if(!color[i]){
			if(!dfs(i,1)) {
				flag=false;
				break;
		}
	}	
}
    if(flag) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
