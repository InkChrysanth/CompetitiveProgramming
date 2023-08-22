#include<bits/stdc++.h>
using namespace std;
char s[256],t;
stack<char>Q;
int main()
{
	gets(s);
	int i=0;
	while(s[i]!='@'){
		t=s[i];
		if(t=='(') Q.push(t);
		if(t==')') {
			if(Q.empty()) {
				cout<<"No"<<endl;
				return 0;
			}
			else Q.pop();
		}
		i++;
	}
	if(!Q.empty()) cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
	return 0;
}
