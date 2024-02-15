/*
multimap 的应用 
*/
#include<bits/stdc++.h>
using namespace std;
struct StudentInfo{
	int id;
	char name[20];
};
struct Student{
	int score;
	StudentInfo info;
};
typedef multimap<int ,StudentInfo>MAP_STD; //等价于
int main() {
	MAP_STD mp;
	Student st;
	char cmd[20];
	while(cin>>cmd){
		if(cmd[0]=='A'){
			cin>>st.info.name>>st.info.id>>st.score;
			mp.insert(make_pair(st.score,st.info));
			//make_pair生成一个pair<int,studentInfo>变量
			//其first 等于st.score,second等于st.info 
		}
		else if(cmd[0]=='Q'){
			int score;
			cin>>score;
			MAP_STD::iterator p=mp.lower_bound(score);
			if(p!=mp.begin()){
				--p;
				score=p->first;
				MAP_STD::iterator maxp=p;
				int maxId=p->second.id;
				for(;p!=mp.begin() && p->first==score;--p){
					if(p->second.id>maxId){
						maxp=p;
						maxId=p->second.id;
					}
				}
				if(p->first==score){
					if(p->second.id>maxId){
						maxp=p;
						maxId=p->second.id;
					}
				}
				cout<<maxp->second.name<<" "
				    <<maxp->second.id<<" "
				    <<maxp->first<<endl;
			}
			else cout<<"Nobody"<<endl;
		}
	}
	return 0;
}
