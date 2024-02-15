#include<bits/stdc++.h>
using namespace std;
#define MAX 10005
char s1[MAX],s2[MAX];
int MaxLen[MAX][MAX];
int main()
{
	cin>>s1>>s2;
	int i,j;
	int str1=strlen(s1),str2=strlen(s2);
	for(i=0;i<str1;i++) MaxLen[i][0]=0;
	for(i=0;i<str2;i++) MaxLen[0][i]=0;
	for(i=1;i<=str1;i++)
	    for(j=1;j<=str2;j++){
	    	if(s1[i-1]==s2[j-1]) MaxLen[i][j]=MaxLen[i-1][j-1]+1;
	    	else  MaxLen[i][j]=max(MaxLen[i-1][j],MaxLen[i][j-1]);
		}
    cout<<	MaxLen[str1][str2]	<<endl;
    return 0;
}
