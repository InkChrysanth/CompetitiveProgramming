/*
set的应用 
set不能像数组那样用下标 
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	set<int>s;
	set<int>::iterator it;
	int x;
	pair<set<int>::iterator,bool>rst;//定义pair类型的变量
	for(int i=0;i<10;i++){
		cin>>x;
		rst=s.insert(x);//往set里插入数据
		if(rst.second==true) cout<<x<<" YES"<<endl;
		else cout<<x<<"NO"<<endl;
	} 
	for(it=s.begin();it!=s.end();it++) cout<<*it<<" ";
	cout<<endl;
	return 0;
}
