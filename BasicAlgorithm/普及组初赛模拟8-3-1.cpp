#include<bits/stdc++.h>
using namespace std;
int a[20];
int main(){
	a[1]=a[2]=1;
	for(int i=2;i<=10;i++){
		a[i+1]=1;
		for(int k=i;k>=2;k--) a[k]+=a[k-1];
	}
	for(int i=1;i<=10;i++) cout<<a[i]<<" ";
	cout<<a[11]<<endl;
	return 0;
}
