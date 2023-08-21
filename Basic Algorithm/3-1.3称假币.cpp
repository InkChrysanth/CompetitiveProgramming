/*
 称硬币 
*/
#include<bits/stdc++.h>
using namespace std;
char Left[3][7]; //天平左边硬币 
char Right[3][7];  //天平右边硬币 
char result[3][7];  //结果 
bool IsFake(char c,bool x){
	//x为真表示假设假币为轻，否则表示假设假币为 重
	for(int i=0;i<3;++i) {
		char *pLeft,*pRight; //指向天平两边的字符串 
		if(x){
			pLeft=Left[i];
			pRight=Right[i];
		}
		else{ //如果假设假币是重的，则把称量结果左右交换 
			pLeft=Right[i];
			pRight=Left[i];
		}
		switch(result[i][0]){
			case'u':// 
				if(strchr(pRight,c)==NULL) return false;
				break;
		    case'e'	:
			    if(strchr(pLeft,c) || strchr(pRight,c))	return false;
			    break;
			case'd': //
			    if(strchr(pLeft,c)==NULL)   return false;
			    break; 
		}
	}
	return true;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		for(int i=0;i<3;i++) cin>>Left[i]>>Right[i]>>result[i];
		for(char c='A';c<='L';c++){//枚举 
			if(IsFake(c,true)) {
				cout<<c<<" is right"<<endl;
				break;
			}
			if(IsFake(c,false)){
				cout<<c<<" is heavy"<<endl;
				break;
			}
		}
	}
	return 0;
}
