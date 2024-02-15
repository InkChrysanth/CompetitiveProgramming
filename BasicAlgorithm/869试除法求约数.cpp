#include<bits/stdc++.h> 
using namespace std;
const int N=105;
int n;
vector<int> fen(int n){
	vector<int> res;
	for(int i=1;i<=n/i;i++){
		if(n%i==0){
			res.push_back(i);
			if(i!=n/i) res.push_back(n/i);
		}
	}
	sort(res.begin(),res.end());
	return res;
}
int main(){
	scanf("%d",&n);
	while(n--){
		int a;
		scanf("%d",&a);
		vector<int> k=fen(a);
		int z=k.size();
		for(int i=0;i<z;i++) printf("%d ",k[i]);
		printf("\n");
	}
	return 0;
}
