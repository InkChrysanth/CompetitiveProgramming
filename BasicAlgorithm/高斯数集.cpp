#include<bits/stdc++.h>
using namespace std;
const int N=100001;
long long q[N];
int tail=1;
int a,n;
int main(){
	cin>>a>>n;
	q[1]=a;
	long long t1,t2,t;
	int pa=1,pb=1;
	while(tail<n){
		t1=q[pa]*2+1;
		t2=q[pb]*3+1;
		t=min(t1,t2);
		if(t!=q[tail]) q[++tail]=t;
		if(t1<t2) pa++;
		else pb++;
	}
	cout<<q[n]<<endl;
}



