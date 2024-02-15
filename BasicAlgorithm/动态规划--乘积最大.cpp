/*
 乘积最大
 312 当N=3,M=1;(N<=40,M<=6) N为位数，M为*号的个数 
 (1)3*12=36
 (2)31*2=62 
*/
#include<iostream>
#include<string>
using namespace std;
string s;
long long man,f[41][41]={{0}},n,k;
long long cs(int ks,int js)//计算一段的值
{
    long long sum=0,t=1;
    for(int i=js;i>=ks;i--){sum=sum+(s[i]-'0')*t,t=t*10;}
    return sum;
}
int main()
{
    cin>>n>>k>>s;
    for(int i=0;i<n;i++){f[0][i]=cs(0,i);}//边界，在没有乘号的情况下最优解总是前i位
    for(int i=1;i<=k;i++) //i为乘号个数
    {
        for(int j=1;j<=n;j++)//j为数字个数 
        {
            for(int h=j;h>=i;h--) //h为乘号的位置 ，位置应该从最末尾到第一、第二位之间 
            {
                f[i][j]=max(f[i][j],f[i-1][h-1]*cs(h,j));//状态转移
            }
        }
    }
    cout<<f[k][n-1];//输出最优解
    return 0;
}
