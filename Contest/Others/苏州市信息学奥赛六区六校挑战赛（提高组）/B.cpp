//ODT(100pts) 类似https://www.luogu.com.cn/problem/P2824
#include<bits/stdc++.h>
using namespace std;
const int N=5e4+5;
typedef long long ll;
const int mod=998244353;
int n,m,k;
int a[N];
int cnt[10];
ll pw[N],dv;
struct node{
	int l,r;
	mutable int v;
	node(int l,int r=0,int v=0):l(l),r(r),v(v) {}
	bool operator<(const node&a) const{
		return l<a.l;
	}
};
set<node> odt;
inline set<node>::iterator split(int p){
	set<node>::iterator it=odt.lower_bound(node(p));
	if(it!=odt.end()&&it->l==p) return it;
	it--;
	if(it->r<p) return odt.end();
	int l=it->l,r=it->r,v=it->v;
	odt.erase(it);
	odt.insert(node(l,p-1,v));
	return odt.insert(node(p,r,v)).first;
}
inline void ch(int l,int y){
	set<node>::iterator nr=split(l+1),nl=split(l);
	nl->v=y;
}
inline void cover(int l,int r,int v){
	set<node>::iterator nr=split(r+1),nl=split(l);
	odt.erase(nl,nr);
	odt.insert(node(l,r,v));
}
inline void usort(int l,int r){
	set<node>::iterator nr=split(r+1),nl=split(l);
	memset(cnt,0,sizeof(cnt));
	for(set<node>::iterator it=nl;it!=nr;it++){
		cnt[it->v]+=it->r-it->l+1;
	}
	int cur=l;
	for(int i=0;i<k;i++){
		if(!cnt[i]) continue;
		cover(cur,cur+cnt[i]-1,i);
		cur+=cnt[i];
	}
}
inline void dsort(int l,int r){
	set<node>::iterator nr=split(r+1),nl=split(l);
	memset(cnt,0,sizeof(cnt));
	for(set<node>::iterator it=nl;it!=nr;it++){
		cnt[it->v]+=it->r-it->l+1;
	}
	int cur=l;
	for(int i=k-1;i>=0;i--){
		if(!cnt[i]) continue;
		cover(cur,cur+cnt[i]-1,i);
		cur+=cnt[i];
	}
}
inline ll qp(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
inline ll qu(int l,int r){
	set<node>::iterator nr=split(r+1),nl=split(l);
	ll res=0,cur=r-l+1;
	int len,v;
	for(set<node>::iterator it=nl;it!=nr;it++){
		len=it->r-it->l+1;v=it->v;
		cur-=len;
		if(len==1) res=(res+v*pw[cur]%mod)%mod;
		else res=(res+dv*(pw[len]-1)%mod*v%mod*pw[cur]%mod)%mod;
	}
	return res;
}
void print(){
	int len,v;
	printf("cur::");
	for(set<node>::iterator it=odt.begin();it!=odt.end();it++){
		len=it->r-it->l+1;v=it->v;
		for(int i=1;i<=len;i++) printf("%d ",v);
	}
	printf("\n");
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) scanf("%1d",&a[i]);
	int cur=a[1],st=1;
	for(int i=2;i<=n;i++){
		if(a[i]!=cur){
			odt.insert(node(st,i-1,cur));
			cur=a[i];st=i;
		}
	}
	odt.insert(node(st,n,cur));
	pw[0]=1;
	for(int i=1;i<=n;i++) pw[i]=pw[i-1]*k%mod;
	dv=qp(k-1,mod-2)%mod;
	int a,b,c,op;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&op,&a,&b);
		if(op==1) ch(a,b);
		else if(op==2) usort(a,b);
		else if(op==3) dsort(a,b);
		else printf("%lld\n",qu(a,b)%mod);
//		print();
	}
	return 0;
}
//Brute Force(30pts)
/*
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
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

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;
constexpr int mod=998244353;

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    string num;
    int n, m, k;
    cin>>n>>m>>k>>num;
    num=" "+num;
    auto query=[&](string s)
    {
        int res=0;
        each(x, s) res=(1ll*res*k%mod+x-'0')%mod;
        return res;
    };
    for(int i=1, opt, l, r; i<=m; i++)
    {
        cin>>opt>>l>>r;
        switch(opt)
        {
            case 1:
                num[l]=r+'0';
                break;
            case 2:
                stable_sort(num.begin()+l, num.begin()+r+1);
                break;
            case 3:
                stable_sort(num.begin()+l, num.begin()+r+1, greater<char>());
                break;
            case 4:
                cout<<query(num.substr(l, r-l+1))<<endl;
                break;
            default: break;
        }
    }
	return 0;
}
*/