/*
vector支持比较 
vector<int>a(4,5),b(3,4);
	bool t;
	t=a<b;
	cout<< t;
	
 deque<int>pp;//双端队列  速度超慢 
    size()
	empty()
	clear()
	front()/back()
	push_front()/pop_back()
	begin()/end()
	
set/multiset 时间复杂度是0(logn) ;
   insert()
   find()
   count()
   earse()
   begin(),end() ++,--返回前驱和后继 
    (1)输入是一个数，删掉所有x;
	(2)输入一个迭代器，删除这个迭代器
	lower_bound(x) 返回大于等于x的最小的一个迭代器 
	upper_bound(x)		返回大于x的最小数的迭代器
	 
map/multimap	
    insert()  插入的数是一个pair 
    earse()   插入的参数是pair或者迭代器
	find() 
	[]时间复杂度是0(logn) ;
    lower_bound(x) 返回大于等于x的最小的一个迭代器 
	upper_bound(x)		返回大于x的最小数的迭代器
	
unordered_set,unordered_map,unordered_multimap,unordered_multiset,哈希表
    和上面类似，增删改查的时间复杂度是O(1);
	不支持lower_bound()/upper_bound();	
	
bitset,压位
	 bitset<10000> S; //长度为10000的S
	 ~,&,|,^,>>,<<,==,!= []
	 count() 返回有多少个1
	 any/none()
	 any()是否至少有一个1
	 none()判断是否全为0	 
	 set(),把所有位置成1
	 set(k,v)将第k位变成v
	 reset()把所有位变成0
	 flip()等价于~
	 flip(k)把第k位取反 
	  
*/
#include<bits/stdc++.h> 
using namespace std;
int main(){
	vector<int>a(4,5),b(3,4);
	bool t;
	t=a<b;
	cout<< t<<endl;
    pair<int ,pair<int,int> >c;
    string sa="yxc";
    sa+="def";
    sa+='c';
    string pq;
    pq=sa.substr(1,3);
    cout<<pq<<endl;
    cout<<sa<<endl;
 //   priority_queue<int,vector<int>,greatr<int> >heap;
    priority_queue<int,vector<int>,greater<int> >heap;
    deque<int>pp;//双端队列 
    set<int>S;
    multiset<int>MS;
    map<string,int>QQQQ;
    QQQQ["yxc"]=1;
    cout<<QQQQ["yxc"]<<endl;
    unordered_multimap<string, int> unQQ;
    
	return 0;
}
