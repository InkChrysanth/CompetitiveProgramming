#include <bits/stdc++.h>
using namespace std;
const int N=100010;
const double eps=1e-8;
struct Point
{
    double x, y;
}a[N];
double cross(Point A, Point B, Point C)
{
    //结果若>0 A->C在A->B的逆时针方向 <0则反之 =0时共线
    return (B.x-A.x)*(C.y-A.y)-(C.x-A.x)*(B.y-A.y);
}
bool cmp(Point A, Point B)
{
    double pp=cross(a[0], A, B);
    if(pp>0) return true;//OB在OA的逆时针方向 A<B
    if(pp<0) return false;//OB在OA的顺时针方向 A>B
    if(A.x!=B.x) return A.x<B.x;//A、B共线时按x大小排序
    if(A.y!=B.y) return A.y<B.y;
}
double f(Point A, Point B)
{
    return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}
int main()
{
    int n; cin>>n;
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
        while(tt>0 && cross(a[tt-1], a[tt], a[i])<=0) tt--;
        a[++tt]=a[i];
    }
    double ans=0;
    a[++tt]=a[0];
    for(int i=0; i<=tt-1; i++)
        ans+=f(a[i], a[i+1]);
    printf("%.2lf\n", round(ans*pow(10, 2))*pow(10, -2));
    return 0;
}
