#include<bits/stdc++.h>
using namespace std;
const int maxn=300;
char c[300];
stack<int>Q;
int main(){
	int i=0;
	int q1,q2;
	gets(c);	
	while(c[i]!='\0'){
		switch(c[i]){
			case '+':{
				q1=Q.top();Q.pop();q2=Q.top();Q.pop();				
				Q.push(q1+q2);break;			
			}		
		    case '-':{
				q1=Q.top();Q.pop();q2=Q.top();Q.pop();				
				Q.push(q1-q2);break;				
			}		
			case '*':{
				q1=Q.top();Q.pop();q2=Q.top();Q.pop();				
				Q.push(q1*q2);break;				
			}		
			case '/':{
				q1=Q.top();Q.pop(); q2=Q.top();Q.pop();				
				Q.push(q1/q2);	break;
			
			}	
			default:
			{
				int x=0;
				while(c[i]!=' '){
					x=x*10+c[i++]-'0';
				}
				Q.push(x); break;
			}	
		}
		i++;
	}
	cout<<Q.top()<<endl;
	return 0;
}
