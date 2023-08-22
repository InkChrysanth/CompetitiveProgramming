#include<bits/stdc++.h> 
using namespace std;
int main(){
	int nums[]={10,20,30,30,20, 10, 10,20}; 
	sort(nums,nums+8);
	bool ret=binary_search(nums,nums+8,20);
	cout<<"20 :"<<ret<<endl;
	ret=binary_search(nums,nums+3,30);
	cout<<"30:"<<ret<<endl;
	return 0;
}
