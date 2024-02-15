#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
int prim[N],cnt;
bool st[N];
void get_primes(int n){
    for(int i=2;i<=n;i++)
    {
        if(!st[i]) prim[cnt++]=i;
        for(int j=0;prim[j]<=n/i;j++) {
                st[prim[j]*i]=true;
                if(i%prim[j]==0) break; //i%prim[j]==0那么prim[j]一定是i的最小折因子
        } //n只会被它的最小折因子筛掉 当i=6,prim[j]=2时就不能j++,否则18被3这个素数筛掉，18同时被2筛掉，这样就出现重复筛 
        
    }
}
int main(){
    int n;
    cin>>n;
    get_primes(n);
    cout<<cnt<<endl;
    return 0;
}
