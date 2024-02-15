#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
struct area{
	int l,r;
	bool operator< (const area &w)const{
	return l<w.l;
	}
}Area[maxn];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		Area[i].l=x;
		Area[i].r=y;
	}
	sort(Area,Area+n);
	int g=1,st=Area[0].l,ed=Area[0].r;
	for(int i=1;i<n;i++){
		if(Area[i].l > ed){st = Area[i].l; ed = Area[i].r; g++;}
        //1.当新的左端点符合大于原右标准，则需要更新左右标准
        else if(Area[i].r > ed) ed = Area[i].r;
	}
	cout<<g<<endl;
	return 0;
}
