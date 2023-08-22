#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
int heap[maxn],len=0,n,sum=0;
void put(int x){
	int p;
	len++;
	heap[len]=x;
	p=len;
	while(p!=1 && heap[p]<heap[p/2]){		
			swap(heap[p],heap[p*2]);
			p/=2;				    
	}
}
int get(){
	int p,q,x=heap[1];
	heap[1]=heap[len];
	len--;p=1;
	while(p*2<=len){
		if(p*2+1>len || heap[2*p]<heap[2*p+1])
		    q=p*2; //选左路 
		else 
		    q=p*2+1; //选右路 
		if(heap[p]>heap[q])	 {
			swap(heap[p],heap[q]);
			p=q;
		} 
		else 
		    return x;  
	}
	return x;
}
int main(){
	cin>>n;
	int x;
	for(int i=1;i<=n;i++){
		cin>>x;put(x);
	}
	for(int i=1;i<=n-1;i++){
		int a=get();
		int b=get();
		sum=sum+a+b;
		put(a+b);
	}
	cout<<sum<<endl;
	return 0;
}
