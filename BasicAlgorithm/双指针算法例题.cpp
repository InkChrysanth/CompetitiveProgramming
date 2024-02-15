#include<bits/stdc++.h> 
using namespace std;
char str[10000];
int main(){
	gets(str);
	int n=strlen(str);
	for(int i=0;i<n;i++){
		int j=i;
		while(str[j]!=' ' && j<n) j++;
		for(int z=i;z<j;z++) cout<<str[z];
		cout<<endl;
		i=j;
	}
	return 0;
}

