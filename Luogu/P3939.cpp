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

const int N=300010;
int n, m;
int a[N];
vector<int> color[N];
signed main()
{
	n=int_rd, m=int_rd;
    for(int i=1; i<=n; i++)
    {
        a[i]=int_rd;
        color[a[i]].emplace_back(i);
    }
    while(m--)
    {
        int op=int_rd;
        if(op==1)
        {
            int l=int_rd, r=int_rd, c=int_rd;
            cout<<upper_bound(color[c].begin(), color[c].end(), r)-
                lower_bound(color[c].begin(), color[c].end(), l)<<endl;
        }
        else
        {
            int k=int_rd;
            (*lower_bound(color[a[k]].begin(), color[a[k]].end(), k))++;
            (*lower_bound(color[a[k+1]].begin(), color[a[k+1]].end(), k+1))--;
            swap(a[k], a[k+1]);
        }
    }
	return 0;
}