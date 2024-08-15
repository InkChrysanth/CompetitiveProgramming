#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N=70;
int n;
int len, sum;
int w[N];
bool st[N];

bool dfs(int u, int s, int start)
{
	if(u*len==sum) return true;
	if(s==len) return dfs(u+1, 0, 0);
	for(int i=start; i<n; i++)
	{
		if(st[i] || s+w[i]>len) continue;
		st[i]=true;
		if(dfs(u, s+w[i], i+1)) return true;
		st[i]=false;
		if(s==0) return false;
		if(s+w[i]==len) return false;
		int j=i;
		while(j<n && w[i]==w[j]) j++;
		i=j-1;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	while(cin>>n, n)
	{
		memset(st, false, sizeof st);
		sum=0;
		for(int i=0; i<n; i++) cin>>w[i], sum+=w[i];
		sort(w, w+n, greater<int>());
		len=0;
		while(++len)
			if(sum%len==0 && dfs(0, 0, 0))
			{
				cout<<len<<endl;
				break;
			}
	}
	return 0;
}