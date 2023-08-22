/*
int Stack[N],a[N];
int top,n;
int main()
{
 int i,cur;
 cin>>n;
 for(i=1;i<=n;i++)
     cin>>a[i];
 top=0;
 cur=1;
 for(i=1;i<=n;i++)
 { 
   while(cur<=a[i])
   {
       top++;
       Stack[top]=cur;
       cur++;
     }
      if(Stack[top]==a[i])
      top--;
      else
      {
          cout<<"no"<<endl;
          return 0;
      }
   }
cout<<"yes"<<endl;
return 0;
}

*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
int a[maxn];
stack<int>Q;
int cur=1;
int main(){
	int n,i,j;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++)
	{
		while(cur<=a[i]){
			Q.push(cur++); //车子不能返回所以cur变量只增不减 
		}
		if(Q.top()==a[i]) {
			Q.pop() ;
		}
		else{
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}

