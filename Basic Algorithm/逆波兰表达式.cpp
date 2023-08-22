/*
Äæ²¨À¼±í´ïÊ½ 
*/
#include<bits/stdc++.h>
using namespace std;
double exp(){
	char s[20];
	cin>>s;
	switch(s[0]){
		case '+':return exp()+exp();
		case '-':return exp()-exp();
		case '*':return exp()*exp();
		case '/':return exp()/exp();
		default :return atof(s);
		break;
	}
}
int main(){
	printf("%lf",exp());
	return 0;
}
