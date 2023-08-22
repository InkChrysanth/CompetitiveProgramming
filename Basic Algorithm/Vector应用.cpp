/*
平面内有n个点(n<=100000),请按从左到右，从下到上的顺序输出
这些点。即先按横坐标排序，如果横坐标相等，则按纵坐标排序。
样例输入：
3
2.1 3
3 5
3 4
样例输出：
2.1 3
3 4
3 5 
*/
#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	double x,y;
//	node(int _x=0,int _y=0):x(_x),y(_y){} //构造函数，完成成员变量初始化 
	bool operator<(node const &a)const{
		if(x==a.x) return y<a.y;
		return x<a.x;
	}
};
bool comp(node &a,node &b){
	if(a.x==b.x) return a.y<b.y;
	else return a.x<b.x;
}
vector<node>a;
int main(){
	cin>>n;
	a.resize(n);
	for(int i=0;i<n;i++) cin>>a[i].x>>a[i].y;
	sort(a.begin(),a.end());
	for(int i=0;i<n;i++) cout<<a[i].x<<" "<<a[i].y<<endl;
	return 0;
}
