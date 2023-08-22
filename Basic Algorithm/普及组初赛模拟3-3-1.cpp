#include<bits/stdc++.h>
  #include<string>
  using namespace std;
  
  //ack function definition
  int ack(int m,int n)
  {
      if(m == 0)
      {
         return n+1;
     }
     else if(n == 0)     {
        return ack(m - 1, 1);
     }
     else
     {
         return ack(m - 1, ack(m, n - 1));
     }
 }
 
 int main()
 {
     cout<<"***********************************"<<endl;
     cout<<"下面矩阵中第i行第j列的值为ack(i,j)"<<endl;
     cout<<"i,j的取值从0开始,第一个为ack(0,0)"<<endl;
     cout<<"***********************************"<<endl;
     for(int i = 0;i <= 4;i++)
     {
         for(int j = 0;j <= 3;j++)
         {
             cout<<ack(i,j)<<"\t";
         }
         cout<<endl;
     }
     
     return 0;
 }
