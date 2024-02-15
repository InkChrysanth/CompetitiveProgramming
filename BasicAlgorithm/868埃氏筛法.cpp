#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
int prim[N],cnt;
bool st[N];
void get_primes(int n){
    for(int i=2;i<=n;i++)
    {
        if(!st[i]){
            cnt++;
            prim[cnt++]=i;
            for(int j=0;j<cnt;j++) st[prim[j]*i]=true;
        }
    }
}
int main(){
    int n;
    cin>>n;
    get_primes(n);
    cout<<cnt<<endl;
    return 0;
}
