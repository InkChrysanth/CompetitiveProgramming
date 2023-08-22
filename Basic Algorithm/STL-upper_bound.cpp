#include<bits/stdc++.h> 
using namespace std;
int main(){
	int nums[]={10,20,30,30,20, 10, 10,20}; 
	sort(nums,nums+8);
	int pos=upper_bound(nums,nums+8,20)-nums; //×ó±ÕÓÒ¿ª 
	cout<<"20 pos:"<<pos<<endl;
	pos=upper_bound(nums,nums+8,25)-nums;
	cout<<"25 pos:"<<pos<<endl;
	return 0;
}
