/*
表达式的值 
*/
#include<bits/stdc++.h>
using namespace std;
int factor_value();//求一个因子的值
int term_value(); //求一个项的值 
int expression_value(); //求一个表达式的值 
int factor_value(){ //求一个因子的值 
	int result=0;
	char c=cin.peek();
	if(c=='('){
		cin.get();
		result=expression_value();
		cin.get();
	}
	else{
		while(isdigit(c)){
			result=10*result+c-'0';
			cin.get();
			c=cin.peek();
		}
	}
	return result;
}
int term_value(){//求一个项的值 
	int result=factor_value() ;//求第一个因子的值
	while(true) {
		char op=cin.peek();
		if(op=='*' || op=='/'){
			cin.get();
			int value=factor_value();
			if(op=='*') result*=value;
			else result/=value;
		}
		else break;
	}
    return result;	
}
int expression_value(){ //求一个表达式的值 
	int result=term_value();
	bool more =true;
	while(more){
		char op=cin.peek();
		if(op=='+' || op=='-'){
			cin.get();
			int value=term_value();
			if(op=='+') result+=value;
			else result-=value;
		}
		else more=false;
	}
	return result;
}
int main(){
	cout<<expression_value()<<endl;
	return 0;
}
