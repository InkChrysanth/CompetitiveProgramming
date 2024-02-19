//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#include <bits/stdc++.h>
#define Fi(s) freopen(s,"r",stdin)
#define Fo(s) freopen(s,"w",stdout)
#define Fre(s) Fi(s".in"),Fo(s".out")
#define For(i,j,k) for(int i=(j),i##_=(k);i<=i##_;i++)
#define Rep(i,j,k) for(int i=(j),i##_=(k);i>=i##_;i--)
#define fi first
#define se second
#define rd read
#define endl '\n'
#define mp make_pair
#define eb emplace_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3fll;

// template <typename T>
// void read(T &x)
// {
// 	x=0; char ch=getchar(); ll f=1;
// 	while(!isdigit(ch))
// 	{
// 		if(ch=='-') f*=-1;
// 		ch=getchar();
// 	}
// 	while(isdigit(ch))
// 	{
// 		x=x*10+(ch^48);
// 		ch=getchar();
// 	}
// 	x*=f;
// }
// template <typename T, typename...Args>
// void read(T &first, Args &...args)
// {
// 	read(first);
// 	read(args...);
// }

namespace GenHelper
{
    unsigned z1,z2,z3,z4,b;
    unsigned rand_()
    {
    b=((z1<<6)^z1)>>13;
    z1=((z1&4294967294U)<<18)^b;
    b=((z2<<2)^z2)>>27;
    z2=((z2&4294967288U)<<2)^b;
    b=((z3<<13)^z3)>>21;
    z3=((z3&4294967280U)<<7)^b;
    b=((z4<<3)^z4)>>12;
    z4=((z4&4294967168U)<<13)^b;
    return (z1^z2^z3^z4);
    }
}
void srand(unsigned x)
{using namespace GenHelper;
z1=x; z2=(~x)^0x233333333U; z3=x^0x1234598766U; z4=(~x)+51;}
int read()
{
    using namespace GenHelper;
    int a=rand_()&32767;
    int b=rand_()&32767;
    return a*32768+b;
}

const int N=20000010;

int n, m, s;
ull ans=0;
array<pii, N> a;

signed main()
{
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>s;
    srand(s);
    For(i, 1, n) a[i]={rd(), i};
    sort(a.begin()+1, a.begin()+n+1, greater<pii>());
    while(m--)
    {
        int l=rd()%n+1, r=rd()%n+1;
        if(l>r) swap(l, r);
        int ptr=0; while(a.at(ptr).se>r || a.at(ptr).se<l) ptr++;
        ans+=a.at(ptr).fi;
    }
    cout<<ans<<endl;
	return 0;
}