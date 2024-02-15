#include<bits/stdc++.h>
using namespace std;
struct Student{
	string name;
	int score;
};
Student student[5]={{"Ja",89},{"Ci",87},{"To",74},{"Al",87},{"Mi",98}};
typedef map<string,int> MP;
int main(){
	MP mp;
	for(int i=0;i<5;i++) mp.insert(make_pair(student[i].name,student[i].score));
	cout<<mp["Ja"]<<endl;
	mp["Ja"]=60;
	MP::iterator i;
	for(i=mp.begin();i!=mp.end();i++) cout<<"("<<i->first<<","<<i->second<<")";
	cout<<endl;
	Student st;
	st.name="Ja";
	st.score=99;
	pair<MP::iterator, bool>p=mp.insert(make_pair(st.name,st.score));//插入是否成功 
	if(p.second) 
	   cout<<"("<<p.first->first<<","<<p.first->second<<")inserted"<<endl;
	else//指针用-> 
	    cout<<"insertion failed"<<endl;
	mp["Harry"]=78;
	MP::iterator q=mp.find("Harry");
	cout<<"("<<q->first<<","<<q->second<<")"<<endl;
	return 0;

	
}
