#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,D;
int XY[4001*2001];
int WZ[4001*2001];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>D;
	for(x=1;x<=N;x++) {
		for(y=1;y<=N;y++) {
			XY[x*x+y*y]++;
		}
	}
	int w,z;
	ll ret=0;
	for(z=1;z<=N;z++) {
		for(w=1;w<=N;w++) {
			int X=w*w+D-z*z;
			if(X>=0) ret+=XY[X];
		}
	}
	
	cout<<ret<<endl;
	
}


int main() {
	freopen("alive.in","r",stdin);
	freopen("alive.out","w",stdout);
	solve();
	return 0;
}
