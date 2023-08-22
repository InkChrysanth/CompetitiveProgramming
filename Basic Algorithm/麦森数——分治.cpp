/*
麦森数 
*/
#include<bits/stdc++.h>
using namespace std;
int P;
long long a[510];
int main()
{
    cin>>P;    
    cout<<int(P*log(2)+1)<<endl; // 第一问    
    long long tmp=pow(2,50);       // tmp=2^50    
    a[500]=1;
    int t50=P/50;                 // t50：能乘以2^50的次数 
	int t1=P-t50*50;              // t1： 剩下的，一个一个乘上去 
    for(int T=1;T<=t50;T++)
    {
        for(int i=500;i>=1;i--)
        {
            a[i]*=tmp;            // 每一位都乘上2^50
        }
        for(int i=500;i>=1;i--)
        {
            a[i-1]+=a[i]/10;
            a[i]%=10;             // 处理进位
        }
    }    
        for(int i=500;i>=1;i--)
        {
            a[i]*=pow(2,t1);              // 每一位都乘上2
        }
        for(int i=500;i>=1;i--)
        {
            a[i-1]+=a[i]/10;
            a[i]%=10;             // 处理进位
        }   
    a[500]--; //最后-1   
    for(int i=1;i<=500;i++)
    {
        cout<<a[i];
        if(i%50==0) cout<<endl;
    }
    return 0;
}
