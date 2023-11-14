// Problem: 砖块摆放
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/65196/B
// Memory Limit: 524288 KB
// Time Limit: 2000 ms

#include <bits/stdc++.h>
#define int_rd (int)read()
#define ll_rd read()
#define endl '\n'
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

inline ll read()
{
	ll a=0; int f=0; char p=getchar();
	while(!isdigit(p)){f|=p=='-'; p=getchar();}
	while(isdigit(p)){a=(a<<3)+(a<<1)+(p^48); p=getchar();}
	return f?-a:a;
}

const int N=200010, p=3;

int qmi(int a, int k)
{
    int res=1;
    while(k)
    {
        if(k&1) res=(ll)res*a%p	;
        a=(ll)a*a%p;
        k>>=1;
    }
    return res;
}

ll C(ll a, ll b)
{
    if(a<b) return 0;
    ll res=1;
    for(int i=1, j=a; i<=b; i++, j--)
    {
        res=(ll)res*j%p;
        res=(ll)res*qmi(i, p-2)%p;
    }
    return res;
}

ll lucas(ll a, ll b)
{
    if(b==0) return 1;
    return (ll)C(a%p, b%p)*lucas(a/p, b/p)%p;
}

int get()
{
	char ch=getchar();
	if(ch=='A') return 0;
	if(ch=='B') return 1;
	if(ch=='C') return 2;
	return 0;
}

void print(int x)
{
	if(x==0) cout<<'A'<<endl;
	if(x==1) cout<<'B'<<endl;
	if(x==2) cout<<'C'<<endl;
}

int n;
int a[N];

void kumiko()
{
	n=int_rd;
	int ans=0;
	for(int i=0; i<n; i++)
		ans=(ans+lucas(n-1, i)*get())%p;
	ans=((n%2?1:-1)*ans+p)%p;
	print(ans);
}

signed main()
{
	cin.tie(0); cout.tie(0);
	int T=int_rd;
	while(T--) kumiko();
	return 0;
}