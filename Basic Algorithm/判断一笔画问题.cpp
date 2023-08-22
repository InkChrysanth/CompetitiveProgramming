#include<bits/stdc++.h>
using namespace std;
const int MaxV=1005;
int G[MaxV][MaxV];
int main(){
	int k;
	cin>>k;
	while(k--){
		int n,m;
		cin>>n>>m;
		memset(G,0,sizeof(G));
		for(int i=1;i<=m;i++){
			int u,v;
			cin>>u>>v;
			G[u][v]=G[v][u]=1;
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			int sum=0;
			for(int j=1;j<=n;j++)
			   sum+=G[i][j];
			if(sum%2==1)   
			    cnt++;
		}
		if(cnt==0 ||cnt==2) //根据奇点的个数判断,奇点只能由0或者2个 
		   cout<<"Yes"<<endl;
		else
		    cout<<"No"<<endl;   
	}
	return 0;
}
