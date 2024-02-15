/*
10
R 7
D 1
L 3
IL 2 10
D 3
IL 2 7
L 8
R 9
IL 4 7
IR 2 2
*/ 
#include <iostream>

using namespace std;

const int N=100010;

int e[N],l[N],r[N],idx=0;

void insertL(int x)
{
    l[idx]=0;//新节点->pre=head
    r[idx]=r[0];//新节点->next=head->next
    r[0]=idx;//head->next=新节点
    l[r[idx]]=idx;//新节点->next->pre=新节点
    e[idx++]=x;//add x
}

void insertR(int x)
{
    r[idx]=1;//新节点->next=tail
    l[idx]=l[1];//新节点->pre=tail->pre
    r[l[idx]]=idx;//新节点->pre->next=新节点
    l[1]=idx;//tail->pre=新节点
    e[idx++]=x;//add x
}

void deleteK(int k)
{
    r[l[k]]=r[k];//k->pre->next=k->next
    l[r[k]]=l[k];//k->next->pre=k->pre
}

void insertKL(int k,int x)                                  
{
    l[idx]=l[k];//新节点->pre=k->pre
    r[idx]=k;//新节点->next=k
    r[l[idx]]=idx;//新节点->pre->next=新节点
    l[k]=idx;//k->pre=新节点
    e[idx++]=x;//add x
}

void insertKR(int k,int x)
{
    r[idx]=r[k];//新节点->next=k->next
    l[idx]=k;//新节点->pre=k
    l[r[idx]]=idx;//新节点->next->pre=新节点
    r[k]=idx;//k->next=新节点
    e[idx++]=x;//add x
}   

void init()
{
    r[0]=1;//head->next=tail 0为队列头 
    l[1]=0;//tail->pre=head  1为队列尾 
    idx=2;//add two nodes
}

int main()
{
    ios::sync_with_stdio(false);
    init();
    int m;
    cin>>m;

    while(m-->0)
    {

        string command;
        int k,x;
        cin>>command;
        if(command=="L")
        {
            cin>>x;
            insertL(x);
        }
        else if(command=="R")
        {
            cin>>x;
            insertR(x);
        }
        else if (command=="D")
        {
            cin>>k;
            deleteK(k+1);//因为初始化加了两个节点，所以第k个数的下标为k+2-1
        }
        else if (command=="IL")
        {
            cin>>k>>x;
            insertKL(k+1,x);
        }
        else if(command=="IR")
        {
            cin>>k>>x;
            insertKR(k+1,x);
        }

    }
    for(int i=r[0];i!=1;i=r[i]) cout<<e[i]<<' ';//从头开始,当i!=tail时输出
    cout<<endl;
    return 0;

}

