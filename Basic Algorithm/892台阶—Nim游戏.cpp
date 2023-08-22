#include<bits/stdc++.h> 
using namespace std;
int main()
{
	int n;
	int res=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		if(i&1) res^=x;
	}
	if(res) puts("Yes");
	else puts("No");
	return 0;
}
