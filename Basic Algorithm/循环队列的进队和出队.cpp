#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
int n,tail,head,Q[maxn];
void push(int x)
{
	if((tail+1)%n==head) cout<<"¶ÓÂú"<<endl;
	else{
		tail=(tail+1)%n;
		Q[tail]=x;
	}
}
void pop()
{
	if(tail==head) cout<<"¶Ô¿Õ"<<endl;
	else{
		head=(head+1)%n;
		cout<<Q[head]<<" ";
	}
}

int main(){
	int x;
	cin>>n;
	for(int i=1;i<n+2;i++){
		cin>>x;
		push(x);
	}
	for(int i=1;i<n+2;i++){
		pop();
	}
	return 0;
}

