#include<bits/stdc++.h> 
using namespace std;
int main(){
	int nums[]={10,20,30,30,20, 10, 10,20}; 
	sort(nums,nums+8);
	int pos=lower_bound(nums,nums+8,20)-nums;
	cout<<"20 pos:"<<pos<<endl;
	pos=lower_bound(nums,nums+8,15)-nums;
	cout<<"15 pos:"<<pos<<endl;
	return 0;
}
