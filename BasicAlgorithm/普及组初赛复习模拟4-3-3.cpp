#include<bits/stdc++.h> 
using namespace std;
int b[6];
int main(){
	for(int i=1;i<=5;i++) b[i]=i;
	int s=1;
	int j=1;
	while(j>0){
		j=5;
		while(j>0 &&b[j]==10+j-5) j--;
		if(j>0){
			s++;b[j]++;
			for(int i=j+1;i<=5;i++) {b[i]=b[j]+i-j;
			}			
		}
		for(int i=1;i<=5;i++) cout<<b[i]<<" ";
		cout<<endl;
//		cout<<j<<endl;
	}
	cout<<j<<endl;
	cout<<"s="<<s<<endl;
	return 0;
}
