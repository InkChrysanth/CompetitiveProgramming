/*
5
25 3
105 30
20 50
10 17
100 10
shuchu 10
第一列为奶牛到达时间，第二列为奶牛吃草时间，输出这些奶牛等待的最短时间
等待过程中编号小的奶牛有优先权 
friend bool operator 这个函数是友元函数，返回的是bool值operator是用于运算符重载
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
struct cow{
	int start,over,z;
	 friend bool operator < ( const cow a, const cow b ){
		return  a.z>b.z; //实现结构体小根堆的排序 
	} 
}c[maxn];
priority_queue<cow>q; //结构体的优先队列 
int read(){ //快速读取 
	int s=0,f=1;char c=getchar();
	while(c<'0' || c>'9') if(c=='-') f=-1,c=getchar();
	while(c>='0' &&c<='9') s=s*10+c-'0',c=getchar();
	return s*f;
}
bool cmp(cow a,cow b){
	return a.start<b.start;
}
int ans=0;
int main(){
	int n=read();
	for(int i=1;i<=n;i++) c[i].start=read(),c[i].over=read(),c[i].z=i;
	sort(c+1,c+n+1,cmp); //按进入时间进行排序 
	q.push(c[1]);
	int ans=c[1].start;
	int cnt=2;
	int now=c[1].start+c[1].over;
	while(cnt<=n ||!q.empty()){
		if(q.empty()){
			q.push(c[cnt]);
			now=c[cnt].start+c[cnt].over;
			cnt++;
		}		
		while(c[cnt].start<=now &&cnt<=n ){
			q.push(c[cnt]);
			cnt++;
		}
		q.pop();
		cow f=q.top();		
		ans=max(ans,now-f.start);		
		now=f.start+f.over;
	}
	cout<<ans<<endl;;
	return 0;
}
