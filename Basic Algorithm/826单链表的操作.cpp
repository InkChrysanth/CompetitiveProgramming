/*
10
H 9
I 1 1
D 1
D 0
H 6
I 3 6
I 4 5
I 4 5
I 3 4
D 6
*/
#include<bits/stdc++.h> 
using namespace std;
const int N=1e5+10;
int e[N],ne[N],idx,head;
void init(){
	head=-1;
	idx=0;
}
void insert_head(int x){
	e[idx]=x;
	ne[idx]=head;
	head=idx;
	idx++;
}
void add(int k,int x){
	e[idx]=x;
	ne[idx]=ne[k];
	ne[k]=idx;
	idx++;
}
void delet(int k){
	ne[k]=ne[ne[k]];
}
int main(){
	int n;
	cin>>n;
	init();
    while(n--){
		char c;
		int x,k;
		cin>>c;
		if(c=='H'){
			cin>>x;
			insert_head(x);
		}
		else if(c=='D'){
			cin>>k;
			if(k==0) head=ne[head];
			else delet(k-1);			
		}
		else{
			cin>>k>>x;
			add(k-1,x);
		}
	}
	for(int i=head;i!=-1;i=ne[i]) cout<<e[i]<<" ";
	cout<<endl<<idx<<endl;//数组中有idx-1个数据 
}
