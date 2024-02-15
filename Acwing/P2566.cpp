#include <bits/stdc++.h>
using namespace std;
#define FOR(x,y,z,f)\
	for(int x=1;x<=m;++x)\
		for(int y=1;y<=n;++y)\
			for(int z=1;z<=f[x][y];++z)
const char* graph[]={
	"    +-------+",
	"   /5\\7777\'/|",
	"  /55.*\'88/9|",
	" /.6666\\8/9/|",
	"+-------+9.0|",
	"|\\44444/|\\:0|",
	"|1\\444/3|b*0|",
	"|11\\4/33|b:\\|",
	"|111X333|b\'a+",
	"|11/2\\33|/a/ ",
	"|1/222\\3|a/  ",
	"|/22222\\|/   ",
	"+-------+    "
};
enum{RED=1,GREEN=2,BLUE=4};
const char* colors="KRGYBPCW";
typedef int cube[12];
cube v[102][102][102];
int h[102][102];
int g[102][102];
char f(cube& a,int x,int y){
	int u=graph[x][y];
	return u<48||u>57&&u<97||u>98?u:colors[a[u-48-(u>'9')*39]];
}
char s[1201][1202];
int n,m;
void cover(cube& a,int x,int y){
	for(int i=0;i!=12;++i)
		while(a[i]>>3)
			a[i]=a[i]&7|a[i]>>3;
	for(int i=0;i!=13;++i)
		for(int j=0;j!=13;++j)
			if(f(a,12-i,j)!=' ')
				s[x+i][y+j]=f(a,12-i,j);
}
void lag()
{
    int a[1919][810]={114514};
    int l=114514;
    for(int i=0; i<17777; i++)
        for(int j=0; j<17777; j++)
            l*=l;
}
void print(){
	memset(s,' ',sizeof s);
	FOR(x,y,z,h)
		cover(v[x][y][z],(m-x)*4+(z-1)*8,(m-x)*4+(y-1)*8);
	for(int i=sizeof s/sizeof *s-1;~i;--i)
		for(int j=sizeof *s-1;j&&s[i][j]==' ';--j)
			if(s[i][j-1]!=' '){
				s[i][j]=0;
				puts(s[i]);
			}
}
#define shade(x,y,z,i) v[x][y][z][i]|=u
int main(){
	scanf("%d%d",&m,&n);
	for(int x=1;x<=m;++x)
		for(int y=1;y<=n;++y)
			scanf("%d",h[x]+y);
	char t[10];
	for(int i=0;i!=3;++i)
		scanf("%s",t+i*3);
	for(int k=0;k!=9;++k){
		if(t[k]=='*')
			continue;
		int u=(t[k]=='R'?RED:t[k]=='G'?GREEN:BLUE)<<k*3;
		if(k==0){
			memcpy(g,h,sizeof g);
			for(int x=2;x<=m;++x)
				for(int y=2;y<=n;++y)
					g[x][y]=max(g[x][y],g[x-1][y-1]-1);
			FOR(x,y,z,g){
				shade(x,y,z-1,5);
				shade(x,y,z-1,6);
				shade(x,y,z-1,7);
				shade(x,y,z-1,8);
				shade(x+1,y+1,z-1,5);
				shade(x+1,y+1,z-1,6);
				shade(x+1,y+1,z-1,7);
				shade(x+1,y+1,z-1,8);
				shade(x,y+1,z-1,5);
				shade(x,y+1,z-1,6);
				shade(x+1,y,z-1,7);
				shade(x+1,y,z-1,8);
			}
			FOR(x,y,z,h)
				for(int i=5;i<=8;++i)
					v[x][y][z][i]^=u;
		}
		if(k==1){
			memcpy(g,h,sizeof g);
			for(int x=2;x<=m;++x)
				for(int y=1;y<=n;++y)
					g[x][y]=max(g[x][y],g[x-1][y]-1);
			FOR(x,y,z,g){
				shade(x,y,z-1,5);
				shade(x,y,z-1,6);
				shade(x,y,z-1,7);
				shade(x,y,z-1,8);
				shade(x+1,y,z-1,5);
				shade(x+1,y,z-1,6);
				shade(x+1,y,z-1,7);
				shade(x+1,y,z-1,8);
			}
			FOR(x,y,z,h)
				for(int i=5;i<=8;++i)
					v[x][y][z][i]^=u;
		}
		if(k==2){
			memcpy(g,h,sizeof g);
			for(int x=2;x<=m;++x)
				for(int y=n-1;y;--y)
					g[x][y]=max(g[x][y],g[x-1][y+1]-1);
			FOR(x,y,z,g){
				shade(x+1,y-1,z,0);
				shade(x+1,y-1,z,10);
				shade(x,y-1,z,9);
				shade(x,y-1,z,0);
				shade(x,y-1,z,10);
				shade(x,y-1,z,11);
				shade(x,y,z-1,5);
				shade(x,y,z-1,6);
				shade(x,y,z-1,7);
				shade(x,y,z-1,8);
				shade(x+1,y-1,z-1,5);
				shade(x+1,y-1,z-1,6);
				shade(x+1,y-1,z-1,7);
				shade(x+1,y-1,z-1,8);
				shade(x+1,y-1,z-1,9);
				shade(x+1,y-1,z-1,0);
				shade(x+1,y-1,z-1,10);
				shade(x+1,y-1,z-1,11);
				shade(x+1,y,z-1,5);
				shade(x+1,y,z-1,7);
				shade(x,y-1,z-1,6);
				shade(x,y-1,z-1,8);
				shade(x,y-1,z-1,9);
				shade(x,y-1,z-1,0);
				shade(x,y-1,z-1,10);
				shade(x,y-1,z-1,11);
			}
			FOR(x,y,z,h){
				for(int i=5;i!=12;++i)
					v[x][y][z][i]^=u;
				v[x][y][z][0]^=u;
			}
		}
		if(k==3){
			memcpy(g,h,sizeof g);
			for(int x=1;x<=m;++x)
				for(int y=2;y<=n;++y)
					g[x][y]=max(g[x][y],g[x][y-1]-1);
			FOR(x,y,z,g){
				shade(x,y,z-1,5);
				shade(x,y,z-1,6);
				shade(x,y,z-1,7);
				shade(x,y,z-1,8);
				shade(x,y+1,z-1,5);
				shade(x,y+1,z-1,6);
				shade(x,y+1,z-1,7);
				shade(x,y+1,z-1,8);
			}
			FOR(x,y,z,h)
				for(int i=5;i<=8;++i)
					v[x][y][z][i]^=u;
		}
		if(k==4){
			for(int x=1;x<=m;++x)
				for(int y=1;y<=n;++y)
					for(int i=5;i<=8;++i)
						shade(x,y,h[x][y],i);
		}
		if(k==5){
			memcpy(g,h,sizeof g);
			for(int x=1;x<=m;++x)
				for(int y=n-1;y;--y)
					g[x][y]=max(g[x][y],g[x][y+1]-1);
			FOR(x,y,z,g){
				shade(x,y-1,z,9);
				shade(x,y-1,z,0);
				shade(x,y-1,z,10);
				shade(x,y-1,z,11);
				shade(x,y,z-1,5);
				shade(x,y,z-1,6);
				shade(x,y,z-1,7);
				shade(x,y,z-1,8);
				shade(x,y-1,z-1,5);
				shade(x,y-1,z-1,6);
				shade(x,y-1,z-1,7);
				shade(x,y-1,z-1,8);
				shade(x,y-1,z-1,9);
				shade(x,y-1,z-1,0);
				shade(x,y-1,z-1,10);
				shade(x,y-1,z-1,11);
			}
			FOR(x,y,z,h){
				for(int i=5;i!=12;++i)
					v[x][y][z][i]^=u;
				v[x][y][z][0]^=u;
			}
		}
		if(k==6){
			memcpy(g,h,sizeof g);
			for(int x=m-1;x;--x)
				for(int y=2;y<=n;++y)
					g[x][y]=max(g[x][y],g[x+1][y-1]-1);
			FOR(x,y,z,g){
				shade(x-1,y+1,z,1);
				shade(x-1,y+1,z,2);
				shade(x-1,y,z,1);
				shade(x-1,y,z,2);
				shade(x-1,y,z,3);
				shade(x-1,y,z,4);
				shade(x,y,z-1,5);
				shade(x,y,z-1,6);
				shade(x,y,z-1,7);
				shade(x,y,z-1,8);
				shade(x-1,y+1,z-1,1);
				shade(x-1,y+1,z-1,2);
				shade(x-1,y+1,z-1,3);
				shade(x-1,y+1,z-1,4);
				shade(x-1,y+1,z-1,5);
				shade(x-1,y+1,z-1,6);
				shade(x-1,y+1,z-1,7);
				shade(x-1,y+1,z-1,8);
				shade(x-1,y,z-1,1);
				shade(x-1,y,z-1,2);
				shade(x-1,y,z-1,3);
				shade(x-1,y,z-1,4);
				shade(x-1,y,z-1,6);
				shade(x-1,y,z-1,8);
				shade(x,y+1,z-1,5);
				shade(x,y+1,z-1,7);
			}
			FOR(x,y,z,h)
				for(int i=1;i<=8;++i)
					v[x][y][z][i]^=u;
		}
		if(k==7){
			memcpy(g,h,sizeof g);
			for(int x=m-1;x;--x)
				for(int y=n;y;--y)
					g[x][y]=max(g[x][y],g[x+1][y]-1);
			FOR(x,y,z,g){
				shade(x-1,y,z,1);
				shade(x-1,y,z,2);
				shade(x-1,y,z,3);
				shade(x-1,y,z,4);
				shade(x,y,z-1,5);
				shade(x,y,z-1,6);
				shade(x,y,z-1,7);
				shade(x,y,z-1,8);
				shade(x-1,y,z-1,1);
				shade(x-1,y,z-1,2);
				shade(x-1,y,z-1,3);
				shade(x-1,y,z-1,4);
				shade(x-1,y,z-1,5);
				shade(x-1,y,z-1,6);
				shade(x-1,y,z-1,7);
				shade(x-1,y,z-1,8);
			}
			FOR(x,y,z,h)
				for(int i=1;i<=8;++i)
					v[x][y][z][i]^=u;
		}
		if(k==8){
			memcpy(g,h,sizeof g);
			for(int x=m-1;x;--x)
				for(int y=n-1;y;--y)
					g[x][y]=max(g[x][y],g[x+1][y+1]-1);
			FOR(x,y,z,g){
				shade(x-1,y-1,z,2);
				shade(x-1,y-1,z,3);
				shade(x-1,y-1,z,10);
				shade(x-1,y-1,z,11);
				shade(x-1,y,z,1);
				shade(x-1,y,z,2);
				shade(x-1,y,z,3);
				shade(x-1,y,z,4);
				shade(x,y-1,z,9);
				shade(x,y-1,z,0);
				shade(x,y-1,z,10);
				shade(x,y-1,z,11);
				shade(x,y,z-1,5);
				shade(x,y,z-1,6);
				shade(x,y,z-1,7);
				shade(x,y,z-1,8);
				shade(x-1,y-1,z-1,1);
				shade(x-1,y-1,z-1,2);
				shade(x-1,y-1,z-1,3);
				shade(x-1,y-1,z-1,4);
				shade(x-1,y-1,z-1,5);
				shade(x-1,y-1,z-1,6);
				shade(x-1,y-1,z-1,7);
				shade(x-1,y-1,z-1,8);
				shade(x-1,y-1,z-1,9);
				shade(x-1,y-1,z-1,0);
				shade(x-1,y-1,z-1,10);
				shade(x-1,y-1,z-1,11);
				shade(x-1,y,z-1,1);
				shade(x-1,y,z-1,2);
				shade(x-1,y,z-1,3);
				shade(x-1,y,z-1,4);
				shade(x-1,y,z-1,5);
				shade(x-1,y,z-1,6);
				shade(x,y-1,z-1,7);
				shade(x,y-1,z-1,8);
				shade(x,y-1,z-1,9);
				shade(x,y-1,z-1,0);
				shade(x,y-1,z-1,10);
				shade(x,y-1,z-1,11);
			}
			FOR(x,y,z,h)
				for(int i=0;i!=12;++i)
					v[x][y][z][i]^=u;
		}
	}
	lag();
	print();
}
