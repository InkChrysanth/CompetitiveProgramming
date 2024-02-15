/*
5
1 10
2 4
3 6
5 8
4 7
输出 4 
friend bool operator 这个函数是友元函数，返回的是bool值operator是用于运算符重载
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
struct cow{
	int start,over;
	 friend bool operator < ( const cow a, const cow b ){
		return  a.over>b.over; //实现结构体小根堆的排序 
	}
}c[maxn];
priority_queue<cow>q; //结构体的优先队列 
int read(){ //快速读取 
	int s=0,f=1;char c=getchar();
	while(c<'0' || c>'9') if(c=='-') f=-1,c=getchar();
	while(c>='0' &&c<='9') s=(s<<3)+(s<<1)+c^48,c=getchar();
	return s*f;
}
bool cmp(cow a,cow b){
	return a.start<b.start;
}
int ans=0;
int main(){
	int n=read();
	for(int i=1;i<=n;i++) c[i].start=read(),c[i].over=read();
	sort(c+1,c+n+1,cmp); //按进入时间进行排序 
	int ans=1;
	q.push(c[1]);
	for(int i=2;i<=n;i++){
		cow x=q.top();
		if(c[i].start>x.over){ //可以放在一个牛棚 
			q.pop(); //原先的弹出 
			q.push(c[i]);//加入新的！
		}
		else{
			ans++; 
			q.push(c[i]);
		}		
	}
	cout<<ans;
	return 0;
}
