
/*
5 5
1  2  3  4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
*/
#include<bits/stdc++.h>
using namespace std;
int dx[]={-1,0,1,0},dy[]={0,1,0,-1},a[105][105],m[105][105];
int r,c;
bool p(int i,int j) //判断越界函数 
{
    return (i>=1&&i<=r&&j>=1&&j<=c);
}
int s(int i,int j) //深搜 
{
    int k;
    if(m[i][j]>0)  return m[i][j];
    m[i][j]=1;
    for(k=0;k<4;k++)
           if(p(i+dx[k],j+dy[k]))
               if(a[i+dx[k]][j+dy[k]]<a[i][j])
               {
                  if(m[i][j]<s(i+dx[k],j+dy[k])+1)
                    m[i][j]=s(i+dx[k],j+dy[k])+1;        }
 
    return m[i][j];
}
int main()
{
    int i,j,Max=0;
    cin>>r>>c;
    for(i=1;i<=r;i++)
        for(j=1;j<=c;j++)
        cin>>a[i][j];
   for(i=1;i<=r;i++) //穷举打擂台 
    { 
	    for(j=1;j<=c;j++)
            if(Max<s(i,j)) Max=s(i,j);
	}
    cout<<Max<<endl;
    return 0;
 
}
