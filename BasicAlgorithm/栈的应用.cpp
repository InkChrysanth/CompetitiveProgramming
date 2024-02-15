#include<bits/stdc++.h>
using namespace std;
string  str;
char s[10005];
int main(){
	while(getline(cin,str)){
		int top=0;
		int k=str.size();
		for(int i=0;i<k;++i){
			switch(str[i]){
				case'#':top--; break;
				case'@':top=0;break;
				default:top++;s[top]=str[i];
			}
		}
		for(int i=1;i<=top;i++) cout<<s[i];
		cout<<endl;
	}
	return 0;
}
