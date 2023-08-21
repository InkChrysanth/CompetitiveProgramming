#include<bits/stdc++.h>
using namespace std;
char oriLights[5]; //存放输入的原始的灯矩阵 
char lights[5];    //存放灯变化中的的矩阵 
char result[5];   //最终的开关结果 
int GetBit(char c,int i){ //取第i位的比特值0或1 
	return (c>>i) &1;
}
void SetBit(char &c,int i ,int v){//改变i位的状态到v 
	if(v){
		c|=(1<<i);
	}
	else 
	    c&=~(1<<i);
}
void FlipBit(char &c,int i) //灯状态的翻转
{
	c^=(1<<i);
 } 
void OutputResult(int t,char result[]){//输出开关矩阵 
	cout<<"PUZZLE #"<<t<<endl;
	for(int i=0;i<5;i++){
		for(int j=0;j<6;j++){
			cout<<GetBit(result[i],j);
			if(j<5) cout<<" ";			
		}
		cout<<endl;
	}
}
int main(){
	int T;
	cin>>T;
	for(int t=1;t<=T;t++){
		for(int i=0;i<5;i++)
		   for(int j=0;j<6;j++){
		   	int s;
		   	cin>>s;
		   	SetBit(oriLights[i],j,s);
		   }
	    for(int n=0;n<64;n++){ //穷举64种状态 
		   int switchs=n; //一行6盏灯有2^6个状态组合 
		    memcpy(lights,oriLights,sizeof(oriLights));
		    for(int i=0;i<5;i++){
		    	result[i]=switchs;
			    for(int j=0;j<6;j++){
				   if(GetBit(switchs,j)){
					   if(j>0) 
					        FlipBit(lights[i],j-1);
					    FlipBit(lights[i],j)  ;
					    if(j<5)    
					      FlipBit(lights[i],j+1);
				    }
			    }
			if(i<4) //更改上一行的灯的状态 
			      lights[i+1]^=switchs;
			switchs=lights[i] ;//下一行的状态    
		}
		if(lights[4]==0){ //最后一行都是灭的 
		    OutputResult( t, result);
			break;
		}
	}	   
	}
	return 0;
}
