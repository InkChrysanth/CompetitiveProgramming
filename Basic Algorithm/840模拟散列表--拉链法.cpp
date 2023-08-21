/*
5
I 1
I 2
I 3
Q 2
Q 5
*/
#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int e[N],ne[N],idx,head[N];
int PQ=100003;
void insert(int x){
	int k=(x%PQ+PQ)%PQ;
	e[idx]=x;ne[k]=head[k],head[k]=idx++;
}
bool  find(int x){
	int k=(x%PQ+PQ)%PQ;
	for(int i=head[k];i!=-1;i=ne[i]){
		if(e[i]==x) return true;
	}
	return false;
}
int main(){
	cin.tie(0);
    memset(head,-1,sizeof(head));
	int n;
	cin>>n;
	while(n--){
		char c[2];
	    int x;
		cin>>c>>x;
		if(c[0]=='I') insert(x);
		else{
			if(find(x)) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}
	return 0;
}
