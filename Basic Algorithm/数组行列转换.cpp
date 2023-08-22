#include<bits/stdc++.h>
using namespace std;
const int maxn=100;
vector<vector<int> >a;
int main(){
	int i,j,M,k,x,y,z;
	cin>>M>>k;//k为元素个数，M为列的个数 
	a.resize(M+1); //初始分配空间 
	for(vector<vector<int> >::iterator it=a.begin();it!=a.end();++it) (*it).resize(k/M+1);
	//初始分配每一个一维数组的空间 
	for(i=1;i<=k;i++){
			cin>>x>>y>>z;
			a[y][++a[y][0]]=z; //a[y][0]保存的是y列的元素个数 
		}
	for(i=1;i<=M;i++){
		for(j=1;j<=a[i][0];j++)
		cout<<a[i][j]<<" ";
	}
	return 0;
}
