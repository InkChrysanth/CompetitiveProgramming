/*N皇后问题 
*/
#include<bits/stdc++.h>
using namespace std;
int N,Z;
int queenPos[1005] ;
void NQueen(int k){
	int i;
	if(k==N) { //在0~k-1行皇后已经摆好的情况下，摆第k行及其后的皇后 
	    Z++;
		for(i=0;i<N;i++) cout<<queenPos[i]+1<<" ";
		cout<<endl;
		return ;
	}
	for(i=0;i<N;i++){//尝试第k个皇后的位置 
		int j;
		for(j=0;j<k;j++){ //和已经摆好的k个皇后的位置比较，看是否冲突 
			if(queenPos[j]==i || abs(queenPos[j]-i)==abs(k-j)) break;
		}
		if(j==k) { //当前选的位置不冲突 
		   queenPos[k]=i; //将第k个皇后摆放在位置i 
		   NQueen(k+1);
	    }
	
	}
}
int main(){
	cin>>N;
	NQueen(0);
	cout<<Z;
	return 0;
	
}
