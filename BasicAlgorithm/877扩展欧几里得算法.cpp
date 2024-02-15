#include<bits/stdc++.h>
using namespace std;
int Edgcd(int a,int b,int &x,int &y){ //返回gcd(a,b)并求出解 
	if (!b)
    {
        x = 1, y = 0;
        return a;
    }
    int d = Edgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
int main(){
	int n;
	cin>>n;
	while(n--){
		int a,b,x,y;
		cin>a>>b;
		Edgcd(a,b,x,y);
		cout<<x<<" "<<y<<endl;
	}
	return 0;
}
