//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#include <bits/stdc++.h>
#include <bits/extc++.h>
#define int long long
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define Fi(s) freopen(s,"r",stdin)
#define Fo(s) freopen(s,"w",stdout)
#define Fre(s) Fi(s".in"),Fo(s".out")
#define all(x) x.begin(), x.end()
#define For(i,j,k) for(int i=(j),i##_=(k);i<=i##_;i++)
#define Rep(i,j,k) for(int i=(j),i##_=(k);i>=i##_;i--)
#define each(i,x) for(auto &i:(x))
#define fi first
#define se second
#define rd read
#define endl '\n'
#define mp make_pair
#define mtp make_tuple
#define pb push_back
#define eb emplace_back
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3fll;
const double eps=1e-10;

int dx[]={0, 0, 1, 0, -1, 1, 1, -1, -1};
int dy[]={0, 1, 0, -1, 0, 1, -1, 1, -1};

template <typename T>
void read(T &x)
{
	x=0; char ch=getchar(); ll f=1;
	while(!isdigit(ch))
	{
		if(ch=='-') f*=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=x*10+(ch^48);
		ch=getchar();
	}
	x*=f;
}
template <typename T, typename...Args>
void read(T &first, Args &...args)
{
	read(first);
	read(args...);
}
const int N=100010, M=20;

int n, m, k;
int h[N];
int nxta[N], nxtb[N];
int da[2][N][M], db[2][N][M];
int f[2][N][M];
set<pii> tr;

pii query(int p, int dist)
{
	int res1=0, res2=0;
	Rep(i, k, 0)
	{
		if(f[0][p][i] && res1+res2+da[0][p][i]+db[0][p][i]<=dist)
		{
			res1+=da[0][p][i];
			res2+=db[0][p][i];
			p=f[0][p][i];
			// debug(p);
		}
	}
	return mp(res1, res2);
}

signed main()
{
	cin.tie(0); cout.tie(0);
	rd(n);
	k=log(n)/log(2);
	// debug(k);
	For(i, 1, n) rd(h[i]);
	tr.insert(mp(llinf, 0)); tr.insert(mp(llinf+1, 0));
	tr.insert(mp(-llinf, 0)); tr.insert(mp(-llinf-1, 0));
	Rep(i, n, 1)// W->E
	{
		pii t(h[i], i);
		auto ptr=++(tr.lower_bound(t));
		vector<pii> v;
		For(j, 1, 4) v.eb(*(ptr--));
		int d1=inf, d2=inf, p1=0, p2=0;
		reverse(all(v));
		each(vt, v)
        {
        	int vh=vt.fi, vp=vt.se;
        	// debug(vp);
            int dt=abs(vh-h[i]);
            if(dt<d1)
            {
                d2=d1, d1=dt;
                p2=p1, p1=vp;
            }
            else if(dt<d2)
            {
                d2=dt, p2=vp;
            }
        }
        nxta[i]=p2, nxtb[i]=p1;
        // debug(p2); debug(p1);
		tr.insert(t);
	}
	For(j, 0, k) For(i, 1, n)
	{
		if(j==0) f[0][i][0]=nxta[i], f[1][i][0]=nxtb[i];//, debug(nxta[i]), debug(nxtb[i]);
		else
		{
			For(p, 0, 1)
			{
				if(j==1) f[p][i][1]=f[1-p][f[p][i][0]][0];//, debug(f[p][i][1]);
				else f[p][i][j]=f[p][f[p][i][j-1]][j-1];//, debug(f[p][i][j]);
			}
		}
	}
	For(j, 0, k) For(i, 1, n)
	{
		if(j==0)
		{
			da[0][i][j]=abs(h[i]-h[nxta[i]]), da[1][i][j]=0;
			db[1][i][j]=abs(h[i]-h[nxtb[i]]), db[0][i][j]=0;
		}
		else
		{
			For(p, 0, 1)
			{
				if(j==1)
				{
					da[p][i][j]=da[p][i][j-1]+da[1-p][f[p][i][j-1]][j-1];
					db[p][i][j]=db[p][i][j-1]+db[1-p][f[p][i][j-1]][j-1];
				}
				else
				{
					da[p][i][j]=da[p][i][j-1]+da[p][f[p][i][j-1]][j-1];
					db[p][i][j]=db[p][i][j-1]+db[p][f[p][i][j-1]][j-1];
				}
			}
		}
	}
	int lm, m;
	rd(lm, m);
	double minr=llinf;
	int maxh=-llinf, ans=0;
	For(i, 1, n)
	{
		auto t=query(i, lm);
		double r=t.se?1.0*t.fi/t.se:llinf;
		if(r<minr || (abs(r-minr)<=eps && h[i]>maxh))
			minr=r, maxh=h[i], ans=i;
	}
	cout<<ans<<endl;
	For(i, 1, m)
	{
		int p;
		rd(p, lm);
		auto t=query(p, lm);
		cout<<t.fi<<' '<<t.se<<endl;
	}
	return 0;
}