#include<bits/stdc++.h> 
using namespace std;
char a[20],ch;
int main(){
	for(int i=1;i<=10;i++) a[i]='A'+i;
	for(int i=1;i<=10;i++){
		ch=a[i],a[i]=a[11-i];
		a[11-i]=ch;
	}
	for(int i=1;i<=10;i++) cout<<a[i];
	cout<<endl;
	return 0;
}
