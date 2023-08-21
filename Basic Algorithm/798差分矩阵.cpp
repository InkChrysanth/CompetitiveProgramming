/*
输入样例：
3 4 3
1 2 2 1
3 2 2 1
1 1 1 1
1 1 2 2 1
1 3 2 3 2
3 1 3 4 1
输出样例：
2 3 4 1
4 3 4 1
2 2 2 2
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int a[N][N],b[N][N];
void insert(int x1,int y1,int x2,int y2,int c){
	b[x1][y1]+=c;
	b[x2+1][y1]-=c;
	b[x1][y2+1]-=c;
	b[x2+1][y2+1]+=c;
}
int main(){
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
	   for(int j=1;j<=m;j++)
	      scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
	   for(int j=1;j<=m;j++)      
	     insert(i,j,i,j,a[i][j]);
	while(q--)     {
		int x1,y1,x2,y2,c;
		scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&c);
		insert(x1,y1,x2,y2,c);
	}
	for(int i=1;i<=n;i++)
	   for(int j=1;j<=m;j++)
	      b[i][j]+=b[i-1][j]+b[i][j-1]-b[i-1][j-1];
	for(int i=1;i<=n;i++)      
	    for(int j=1;j<=m;j++)
	       if(j==m) printf("%d\n",b[i][j]);
	       else printf("%d ",b[i][j]);
	return 0;       
}
