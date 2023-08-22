/*
穷举n位的二进制数的算法 
*/
#include<bits/stdc++.h>
using namespace std;
int b[100],n;
int main(){
	cin>>n;
	memset(b,0,sizeof(b));
	while(b[0]==0){
	    for(int i=1;i<=n;i++)
		    cout<<b[i];
	    cout<<endl;
		int j=n;
		while(b[j]==1)	j=j-1;//指针向前移
		b[j]=b[j]+1;//每次在指针移到的位置+1 
		for(int i=j+1;i<=n;i++)	
		   b[i]	=0; //更新指针后面的位置值为0 
	}
	return 0;
}

