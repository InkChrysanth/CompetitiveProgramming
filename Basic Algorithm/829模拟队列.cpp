/*
10
push 6
empty
query
pop
empty
push 3
push 4
pop
query
push 6
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int q[N],head,tail;
int main(){
	cin.tie(0);
	int n;
	cin>>n;
	head=0,tail=-1;
	while(n--){
		string str;
		int x;
		cin>>str;
		if(str=="push"){
			cin>>x;q[++tail]=x;
		} 
		else if(str=="pop") head++;
		else if(str=="empty"){
			if(head>tail) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
		else cout<<q[head]<<endl;
	}
	return 0;
}
