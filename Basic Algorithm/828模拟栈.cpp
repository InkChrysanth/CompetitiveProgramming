/*
10
push 5
query
push 6
pop
query
pop
empty
push 4
query
empty
*/ 
#include<iostream>
using namespace std;
const int N=100010;
int stack[N],top;
int main()
{
    int m;
    cin>>m;
    while(m--)
    {
        string opration;
        int x;
        cin>>opration;
        if(opration == "push")
        {
            cin>>x;
            stack[top++]=x;
        }
        else if(opration == "pop")
            --top;
        else  if(opration == "empty")
            if(top) printf("NO\n");
            else printf("YES\n");
        else
            cout<<stack[top-1]<<endl;
    }
    return 0;
}


