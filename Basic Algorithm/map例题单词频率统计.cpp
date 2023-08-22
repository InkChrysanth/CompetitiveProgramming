#include<bits/stdc++.h>
using namespace std;

struct Word{
	int times;
	string wd;
};
struct Rule{
	bool operator()(const Word &w1,const Word &w2)const{
		if(w1.times!=w2.times)
		    return w1.times>w2.times;
		else 
		    return w1.wd<w2.wd;
	}
};
typedef map<string,int>MP;
typedef set<Word,Rule> ST;
int main(){	
	string s;
	MP mp;
	ST st;
	while(cin>>s) ++mp[s];
	for(MP::iterator i=mp.begin();i!=mp.end();++i){
		cout<<i->first<<" "<<i->second<<endl;
	}
	for(MP::iterator i=mp.begin();i!=mp.end();++i){
		Word tmp;
		tmp.wd=i->first;
		tmp.times=i->second;
		st.insert(tmp);
	}
	for(ST::iterator i=st.begin();i!=st.end();++i)
	    cout<<i->wd<<" "<<i->times<<endl;
}
