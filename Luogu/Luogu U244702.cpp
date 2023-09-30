// Problem: U244702 define int long long
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/U244702
// Memory Limit:  MB
// Time Limit:  ms

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
vector<string> a;
vector<int> cnt;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s; getline(cin, s);
	while(s!="")
	{
		string t;
		int res=1;
		for(int i=0; i<s.size(); i++)
		{
			if(s[i]==' ') res++, a.push_back(t), t="";
			else t+=s[i];
		}
		a.push_back(t);
		cnt.push_back(res);
		getline(cin, s);
	}
	for(int i=0; i<a.size(); i++)
	{
		if(a[i]=="int" && a[i+1]=="main")
			a[i]="signed", i++;
		else if(a[i]=="int")
			a[i]="long long";
	}
	int el=0, ptr=0;
	for(int i=0; i<a.size(); i++)
	{
		cout<<a[i]<<' '; el++;
		if(el==cnt[ptr]) el=0, ptr++, cout<<endl;
	}
	return 0;
}