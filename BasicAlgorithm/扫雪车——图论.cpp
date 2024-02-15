/*
5 1
1 2 1
2 3 1
3 5 1
3 4 1
输出 5 
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int n;
#define tar first
#define dis second
#define nex gra[x][i]
typedef pair<int,int>Node;
vector<Node>gra[maxn],dis[maxn];
bool vis[maxn];
/*
struct Node{
	int b,c;
	Node(int _b,int _c){b=_b;c=_c;	}
};
vector<Node>gra[maxn];
*/
int dfs(int x){
	vis[x]=true;
	int ans=0,len=gra[x].size();
	for(int i=0;i!=len;++i){
	     if(!vis[nex.tar])
	         ans=max(ans,dfs(nex.tar)+nex.dis);//距离最长的那个 
	}
	return ans;
}
int main(){
	int sta,sum=0;
	cin>>n>>sta;
	for(int i=1,a,b,c;i!=n;++i){
		cin>>a>>b>>c;
		gra[a].push_back(Node(b,c));
		gra[b].push_back(Node(a,c));
		sum+=c; 
	}
	cout<<sum*2-dfs(sta)<<endl;
}
