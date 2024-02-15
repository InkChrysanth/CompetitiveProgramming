/*
10
R 7
D 1
L 3
IL 2 10
D 3
IL 2 7
L 8
R 9
IL 4 7
IR 2 2
Êä³ö
8 7 7 3 2 9 
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1e+5;
int e[N],l[N],r[N],m,idx;
void init(){
	l[1]=0;
	r[0]=1;
	idx=2;
}
void remove(int k){
	l[r[k]]=l[k];
	r[l[k]]=r[k];
}
void add(int k,int x){	
	r[idx]=r[k];
	l[idx]=k;
	r[k]=idx;
	l[r[idx]]=idx;
	e[idx++]=x;
}
void inL(int x){
	
	r[idx]=r[0];
	l[r[idx]]=idx;
	r[0]=idx;
	l[idx]=0;
	e[idx++]=x;
}
void inR(int x){

	r[idx]=1;
	l[idx]=l[1];
	r[l[idx]]=idx;
	l[1]=idx;
	e[idx++]=x;
}
int main(){
	cin.tie(0);
	cin>>m;
	init();
	while(m--){
		string str;
		cin>>str;
		int x,k;
		if(str=="L")
		{
			cin>>x;
			inL( x);
		}
		else if(str=="R")
		{
			cin>>x;
			inR( x);
		}
		else if(str=="D")
		{
			cin>>k;
			remove(k+1);
		}
		else if(str=="IL"){
			cin>>k>>x;
			add(l[k+1],x);
		}
		else{
			cin>>k>>x;
			add(k+1,x);
		}
	}
	for(int i=r[0];i!=1;i=r[i]) cout<<e[i]<<' ';
	cout<<endl;
	return 0;
}
