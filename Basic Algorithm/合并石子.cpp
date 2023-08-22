#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int> >q;
int a[100005];
int main() {
	int n;
	int ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),q.push(a[i]);
	for(int i=1;i<n;i++)
	{
		int x=q.top();q.pop();
		int y=q.top();q.pop();
		ans=ans+x+y;
		q.push(x+y);
	}
	printf("%d\n",ans);
	return 0;
}
