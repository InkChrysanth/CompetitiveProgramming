int lowbit(int x) { return x&-x; }
cout<<(a&a-1);//判断是否是2^k
cout<<(a&-a);//lowbit 取末尾1
cout<<(a&~(1<<b));//把第b位变为0
cout<<(a|(1<<b));//把第b位变为1
cout<<((a>>b)&1);//判断第b位是否为1
cout<<(a^(1<<b));//把第b位取反
while(n)
{
    cout<<lowbit(n)<<" ";
    n-=lowbit(n);
}
