#include<bits/stdc++.h> 
using namespace std;
int main(){
	int x;cin>>x;
	int Y1=0,Y2=1,Y3=1;
	while(Y2<=x){
		Y1+=1,Y3+=2;Y2+=Y3;
		cout<<Y2<<" ";
	}
	cout<<Y1<<endl;
}
