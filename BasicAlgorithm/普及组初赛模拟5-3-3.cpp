#include<bits/stdc++.h>
using namespace std;
int d[100];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;cin>>x;d[x]++;
	}
	d[0]=0;
	for(int i=1;i<=10;i++ ) {
		d[i]+=d[i-1];
		cout<<d[i]<<" ";
	}
	cout<<endl;
	for(int i=1;i<=10;i++)
	    if(d[i]!=d[i-1])
	       cout<<setw(3)<<i<<setw(4)<<d[i-1]+1<<endl;
	return 0;       
}
