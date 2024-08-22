//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
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
#define endl "\n"
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define em emplace

using ll=long long;
using ull=unsigned long long;
using ld=long double;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;
constexpr int N=17, M=21;

int n, h, T;

bool inRange(int x, int l, int r)
{ return x>=l && x<=r; }

struct Vec3
{
    int x, y, z;
    Vec3(int x=0, int y=0, int z=0)
        :x(x), y(y), z(z){}
    Vec3 operator +(const Vec3 &T)const
    { return Vec3(x+T.x, y+T.y, z+T.z); }
    bool operator ==(const Vec3 &T)const
    { return x==T.x && y==T.y && z==T.z; }
    bool operator !=(const Vec3 &T)const
    { return x!=T.x || y!=T.y || z!=T.z; }
};

// 2D direction vectors for UDLR
vector<Vec3> _2D4 = vector<Vec3>{Vec3(-1, 0, 0), Vec3(1, 0, 0), Vec3(0, -1, 0), Vec3(0, 1, 0)};
// 2D direction vectors for UDLR-UL-UR-DL-DR
vector<Vec3> _2D8 = vector<Vec3>{Vec3(-1, 0, 0), Vec3(-1, -1, 0), Vec3(0, -1, 0), Vec3(1, -1, 0),
						Vec3(1, 0, 0), Vec3(1, 1, 0), Vec3(0, 1, 0), Vec3(-1, 1, 0)};
// 3D direction vectors for UDLRFB
vector<Vec3> _3D6 = vector<Vec3>{Vec3(1, 0, 0), Vec3(-1, 0, 0), Vec3(0, 1, 0), Vec3(0, -1, 0),
						Vec3(0, 0, 1), Vec3(0, 0, -1)};

struct IceHouse
{
    #define a(s) a[s.x][s.y][s.z]
    int x, y, len, wid;
    int height=0;
    short a[N][N][M];
    IceHouse(){ memset(a, 0, sizeof a); }
    bool check(Vec3 P)
    { return inRange(P.x, 0, n-1) && inRange(P.y, 0, n-1) && inRange(P.z, 0, h); }
    short query(Vec3 P)
    { return (!check(P) ? -1 : a(P)); }
    void assign(Vec3 P, short val){ a(P)=val; }
    void freeze(Vec3 P){ a(P)=min(4, a(P)+1); }
    #undef a(s)
}A;

int IceBlockCnt=0;

void IceBarrage(int R, int C, int D, int S)
{
    auto cur=Vec3(R, C, 0), dir=_2D8[D];
    int cnt=0;
    S++;
    while(S--)
    {
        if(!A.check(cur) || A.query(cur)==5) break;
        if(A.query(cur)!=4) cnt++;
        A.freeze(cur);
        cur=cur+dir;
    }
    cout<<"CIRNO FREEZED "<<cnt<<" BLOCK(S)"<<endl;
}

void MakeIceBlock()
{
    int cnt=0;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++)
        if(A.query(Vec3(i, j, 0))==4)
            A.assign(Vec3(i, j, 0), 0), cnt++;
    IceBlockCnt+=cnt;
    cout<<"CIRNO MADE "<<cnt<<" ICE BLOCK(S),NOW SHE HAS "<<IceBlockCnt<<" ICE BLOCK(S)"<<endl;
}

void PutIceBlock(int R, int C, int H)
{
    auto cur=Vec3(R, C, H);
    // cout<<" "<<cur.x<<" "<<cur.y<<" "<<cur.z<<endl;
    auto isAttached=[&](Vec3 x)
    {
        if(x.z==0) return true;
        each(dir, _3D6)
            if(A.query(x+dir)==5) return true;
        return false;
    };

    if(!IceBlockCnt){ cout<<"CIRNO HAS NO ICE_BLOCK"<<endl; return; }
    if(A.query(cur)==5 || !isAttached(cur)){ cout<<"BAKA CIRNO,CAN'T PUT HERE"<<endl; return; }
    IceBlockCnt--; A.assign(cur, 5);
    if(cur.x<A.x || cur.x>A.x+A.len-1 || cur.y<A.y || cur.y>A.y+A.wid-1) cout<<"CIRNO MISSED THE PLACE"<<endl;
    else if(inRange(cur.x, A.x+1, A.x+A.len-2) && inRange(cur.y, A.y+1, A.y+A.wid-2))
        cout<<"CIRNO PUT AN ICE_BLOCK INSIDE THE HOUSE"<<endl;
    else cout<<"CIRNO SUCCESSFULLY PUT AN ICE_BLOCK,NOW SHE HAS "<<IceBlockCnt<<" ICE_BLOCK(S)"<<endl;
}

void RemoveIceBlock(int R, int C, int H)
{
    auto cur=Vec3(R, C, H);
    if(A.query(cur)!=5){ cout<<"BAKA CIRNO,THERE IS NO ICE_BLOCK"<<endl; return; }
    int cnt=0/*The number of broken blocks*/;
    vector<Vec3> RemovedBlock;
    bool vis[N][N][M], flag/*isAttached*/;
    #define vis(s) vis[s.x][s.y][s.z]

    //This function is used to count the blocks that need to be removed
    function<void(Vec3)> dfs=[&](Vec3 u)
    {
        vis(u)=true;
        RemovedBlock.eb(u);
        if(u.z==0){ flag=true; return; }
        each(dir, _3D6)
        {
            auto v=u+dir;
            if(A.query(v)==5 && !vis(v))
                dfs(v);
        }
    };

    function<void(Vec3)> remove=[&](Vec3 x)
    {
        if(A.query(x)!=5) return;
        flag=false;
        memset(vis, false, sizeof vis);
        dfs(x);
        if(!flag)
        {
            cnt+=RemovedBlock.size();
            each(p, RemovedBlock)
                A.assign(p, 0);
        }
        RemovedBlock.clear();
    };
    #undef vis(s)

    A.assign(cur, 0);
    IceBlockCnt++;
    each(dir, _3D6) remove(cur+dir);
    if(cnt) cout<<"CIRNO REMOVED AN ICE_BLOCK,AND "<<cnt<<" BLOCK(S) ARE BROKEN"<<endl;
    else cout<<"CIRNO REMOVED AN ICE_BLOCK"<<endl;
}

struct Door
{
    int x, y, h, cost;
    bool st/*isPerfect*/;
    Door(int x=0, int y=0, int h=0, int cost=0, bool st=false)
        :x(x), y(y), h(h), cost(cost), st(st){}
    bool operator<(const Door &T)const
    {
        if(cost!=T.cost) return cost<T.cost;
        if(h!=T.h) return h>T.h;
        if(st!=T.st) return st>T.st;
        if(x!=T.x) return x<T.x;
        return y<T.y;
    }
};

void MakeRoof()
{
    int px1=A.x+A.len/2, py1=A.y+A.wid/2,
     px2=A.x+(A.len-1)/2, py2=A.y+(A.wid-1)/2;
    vector<Vec3> Surround, Roof;
    auto CheckWall=[&](Vec3 x)
    { return x.x==A.x || x.x==A.x+A.len-1 || x.y==A.y || x.y==A.y+A.wid-1; };
    auto CheckInside=[&](Vec3 x)
    { return inRange(x.x, A.x+1, A.x+A.len-2) && inRange(x.y, A.y+1, A.y+A.wid-2) && inRange(x.z, 0, A.height-1); };
    auto CheckOutside=[&](Vec3 x)
    { return !(inRange(x.x, A.x, A.x+A.len-1) && inRange(x.y, A.y, A.y+A.wid-1) && inRange(x.z, 0, A.height)); };
    auto CheckPillar=[&](Vec3 x)
    { return (x.x==A.x || x.x==A.x+A.len-1) && (x.y==A.y || x.y==A.y+A.wid-1);};
    auto isPerfect=[&](Vec3 x)
    { return x.x==px1 || x.y==py1 || x.x==px2 || x.y==py2; };

    bool vis[N][N][M], flag/*isAttached*/;
    #define vis(s) vis[s.x][s.y][s.z]
    //This function is used to count the blocks that need to be removed
    function<void(Vec3)> dfs=[&](Vec3 u)
    {
        vis(u)=true;
        if(u.z==0){ flag=true; return; }
        each(dir, _3D6)
        {
            auto v=u+dir;
            if(A.query(v)==5 && !vis(v))
                dfs(v);
        }
    };
    auto isFloat=[&](Vec3 x)
    {
        if(A.query(x)!=5) return false;
        flag=false;
        memset(vis, false, sizeof vis);
        dfs(x);
        return !flag;
    };
    #undef vis(s)

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            if(inRange(i, A.x, A.x+A.len-1) && inRange(j, A.y, A.y+A.wid-1)
                && (!inRange(i, A.x+1, A.x+A.len-2) || !inRange(j, A.y+1, A.y+A.wid-2)))
                Surround.eb(Vec3(i, j, 0));
            if(inRange(i, A.x, A.x+A.len-1) && inRange(j, A.y, A.y+A.wid-1))
                Roof.eb(Vec3(i, j, 0));
        }
    each(p, Surround)
    {
        for(int i=0; i<=h; i++)
            if(A.query(Vec3(p.x, p.y, i))==5)
                cmax(A.height, i+1);
    }
    // debug(A.height);
    int cnt=0/*The number of the blocks need to complete the roof*/;
    each(p, Roof) cnt+=(A.query(Vec3(p.x, p.y, A.height))!=5);
    if(cnt>IceBlockCnt){ cout<<"SORRY CIRNO,NOT ENOUGH ICE_BLOCK(S) TO MAKE ROOF"<<endl; return; }
    if(A.height<2 || A.len<3 || A.wid<3 || (A.height==2 && A.len==3 && A.wid==3))
    { cout<<"SORRY CIRNO,HOUSE IS TOO SMALL"<<endl; return; }
    each(p, Roof) A.assign(Vec3(p.x, p.y, A.height), 5);
    IceBlockCnt-=cnt;
    
    bool fixWall=false, removeBlock=false;
    int inscnt=0, outcnt=0;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) for(int k=0; k<=h; k++)
    {
        auto cur=Vec3(i, j, k);
        if(A.query(cur)!=5) continue;
        if(CheckInside(cur)) inscnt++;
        else if(CheckOutside(cur)) outcnt++;
        else continue;
        // debug(114514);
        removeBlock=true;
        IceBlockCnt++;
        A.assign(cur, 0);
        each(dir, _3D6)
        {
            auto x=cur+dir;
            if(!CheckWall(x)) continue;
            if(isFloat(x))
            {
                IceBlockCnt++;
                A.assign(x, 0);
            }
        }
    }
    cout<<inscnt<<" ICE_BLOCK(S) INSIDE THE HOUSE NEED TO BE REMOVED"<<endl;
    cout<<outcnt<<" ICE_BLOCK(S) OUTSIDE THE HOUSE NEED TO BE REMOVED"<<endl;
    if(isFloat(Vec3(A.x+1, A.y+1, A.height))){ cout<<"SORRY CIRNO,HOUSE IS BROKEN WHEN REMOVING BLOCKS"<<endl; return; }

    each(p, Surround)
    {
        if(CheckPillar(p)) continue;
        for(int i=2; i<A.height; i++)
        {
            if(A.query(Vec3(p.x, p.y, i))==5) continue;
            if(!IceBlockCnt){ cout<<"SORRY CIRNO,NOT ENOUGH ICE_BLOCKS TO FIX THE WALL"<<endl; return; }
            fixWall=true;
            IceBlockCnt--;
            A.assign(Vec3(p.x, p.y, i), 5);
        }
    }

    cnt=0/*the number of missing blocks for h=0, h=1*/;
    each(p, Surround)
    {
        if(CheckPillar(p)) continue;
        for(int i=0; i<2; i++)
            cnt+=(A.query(Vec3(p.x, p.y, i))!=5);
    }

    vector<Door> D;
    each(p, Surround)
    {
        if(CheckPillar(p)) continue;
        int q/*height*/=(A.query(Vec3(p.x, p.y, 0))!=5)+(A.query(Vec3(p.x, p.y, 1))!=5);
        if(!q) continue;
        auto door=Door(p.x, p.y, q, cnt-q, isPerfect(p));
        each(dir, _2D4)
        {
            auto x=p+dir;
            if(!CheckPillar(x)) continue;
            for(int i=0; i<2; i++)
            {
                if(A.query(Vec3(p.x, p.y, i))!=5)
                    door.cost+=(A.query(Vec3(x.x, x.y, i))!=5);
            }
        }
        D.eb(door);
    }
    sort(all(D));
    if(D.empty() || IceBlockCnt<D.front().cost)
    { cout<<"SORRY CIRNO,NOT ENOUGH ICE_BLOCKS TO FIX THE WALL"<<endl; return; }

    auto door=D.front();
    each(t, D)
        if(IceBlockCnt>=t.cost && t.h>door.h)
        {
            door=t;
            break;
        }
    
    auto doorPos=Vec3(door.x, door.y, 0);
    each(dir, _2D4)
    {
        auto x=doorPos+dir;
        if(!CheckPillar(x)) continue;
        for(int i=0; i<A.height; i++)
        {
            if(A.query(Vec3(x.x, x.y, i))!=5
            && A.query(Vec3(doorPos.x, doorPos.y, i))!=5)
            {
                fixWall=true;
                IceBlockCnt--;
                A.assign(Vec3(x.x, x.y, i), 5);
            }
        }
    }
    each(p, Surround)
    {
        if(CheckPillar(p) || p==doorPos) continue;
        for(int i=0; i<2; i++)
        {
            if(A.query(Vec3(p.x, p.y, i))==5) continue;
            fixWall=true;
            IceBlockCnt--;
            A.assign(Vec3(p.x, p.y, i), 5);
        }
    }

    cout<<"GOOD JOB CIRNO,SUCCESSFULLY BUILT THE HOUSE"<<endl;
    bool AP=true;//All Perfect!
    if(door.h==2) cout<<"DOOR IS OK"<<endl;
    else AP=false, cout<<"HOUSE HAS NO DOOR"<<endl;
    
    for(int i=0; i<2; i++)
    {
        if(A.query(Vec3(doorPos.x, doorPos.y, i))==5)
        {
            IceBlockCnt++;
            A.assign(Vec3(doorPos.x, doorPos.y, i), 0);
        }
    }

    if(!fixWall) cout<<"WALL IS OK"<<endl;
    else AP=false, cout<<"WALL NEED TO BE FIXED"<<endl;

    cnt=0/*the number of missing blocks for pillars*/;
    each(p, Surround)
    {
        if(!CheckPillar(p)) continue;
        for(int i=0; i<A.height; i++)
        {
            // debug(A.query(Vec3(p.x, p.y, i)));
            if(A.query(Vec3(p.x, p.y, i))==5) continue;
            cnt++;
            A.assign(Vec3(p.x, p.y, i), 5);
        }
    }
    // debug(cnt);
    if(!cnt) cout<<"CORNER IS OK"<<endl;
    else AP=false, cout<<"CORNER NEED TO BE FIXED"<<endl;
    
    IceBlockCnt=max(IceBlockCnt-cnt, 0);
    cout<<"CIRNO FINALLY HAS "<<IceBlockCnt<<" ICE_BLOCK(S)"<<endl;
    AP&=((!removeBlock) & door.st);
    if(AP) cout<<"CIRNO IS PERFECT!"<<endl;
}

signed main()
{
    //SpentTime: 6hrs 9mins
	cin.tie(0)->sync_with_stdio(0);
    cin>>n>>h>>A.x>>A.y>>A.len>>A.wid>>T;
    for(string opt; T>=1; T--)
    {
        cin>>opt;
        if(opt=="ICE_BARRAGE")
        {
            int R, C, D, S;
            cin>>R>>C>>D>>S;
            IceBarrage(R, C, D, S);
        }
        else if(opt=="MAKE_ICE_BLOCK")
        {
            MakeIceBlock();
        }
        else if(opt=="PUT_ICE_BLOCK")
        {
            int R, C, H;
            cin>>R>>C>>H;
            PutIceBlock(R, C, H);
        }
        else if(opt=="REMOVE_ICE_BLOCK")
        {
            int R, C, H;
            cin>>R>>C>>H;
            RemoveIceBlock(R, C, H);
        }
        else if(opt=="MAKE_ROOF")
        {
            MakeRoof();
        }
    }
	return 0;
}
