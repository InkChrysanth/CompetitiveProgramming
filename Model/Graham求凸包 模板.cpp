#include <bits/stdc++.h>
using namespace std;
const int N=1010;
int n; 
struct Point
{
    int x, y;
}a[N];
int cross(Point A, Point B, Point C)
{
    //结果若>0 A->C在A->B的逆时针方向 <0则反之 =0时共线
    return (B.x-A.x)*(C.y-A.y)-(C.x-A.x)*(B.y-A.y);
}
bool cmp(Point A, Point B)
{
    int pp=cross(a[0], A, B);
    if(pp<0) return true;//OB在OA的逆时针方向 A<B
    if(pp>0) return false;//OB在OA的顺时针方向 A>B
    return A.x<B.x;//A、B共线时按x大小排序
}
int main()
{
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i].x>>a[i].y;
    for(int i=0; i<n; i++)
    {
        if(a[i].y<a[0].y) swap(a[0], a[i]);
        else if(a[i].y==a[0].y && a[i].x<a[0].x) swap(a[0], a[i]); 
    }
    sort(a+1, a+n, cmp);
    int tt=1;
    for(int i=2; i<n; i++)
    {
        while(tt>0 && cross(a[i], a[tt], a[tt-1])>=0) tt--;
        a[++tt]=a[i];
    }
    for(int i=0; i<=tt; i++)
        cout<<a[i].x<<' '<<a[i].y<<endl;
    return 0;
}