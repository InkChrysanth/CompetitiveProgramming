/*
847图中点的层次 
*/
#include<bits/stdc++.h>
using namespace std;
const int N=100010,M=2*N;
int e[M],ne[M],h[N],idx;
bool vis[N];
int d[M],q[N];
int n,m;
void add(int a,int b){
	e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
int bfs(){
	int hh=0,rr=0;
	q[0]=1; //第一个点是点1 
	while(hh<=rr){
		int t=q[hh++];
		for(int i=h[t];i!=-1;i=ne[i]){
		    int j=e[i];
		    if(!vis[j]){
		    	vis[j]=true;
		        q[++rr]=j; //入队 
		        d[j]=d[t]+1;  //路径累积 
		        if(j==n)return d[j]; //优化		            		        		        
		    }			
			}
		}	
	return -1;
}
int main(){
	cin.tie(0);
	cin>>n>>m;
	int a,b;
	memset(h,-1,sizeof h);
	for(int i=0;i<m;i++){
		cin>>a>>b;
		add(a,b);
	}
	cout<<bfs()<<endl;
}
