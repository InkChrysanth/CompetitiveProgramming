//Shirasu Azusa 2024.8
#include<bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define mp make_pair
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
template<typename T,typename U>
T ceil(T x, U y) {return (x>0?(x+y-1)/y:x/y);}
template<typename T,typename U>
T floor(T x, U y) {return (x>0?x/y:(x-y+1)/y);}
template<class T,class S>
bool chmax(T &a,const S b) {return (a<b?a=b,1:0);}
template<class T,class S>
bool chmin(T &a,const S b) {return (a>b?a=b,1:0);}
int popcnt(int x) {return __builtin_popcount(x);}
int popcnt(ll x) {return __builtin_popcountll(x);}
int topbit(int x) {return (x==0?-1:31-__builtin_clz(x));}
int topbit(ll x) {return (x==0?-1:63-__builtin_clzll(x));}
int lowbit(int x) {return (x==0?-1:__builtin_ctz(x));}
int lowbit(ll x) {return (x==0?-1:__builtin_ctzll(x));}

#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;
int read() {
  int x=0,w=1; char c=getchar(); 
  while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
  while(isdigit(c)) {x=x*10+(c-'0'); c=getchar();}
  return x*w;
}

const int N=2005,mod=998244353;
int f[N][N],n;
char s[N];

signed main() {
  freopen("aspect.in","r",stdin);
  freopen("aspect.out","w",stdout);
  scanf("%lld%s",&n,s+1);
  f[0][0]=1;
  rep(i,1,n) {
    if(s[i]=='0') {
      int sum=f[i-1][0];
      rep(j,1,i) {
        f[i][j]=(sum+f[i-1][j-1]*(j-1))%mod;
        sum=(sum+f[i-1][j])%mod;
      }
    } else {
      rep(j,0,i-1) f[i][j]=f[i-1][j]*(i-j)%mod;
    }
  }
  int ans=0;
  rep(i,0,n) ans=(ans+f[n][i])%mod;
  printf("%lld\n",ans);
  return 0;
}