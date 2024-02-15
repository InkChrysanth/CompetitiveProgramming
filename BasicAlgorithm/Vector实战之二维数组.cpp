#include<bits/stdc++.h>
using namespace std;
int n,m,p,x;
string str;
vector<string>Log[101];
int main(){
	cin>>n>>m>>p;
	for(int i=0;i<m;i++){
		cin>>x>>str;
		Log[x].push_back(str);
	}
	for(int i=0;i<p;i++){
		cin>>x;
		for(int j=0;j<Log[x].size();j++) 
		   cout<<Log[x][j]<<endl;
	}
}
