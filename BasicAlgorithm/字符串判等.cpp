#include<bits/stdc++.h>
using namespace std;
string s1,s2,t1,t2;
int main(){
	getline(cin,s1);
	getline(cin,s2);
	int x=s1.size();
	int y=s2.size();
	for(int i=0;i<x;i++){
		if(isalpha(s1[i])) 
		  t1.push_back(tolower(s1[i]));
	}
	for(int i=0;i<y;i++){
		if(isalpha(s2[i])) 
		  t2.push_back(tolower(s2[i]));
	}
	int f=1;
	if(t1.size()!=t2.size()) 
	   f=0;
	else{
		for(int i=0;i<t1.size();i++){
			if(t1[i]!=t2[i]){
				f=0;break;
			}
		}
	}
	if(f==1)   
	     cout<<"Yes"<<endl;
	else 
	     cout<<"NO"<<endl;
	return 0;
} 
