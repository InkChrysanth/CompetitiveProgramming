#include<bits/stdc++.h> 
using namespace std;
int a[110];
int i,j,x,y,R;
int main(){
	cin>>R;j=0;cin>>x;
	while(x){
		j=j+1;
		a[j]=x;
		cin>>x;
	}
	i=0;
	do{
		i=i+1;x=a[i];y=0;
		for(int k=1;k<=j;k++){
			if(x<a[k]) y++;
		}
	}while(y!=R-1);
	cout<<a[i]<<endl;
	return 0;
}
