#include<bits/stdc++.h>
using namespace std;
int main(){
	int p,e,i,d,caseNo=0;
	while(cin>>p>>e>>i>>d && p!=-1){
		++caseNo;
		int k;
		for(k=d+1;(k-p)%23!=0;k++)
		for(;(k-e)%28!=0;k+=23);
		for(;(k-i)%33!=0;k+=23*28);
		cout<<"Case"<<caseNo<<":"<<k-d<<endl;
	}
	return 0;
}
