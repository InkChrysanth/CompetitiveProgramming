// Problem: P1972 [SDOI2009] HH的项链
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1972
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

#define cmin(i,j) (i)=min((i),(j))
#define cmax(i,j) (i)=max((i),(j))
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define Fi(s) freopen(s,"r",stdin)
#define Fo(s) freopen(s,"w",stdout)
#define Fre(s) Fi(s".in"),Fo(s".out")
#define all(x) x.begin(), x.end()
#define each(i,x) for(auto &i:(x))
#define fi first
#define se second
#define endl '\n'
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define eb emplace_back

using ll=long long;
using ld=long double;
using pii=pair<int, int>;
using pli=pair<ll, int>;
namespace fastio
{
    const int bufl=1<<20;
    const double base1[16]={1,1e-1,1e-2,1e-3,1e-4,1e-5,1e-6,1e-7,1e-8,1e-9,1e-10,1e-11,1e-12,1e-13,1e-14,1e-15};
    const double base2[16]={1,1e1,1e2,1e3,1e4,1e5,1e6,1e7,1e8,1e9,1e10,1e11,1e12,1e13,1e14,1e15};
    struct IN{
        FILE *IT;char ibuf[bufl],*is=ibuf,*it=ibuf;
        IN(){IT=stdin;}IN(char *a){IT=fopen(a,"r");}
        inline char getChar(){if(is==it){it=(is=ibuf)+fread(ibuf,1,bufl,IT);if(is==it)return EOF;}return *is++;}
        template<typename Temp>inline void getInt(Temp &a){a=0;int b=0,c=getChar();while(c<48||c>57)b^=(c==45),c=getChar();while(c>=48&&c<=57)a=(a<<1)+(a<<3)+c-48,c=getChar();if(b)a=-a;}
        template<typename Temp>inline void getDouble(Temp &a){a=0;int b=0,c=getChar(),d=0;__int128 e=0,f=0;while(c<48||c>57)b^=(c==45),c=getChar();while(c>=48&&c<=57)e=(e<<1)+(e<<3)+c-48,c=getChar();if(c==46){c=getChar();while(c>=48&&c<=57)d++,f=(f<<1)+(f<<3)+c-48,c=getChar();}a=e+base1[d]*f;if(b)a=-a;}
        IN& operator>>(char &a){a=getChar();return *this;}
        IN& operator>>(char *a){do{*a=getChar();}while(*a<=32);while(*a>32)*++a=getChar();*a=0;return *this;}
        IN& operator>>(string &a){char b=getChar();while(b<=32)b=getChar();while(b>32)a+=b,b=getChar();return *this;}
        IN& operator>>(int &a){getInt(a);return *this;}
        IN& operator>>(long long &a){getInt(a);return *this;}
        IN& operator>>(__int128 &a){getInt(a);return *this;}
        IN& operator>>(float &a){getDouble(a);return *this;}
        IN& operator>>(double &a){getDouble(a);return *this;}
        IN& operator>>(long double &a){getDouble(a);return *this;}
    };
    struct OUT{
        FILE *IT;char obuf[bufl],*os=obuf,*ot=obuf+bufl;int Eps;long double Acc;
        OUT(){IT=stdout,Eps=6,Acc=1e-6;}OUT(char *a){IT=fopen(a,"w"),Eps=6,Acc=1e-6;}
        inline void ChangEps(int x=6){Eps=x;}
        inline void flush(){fwrite(obuf,1,os-obuf,IT);os=obuf;}
        inline void putChar(int a){*os++=a;if(os==ot)flush();}
        template<typename Temp>inline void putInt(Temp a){if(a<0){putChar(45);a=-a;}if(a<10){putChar(a+48);return;}putInt(a/10);putChar(a%10+48);}
        template<typename Temp>inline void putLeading(Temp a,int b){if(!b)return;putLeading(a/10,b-1);putChar(a%10+48);}
        template<typename Temp>inline void putDouble(Temp a){if(a<0){putChar(45);a=-a;}__int128 b=a;putInt(b);a-=b;a*=base2[Eps];b=a+Acc;putChar(46);putLeading(b,Eps);}
        OUT& operator<<(char a){putChar(a);return *this;}
        OUT& operator<<(char *a){while(*a>32)putChar(*a++);return *this;}
        OUT& operator<<(string a){for(auto c:a)putChar(c);return *this;}
        OUT& operator<<(int a){putInt(a);return *this;}
        OUT& operator<<(long long a){putInt(a);return *this;}
        OUT& operator<<(__int128 a){putInt(a);return *this;}
        OUT& operator<<(float a){putDouble(a);return *this;}
        OUT& operator<<(double a){putDouble(a);return *this;}
        OUT& operator<<(long double a){putDouble(a);return *this;}
        ~OUT(){flush();}
    };
}
using fastio::IN;
using fastio::OUT;
IN fin;
OUT fout;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;
constexpr int N=1000010;

int n, q, T;
int a[N], pos[N], cnt[N];
int ans[N], res;
int pre[N], suf[N], flag[N];

struct Node
{
	int l, r, id;
	bool operator<(const Node &T)const
	{ return pos[l]==pos[T.l] ? r<T.r : pos[l]<pos[T.l]; }
}Q[N];

// void add(int k)
// {
	// if(!cnt[a[k]]) res++;
	// cnt[a[k]]++;
// }
// 
// void del(int k)
// {
	// cnt[a[k]]--;
	// if(!cnt[a[k]]) res--;
// }
// 
signed main()
{
	// cin.tie(0)->sync_with_stdio(0);
	fin>>n;
	T=sqrt(n);
	for(int i=1; i<=n; i++)
		fin>>a[i], pos[i]=(i-1)/T+1;
	fin>>q;
	for(int i=1; i<=q; i++)
		fin>>Q[i].l>>Q[i].r, Q[i].id=i;
	sort(Q+1, Q+q+1);
	for(int i=1; i<=n; i++) pre[i]=flag[a[i]], flag[a[i]]=i;
	memset(flag, 0x3f, sizeof flag);
	for(int i=n; i>=1; i--) suf[i]=flag[a[i]], flag[a[i]]=i;
	int l=1, r=0;
	for(int i=1; i<=q; i++)
	{
		int ql=Q[i].l, qr=Q[i].r;
		while(l<ql) res-=(suf[l++]>r); //del(l++);
		while(l>ql) res+=(suf[--l]>r); //add(--l);
		while(r<qr) res+=(pre[++r]<l); //add(++r);
		while(r>qr) res-=(pre[r--]<l); //del(r--);
		ans[Q[i].id]=res;
	}
	for(int i=1; i<=q; i++)
		fout<<ans[i]<<endl;
	return 0;
}
