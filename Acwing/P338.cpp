#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
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
#define sz(x) int((x).size())
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
using pll=pair<ll, ll>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;

vector<pair<int, array<int, 10>>> ans={
mp(0,array<int, 10>{0,0,0,0,0,0,0,0,0,0}),
mp(1000000,array<int, 10>{488895,600001,600000,600000,600000,600000,600000,600000,600000,600000}),
mp(2000000,array<int, 10>{1088895,2200000,1200001,1200000,1200000,1200000,1200000,1200000,1200000,1200000}),
mp(3000000,array<int, 10>{1688895,2800000,2800000,1800001,1800000,1800000,1800000,1800000,1800000,1800000}),
mp(4000000,array<int, 10>{2288895,3400000,3400000,3400000,2400001,2400000,2400000,2400000,2400000,2400000}),
mp(5000000,array<int, 10>{2888895,4000000,4000000,4000000,4000000,3000001,3000000,3000000,3000000,3000000}),
mp(6000000,array<int, 10>{3488895,4600000,4600000,4600000,4600000,4600000,3600001,3600000,3600000,3600000}),
mp(7000000,array<int, 10>{4088895,5200000,5200000,5200000,5200000,5200000,5200000,4200001,4200000,4200000}),
mp(8000000,array<int, 10>{4688895,5800000,5800000,5800000,5800000,5800000,5800000,5800000,4800001,4800000}),
mp(9000000,array<int, 10>{5288895,6400000,6400000,6400000,6400000,6400000,6400000,6400000,6400000,5400001}),
mp(10000000,array<int, 10>{5888896,7000001,7000000,7000000,7000000,7000000,7000000,7000000,7000000,7000000}),
mp(11000000,array<int, 10>{7488895,8600002,7600000,7600000,7600000,7600000,7600000,7600000,7600000,7600000}),
mp(12000000,array<int, 10>{8088895,11200001,8200001,8200000,8200000,8200000,8200000,8200000,8200000,8200000}),
mp(13000000,array<int, 10>{8688895,12800001,9800000,8800001,8800000,8800000,8800000,8800000,8800000,8800000}),
mp(14000000,array<int, 10>{9288895,14400001,10400000,10400000,9400001,9400000,9400000,9400000,9400000,9400000}),
mp(15000000,array<int, 10>{9888895,16000001,11000000,11000000,11000000,10000001,10000000,10000000,10000000,10000000}),
mp(16000000,array<int, 10>{10488895,17600001,11600000,11600000,11600000,11600000,10600001,10600000,10600000,10600000}),
mp(17000000,array<int, 10>{11088895,19200001,12200000,12200000,12200000,12200000,12200000,11200001,11200000,11200000}),
mp(18000000,array<int, 10>{11688895,20800001,12800000,12800000,12800000,12800000,12800000,12800000,11800001,11800000}),
mp(19000000,array<int, 10>{12288895,22400001,13400000,13400000,13400000,13400000,13400000,13400000,13400000,12400001}),
mp(20000000,array<int, 10>{12888896,24000000,14000001,14000000,14000000,14000000,14000000,14000000,14000000,14000000}),
mp(21000000,array<int, 10>{14488895,24600001,15600001,14600000,14600000,14600000,14600000,14600000,14600000,14600000}),
mp(22000000,array<int, 10>{15088895,26200000,17200002,15200000,15200000,15200000,15200000,15200000,15200000,15200000}),
mp(23000000,array<int, 10>{15688895,26800000,19800001,15800001,15800000,15800000,15800000,15800000,15800000,15800000}),
mp(24000000,array<int, 10>{16288895,27400000,21400001,17400000,16400001,16400000,16400000,16400000,16400000,16400000}),
mp(25000000,array<int, 10>{16888895,28000000,23000001,18000000,18000000,17000001,17000000,17000000,17000000,17000000}),
mp(26000000,array<int, 10>{17488895,28600000,24600001,18600000,18600000,18600000,17600001,17600000,17600000,17600000}),
mp(27000000,array<int, 10>{18088895,29200000,26200001,19200000,19200000,19200000,19200000,18200001,18200000,18200000}),
mp(28000000,array<int, 10>{18688895,29800000,27800001,19800000,19800000,19800000,19800000,19800000,18800001,18800000}),
mp(29000000,array<int, 10>{19288895,30400000,29400001,20400000,20400000,20400000,20400000,20400000,20400000,19400001}),
mp(30000000,array<int, 10>{19888896,31000000,31000000,21000001,21000000,21000000,21000000,21000000,21000000,21000000}),
mp(31000000,array<int, 10>{21488895,31600001,31600000,22600001,21600000,21600000,21600000,21600000,21600000,21600000}),
mp(32000000,array<int, 10>{22088895,33200000,32200001,24200001,22200000,22200000,22200000,22200000,22200000,22200000}),
mp(33000000,array<int, 10>{22688895,33800000,33800000,25800002,22800000,22800000,22800000,22800000,22800000,22800000}),
mp(34000000,array<int, 10>{23288895,34400000,34400000,28400001,23400001,23400000,23400000,23400000,23400000,23400000}),
mp(35000000,array<int, 10>{23888895,35000000,35000000,30000001,25000000,24000001,24000000,24000000,24000000,24000000}),
mp(36000000,array<int, 10>{24488895,35600000,35600000,31600001,25600000,25600000,24600001,24600000,24600000,24600000}),
mp(37000000,array<int, 10>{25088895,36200000,36200000,33200001,26200000,26200000,26200000,25200001,25200000,25200000}),
mp(38000000,array<int, 10>{25688895,36800000,36800000,34800001,26800000,26800000,26800000,26800000,25800001,25800000}),
mp(39000000,array<int, 10>{26288895,37400000,37400000,36400001,27400000,27400000,27400000,27400000,27400000,26400001}),
mp(40000000,array<int, 10>{26888896,38000000,38000000,38000000,28000001,28000000,28000000,28000000,28000000,28000000}),
mp(41000000,array<int, 10>{28488895,38600001,38600000,38600000,29600001,28600000,28600000,28600000,28600000,28600000}),
mp(42000000,array<int, 10>{29088895,40200000,39200001,39200000,31200001,29200000,29200000,29200000,29200000,29200000}),
mp(43000000,array<int, 10>{29688895,40800000,40800000,39800001,32800001,29800000,29800000,29800000,29800000,29800000}),
mp(44000000,array<int, 10>{30288895,41400000,41400000,41400000,34400002,30400000,30400000,30400000,30400000,30400000}),
mp(45000000,array<int, 10>{30888895,42000000,42000000,42000000,37000001,31000001,31000000,31000000,31000000,31000000}),
mp(46000000,array<int, 10>{31488895,42600000,42600000,42600000,38600001,32600000,31600001,31600000,31600000,31600000}),
mp(47000000,array<int, 10>{32088895,43200000,43200000,43200000,40200001,33200000,33200000,32200001,32200000,32200000}),
mp(48000000,array<int, 10>{32688895,43800000,43800000,43800000,41800001,33800000,33800000,33800000,32800001,32800000}),
mp(49000000,array<int, 10>{33288895,44400000,44400000,44400000,43400001,34400000,34400000,34400000,34400000,33400001}),
mp(50000000,array<int, 10>{33888896,45000000,45000000,45000000,45000000,35000001,35000000,35000000,35000000,35000000}),
mp(51000000,array<int, 10>{35488895,45600001,45600000,45600000,45600000,36600001,35600000,35600000,35600000,35600000}),
mp(52000000,array<int, 10>{36088895,47200000,46200001,46200000,46200000,38200001,36200000,36200000,36200000,36200000}),
mp(53000000,array<int, 10>{36688895,47800000,47800000,46800001,46800000,39800001,36800000,36800000,36800000,36800000}),
mp(54000000,array<int, 10>{37288895,48400000,48400000,48400000,47400001,41400001,37400000,37400000,37400000,37400000}),
mp(55000000,array<int, 10>{37888895,49000000,49000000,49000000,49000000,43000002,38000000,38000000,38000000,38000000}),
mp(56000000,array<int, 10>{38488895,49600000,49600000,49600000,49600000,45600001,38600001,38600000,38600000,38600000}),
mp(57000000,array<int, 10>{39088895,50200000,50200000,50200000,50200000,47200001,40200000,39200001,39200000,39200000}),
mp(58000000,array<int, 10>{39688895,50800000,50800000,50800000,50800000,48800001,40800000,40800000,39800001,39800000}),
mp(59000000,array<int, 10>{40288895,51400000,51400000,51400000,51400000,50400001,41400000,41400000,41400000,40400001}),
mp(60000000,array<int, 10>{40888896,52000000,52000000,52000000,52000000,52000000,42000001,42000000,42000000,42000000}),
mp(61000000,array<int, 10>{42488895,52600001,52600000,52600000,52600000,52600000,43600001,42600000,42600000,42600000}),
mp(62000000,array<int, 10>{43088895,54200000,53200001,53200000,53200000,53200000,45200001,43200000,43200000,43200000}),
mp(63000000,array<int, 10>{43688895,54800000,54800000,53800001,53800000,53800000,46800001,43800000,43800000,43800000}),
mp(64000000,array<int, 10>{44288895,55400000,55400000,55400000,54400001,54400000,48400001,44400000,44400000,44400000}),
mp(65000000,array<int, 10>{44888895,56000000,56000000,56000000,56000000,55000001,50000001,45000000,45000000,45000000}),
mp(66000000,array<int, 10>{45488895,56600000,56600000,56600000,56600000,56600000,51600002,45600000,45600000,45600000}),
mp(67000000,array<int, 10>{46088895,57200000,57200000,57200000,57200000,57200000,54200001,46200001,46200000,46200000}),
mp(68000000,array<int, 10>{46688895,57800000,57800000,57800000,57800000,57800000,55800001,47800000,46800001,46800000}),
mp(69000000,array<int, 10>{47288895,58400000,58400000,58400000,58400000,58400000,57400001,48400000,48400000,47400001}),
mp(70000000,array<int, 10>{47888896,59000000,59000000,59000000,59000000,59000000,59000000,49000001,49000000,49000000}),
mp(71000000,array<int, 10>{49488895,59600001,59600000,59600000,59600000,59600000,59600000,50600001,49600000,49600000}),
mp(72000000,array<int, 10>{50088895,61200000,60200001,60200000,60200000,60200000,60200000,52200001,50200000,50200000}),
mp(73000000,array<int, 10>{50688895,61800000,61800000,60800001,60800000,60800000,60800000,53800001,50800000,50800000}),
mp(74000000,array<int, 10>{51288895,62400000,62400000,62400000,61400001,61400000,61400000,55400001,51400000,51400000}),
mp(75000000,array<int, 10>{51888895,63000000,63000000,63000000,63000000,62000001,62000000,57000001,52000000,52000000}),
mp(76000000,array<int, 10>{52488895,63600000,63600000,63600000,63600000,63600000,62600001,58600001,52600000,52600000}),
mp(77000000,array<int, 10>{53088895,64200000,64200000,64200000,64200000,64200000,64200000,60200002,53200000,53200000}),
mp(78000000,array<int, 10>{53688895,64800000,64800000,64800000,64800000,64800000,64800000,62800001,53800001,53800000}),
mp(79000000,array<int, 10>{54288895,65400000,65400000,65400000,65400000,65400000,65400000,64400001,55400000,54400001}),
mp(80000000,array<int, 10>{54888896,66000000,66000000,66000000,66000000,66000000,66000000,66000000,56000001,56000000}),
mp(81000000,array<int, 10>{56488895,66600001,66600000,66600000,66600000,66600000,66600000,66600000,57600001,56600000}),
mp(82000000,array<int, 10>{57088895,68200000,67200001,67200000,67200000,67200000,67200000,67200000,59200001,57200000}),
mp(83000000,array<int, 10>{57688895,68800000,68800000,67800001,67800000,67800000,67800000,67800000,60800001,57800000}),
mp(84000000,array<int, 10>{58288895,69400000,69400000,69400000,68400001,68400000,68400000,68400000,62400001,58400000}),
mp(85000000,array<int, 10>{58888895,70000000,70000000,70000000,70000000,69000001,69000000,69000000,64000001,59000000}),
mp(86000000,array<int, 10>{59488895,70600000,70600000,70600000,70600000,70600000,69600001,69600000,65600001,59600000}),
mp(87000000,array<int, 10>{60088895,71200000,71200000,71200000,71200000,71200000,71200000,70200001,67200001,60200000}),
mp(88000000,array<int, 10>{60688895,71800000,71800000,71800000,71800000,71800000,71800000,71800000,68800002,60800000}),
mp(89000000,array<int, 10>{61288895,72400000,72400000,72400000,72400000,72400000,72400000,72400000,71400001,61400001}),
mp(90000000,array<int, 10>{61888896,73000000,73000000,73000000,73000000,73000000,73000000,73000000,73000000,63000001}),
mp(91000000,array<int, 10>{63488895,73600001,73600000,73600000,73600000,73600000,73600000,73600000,73600000,64600001}),
mp(92000000,array<int, 10>{64088895,75200000,74200001,74200000,74200000,74200000,74200000,74200000,74200000,66200001}),
mp(93000000,array<int, 10>{64688895,75800000,75800000,74800001,74800000,74800000,74800000,74800000,74800000,67800001}),
mp(94000000,array<int, 10>{65288895,76400000,76400000,76400000,75400001,75400000,75400000,75400000,75400000,69400001}),
mp(95000000,array<int, 10>{65888895,77000000,77000000,77000000,77000000,76000001,76000000,76000000,76000000,71000001}),
mp(96000000,array<int, 10>{66488895,77600000,77600000,77600000,77600000,77600000,76600001,76600000,76600000,72600001}),
mp(97000000,array<int, 10>{67088895,78200000,78200000,78200000,78200000,78200000,78200000,77200001,77200000,74200001}),
mp(98000000,array<int, 10>{67688895,78800000,78800000,78800000,78800000,78800000,78800000,78800000,77800001,75800001}),
mp(99000000,array<int, 10>{68288895,79400000,79400000,79400000,79400000,79400000,79400000,79400000,79400000,77400002}),
mp(100000000,array<int, 10>{68888897,80000001,80000000,80000000,80000000,80000000,80000000,80000000,80000000,80000000})
};

signed main()
{

	cin.tie(0)->sync_with_stdio(0);
	array<int, 10> tmp={0,0,0,0,0,0,0,0,0,0};
	int l, r;
	while(cin>>l>>r, l && r)
	{
		if(l>r) swap(l, r);
		auto lnd=*prev(lower_bound(all(ans), mp(l, tmp))),
		 rnd=*lower_bound(all(ans), mp(r, tmp));
		auto lpos=lnd.fi, rpos=rnd.fi;
		auto lans=lnd.se, rans=rnd.se;
        // debug(lpos); debug(rpos);
		for(int i=l-1; i>lpos; i--)
		{
			int t=i;
			while(t) lans[t%10]++, t/=10;
		}
// 		for(auto x: lans) cout<<x<<' ';
// 		cout<<endl;
		for(int i=rpos; i>r; i--)
		{
			int t=i;
			while(t) rans[t%10]--, t/=10;
		}
		for(int i=0; i<=9; i++) tmp[i]=rans[i]-lans[i];
		for(auto x: tmp) cout<<x<<' ';
		cout<<endl;
	}
	return 0;
}
