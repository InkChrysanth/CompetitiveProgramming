#include<bits/stdc++.h>
using namespace std;
int main(){
	double x;
	cin>>x;
	double l=-100,r=100;
	for(int i=0;i<=99;i++){
		double mid=(l+r)/2;
		if(mid*mid*mid>=x) r=mid;
		else l=mid;
	}
	printf("%lf\n",l);
	return 0;
}
