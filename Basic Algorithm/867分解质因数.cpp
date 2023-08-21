#include<bits/stdc++.h> 
using namespace std;
void fenjie(int x) {
	for(int i=2;i<=x/i;i++){
		if(x%i==0){
			int t=0;
			while(x%i==0){
				x/=i;
				t++;
			}
			printf("%d %d\n",i,t);
		}
	}
	if(x>1) printf("%d 1\n",x);
}
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int a;
		scanf("%d",&a);
		fenjie(a);
		printf("\n");
	}
	return 0;
}
