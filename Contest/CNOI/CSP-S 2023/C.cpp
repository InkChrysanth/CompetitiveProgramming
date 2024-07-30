//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define cmin(i,j) (i)=min((i),(j))
#define cmax(i,j) (i)=max((i),(j))
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define Fi(s) freopen(s,"r",stdin)
#define Fo(s) freopen(s,"w",stdout)
#define Fre(s) Fi(s".in"),Fo(s".out")
#define all(x) x.begin(), x.end()
#define each(i,x) for(auto &i:(x))
#define fi first
#define se second
#define endl '\n'
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define eb emplace_back

using ll=long long;
using ld=long double;
using pii=pair<int, int>;
using pli=pair<ll, int>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;

ll calc(const ll size, const int align)
{
    if(size%align==0) return size;
    return (size/align+1)*align;
}

struct member
{
    int tid;
    ll delta;
};

struct structure
{
    ll size;
    int align;
    map<string, member> members;
}structures[110];
int tot=4;

map<string, int> structures_id;

void init()
{
    structures[0].size=structures[0].align=1, structures_id["byte"]=0;
    structures[1].size=structures[1].align=2, structures_id["short"]=1;
    structures[2].size=structures[2].align=4, structures_id["int"]=2;
    structures[3].size=structures[3].align=8, structures_id["long"]=3;
}

//Operation 1

void add_type()
{
    string s; int k;
    cin>>s>>k;
    structure &new_structure=structures[tot];
    structures_id[s]=tot++;
    string type, name;
    for(; k>=1; k--)
    {
        cin>>type>>name;
        int tid=structures_id[type];
        int align=structures[tid].align;
        ll size=structures[tid].size;
        new_structure.size=calc(new_structure.size, align);
        cmax(new_structure.align, align);
        new_structure.members[name]={tid, new_structure.size};
        new_structure.size+=size;
    }
    new_structure.size=calc(new_structure.size, new_structure.align);
    cout<<new_structure.size<<' '<<new_structure.align<<endl;
}

//Operation 2

struct variable
{
    int tid;
    ll begin_pos;
};
map<string, variable> variables;
ll cur_addr=0;

void add_variable()
{
    string t, n;
    cin>>t>>n;
    int tid=structures_id[t];
    cur_addr=calc(cur_addr, structures[tid].align);
    variables[n]={tid, cur_addr};
    cout<<cur_addr<<endl;
    cur_addr+=structures[tid].size;
}

//Operation 3

void access_variable()
{
    auto spilt=[](string s)
    {
        int pos;
        vector<string> res;
        while((pos=s.find('.'))!=-1)
            res.eb(s.substr(0, pos)), s=s.substr(pos+1, s.size()-pos-1);
        res.eb(s);
        return res;
    };
    string s;
    cin>>s;
    vector<string> foos=spilt(s);
    int tid=variables[*(foos.begin())].tid;
    ll addr=variables[*(foos.begin())].begin_pos;
    foos.erase(foos.begin());
    each(foo, foos)
    {
        member cur_member=structures[tid].members[foo];
        tid=cur_member.tid, addr+=cur_member.delta;
    }
    cout<<addr<<endl;
}

//Operation 4

void access_address()
{
    ll addr;
    cin>>addr;
    ll begin_pos=0;
    int tid=-1;
    string name;
    vector<string> res;
    each(t, variables)
    {
        ll pos=t.se.begin_pos;
        if(pos<=addr && pos>=begin_pos)
            begin_pos=pos, tid=t.se.tid, name=t.fi;
    }
    if(tid==-1 || addr-begin_pos>=structures[tid].size)
    {
        cout<<"ERR"<<endl;
        return;
    }
    string _name=name;
    while(structures[tid].members.size())
    {
        addr-=begin_pos, begin_pos=0;
        int _tid=-1;
        each(t, structures[tid].members)
        {
            ll pos=t.se.delta;
            if(pos<=addr && pos>=begin_pos)
                begin_pos=pos, _tid=t.se.tid, name=t.fi;
        }
        if(_tid==-1 || addr-begin_pos>=structures[_tid].size)
        {
            cout<<"ERR"<<endl;
            return;
        }
        res.eb(name); tid=_tid;
    }
    cout<<_name;
    each(s, res) cout<<'.'<<s;
    cout<<endl;
}

signed main()
{
	// cin.tie(0)->sync_with_stdio(0);
    init();
    int T;
    cin>>T;
    for(int opt; T>=1; T--)
    {
        cin>>opt;
        switch(opt)
        {
            case 1:
                add_type();
                break;
            case 2:
                add_variable();
                break;
            case 3:
                access_variable();
                break;
            case 4:
                access_address();
                break;
            default:
                break;
        }
    }
	return 0;
}
