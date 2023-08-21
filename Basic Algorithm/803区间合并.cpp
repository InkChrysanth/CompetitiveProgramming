#include<bits/stdc++.h> 
using namespace std;
const int N=1e5+10;
typedef pair<int,int>pii;
vector<pii>segs;
const int minn=-2e9;
void merge(vector<pii> &segs){
	vector<pii>res;
	int st=minn,ed=minn;
	sort(segs.begin(),segs.end());
	
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		segs.push_back({l,r});	
	}
	merge(segs);
	cout<<segs.size()<<endl;
	return 0;
}


