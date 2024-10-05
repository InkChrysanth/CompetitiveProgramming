#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define PB push_back
#define EB emplace_back
#define rep(i,n,m) for(ll i = (n); i < (ll)(m); i++)
#define rrep(i,n,m) for(ll i = (ll)(m) - 1; i >= (ll)(n); i--)
using ll = long long;
using ld = long double;
const ll INF = 1e18;
template<typename T1, typename T2>bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
template<typename T1, typename T2>bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}

vector<ll>z_algorithm(string s){
  ll n = s.size();
  vector<ll>ret(n,0);
  ret[0] = n;
  ll p = 1,len = 0;
  while(p < n){
    while(p+len < n && s[len] == s[p+len])len++;
    ret[p] = len;
    if(len == 0){p++; continue;}
    ll k = 1;
    while(p+k < n && k+ret[k] < len)ret[p+k] = ret[k], k++;
    p += k, len -= k;
  }
  return ret;
}
struct FastSet{
  using ull = unsigned long long;
  static constexpr unsigned B = 64;
  int n,lg;
  vector<vector<ull>> seg;
  FastSet(int _n) : n(_n){
    do{
      seg.push_back(vector<ull>((_n + B - 1) / B));
      _n = (_n + B - 1) / B;
    } while (_n > 1);
    lg = seg.size();
  }
  bool operator[](int i) const {
    return (seg[0][i / B] >> (i % B) & 1) != 0;
  }
  void set(int i)
  {
    for(int h = 0; h < lg; h++){
      seg[h][i / B] |= 1ULL << (i % B);
      i /= B;
    }
  }
  void reset(int i)
  {
    for(int h = 0; h < lg; h++){
      seg[h][i / B] &= ~(1ULL << (i % B));
      if (seg[h][i / B])
        break;
      i /= B;
    }
  }
  int next(int i){
    for(int h = 0;h < lg; h++){
      if (i / B == seg[h].size())
        break;
      ull d = seg[h][i / B] >> (i % B);
      if (!d){
        i = i / B + 1;
        continue;
      }
      i += __builtin_ctzll(d);
      for (int g = h - 1;g >= 0;g--){
        i *= B;
        i += __builtin_ctzll(seg[g][i / B]);
      }
      return i;
    }
    return n;
  }
};
int main(){
  freopen("proud.in","r",stdin);
  freopen("proud.out","w",stdout);
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  string s;cin>>s;
  int n=s.size();
  auto zv=z_algorithm(s);
  vector<vector<int>>pos(n+1);
  rep(i,0,n)pos[zv[i]].PB(i);
  FastSet st(n);
  rep(i,0,n)if(zv[i]>=1)st.set(i);
  vector<int>dp(n+1,1e9);
  dp[0]=0;
  rep(i,1,n+1){
    chmin(dp[i],dp[i-1]+1);
    if(i==n){
      cout<<dp[i]<<endl;
      break;
    }
    int now=dp[i]+1;
    int idx=i;
    while(1){
      int nxt=st.next(idx);
      if(nxt==n)break;
      now+=nxt-idx+1;
      idx=nxt+i;
      chmin(dp[idx],now);
    }
    for(auto z:pos[i])st.reset(z);
  }
  return 0;
}