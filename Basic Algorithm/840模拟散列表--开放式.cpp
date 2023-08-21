#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int p[N];
int PQ=100003;
void insert(int x){
	int k=(x%PQ+PQ)%PQ;
	while(p[k]) k++;
	if(k==N) k==0;
	p[k]=x;
}
bool  find(int x){
	int k=(x%PQ+PQ)%PQ;
	while(p[k]){
		if(p[k]==x) return true;
		k++;
		if(k==N) k==0;
	}
	return false;
}
int main(){
	cin.tie(0);

	int n;
	cin>>n;
	while(n--){
		char c[2];
	    int x;
		cin>>c>>x;
		if(c[0]=='I') insert(x);
		else{
			if(find(x)) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}
	return 0;
}
