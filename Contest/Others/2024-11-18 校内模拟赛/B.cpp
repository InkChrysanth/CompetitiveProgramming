// 蓝的写
// 放个rft的代码
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define uint unsigned int 
#define DU double
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define rep(i,x,n) for(int i=(x);i<=(n);i++)
#define nep(i,x,n) for(int i=(x);i>=(n);i--)
using namespace std;
const int N=2e5+10;
ll n,k,a[N],s[N],ssl[N],ssr[N],ssl2[N],ssr2[N];
inline void getans(ll x,ll y,ll now){
	if(x>k) return ;
	if(y%4==1){
		ll l=y/4+1,r=min(l+k-x,n-l+1);
		s[l]+=x-1,s[r+1]-=x-1;
		ssl[l]++,ssl[r+1]--,ssl2[r+1]-=r-l+1;
	}
	if(y%4==2){
		ll l=x,r=min(k,x+now-1),pos=n-(y/4);
		a[pos]+=(l+r)*(r-l+1)/2;
	}
	if(y%4==3){
		ll r=n-y/4-1,l=max(r-(k-x),y/4+1);
		s[l]+=x-1,s[r+1]-=x-1;
		ssr[r]++,ssr[l-1]--,ssr2[l-1]-=r-l+1;
	}
	if(y%4==0){
		ll l=x,r=min(k,x+now-1),pos=y/4;
		a[pos]+=(l+r)*(r-l+1)/2;
	}
	getans(x+now,y+1,now-(y&1));
}
int main(){
	scanf("%lld%lld",&n,&k);
	getans(1,1,n);
	rep(i,1,n) s[i]+=s[i-1];

	rep(i,1,n) ssl[i]+=ssl[i-1];
	rep(i,1,n) ssl[i]=ssl[i]+ssl2[i];
	rep(i,1,n) ssl[i]+=ssl[i-1];

	nep(i,n,1) ssr[i]+=ssr[i+1];
	nep(i,n,1) ssr[i]=ssr[i]+ssr2[i];
	nep(i,n,1) ssr[i]+=ssr[i+1];

	rep(i,1,n) printf("%lld ",a[i]+s[i]+ssl[i]+ssr[i]);puts("");
	return 0;
}
// prefix sum