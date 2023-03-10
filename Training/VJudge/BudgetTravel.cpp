// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define F first
#define S second
#define fore(i,a,b) for(int i = (a), ThxMK = (b); i < ThxMK; ++i)
#define pb push_back
#define ALL(s) begin(s), end(s)
#define ALLR(s) rbegin(s), rend(s)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZ(s) int(s.size())
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
using namespace std;
typedef double ld;
typedef long long lli;
typedef pair<lli,lli> ii;
typedef vector<lli> vi;

unordered_map<lli,unordered_map<ld,ld>> dp;

ld getAns(vector<pair<ld,ld>> &station, ld distance,ld tank,ld milespg,ld currentTank,lli pos){
	if(station[pos].first>=distance){
		return 0.0;
	}
	if(dp.count(pos)&&dp[pos].count(currentTank)){
		return dp[pos][currentTank];
	}
	bool si=false;
	ld autonomy=currentTank*milespg;
	if(pos==station.size()-1){
		if(autonomy>=distance-station[pos].first){
			return 0.0;
		}else{
			ld anss = (tank-currentTank)*station[pos].second;
			anss+=200.0;
			anss=round(anss);
			anss/=100.0;
			return anss;
		}
	}
	ld nexdistance = station[pos+1].first-station[pos].first;
	ld ans=99999999999999999.0;
	if(autonomy>=nexdistance){
		si=true;
		ans = min(getAns(station,distance, tank,milespg,currentTank-nexdistance/milespg,pos+1),ans);
	}
	bool other =false;
	if(!si||currentTank<=tank/2.0){
		other=true;
	}
	if(other){
		ld price = (tank-currentTank)*station[pos].second;
		price+=200.0;
		price = round(price);
		price/=100.0;

		autonomy = tank*milespg;
		ans = min(getAns(station,distance,tank,milespg,tank-nexdistance/milespg,pos+1)+price,ans);
	
	}
	dp[pos][currentTank]=ans;
	return dp[pos][currentTank];
}

int main() {_ 
	ld distance,tank,milespg,cost;
	int stations;
	int ds=1;
	while(cin>>distance){
		if(distance<0)break;

		cin>>tank>>milespg>>cost>>stations;
		vector<pair<ld,ld>> station(stations);
		fore(i,0,stations){
			cin>>station[i].first>>station[i].second;
			
		}
		ld ans = 0.0;
		if(stations>0){
			ld nexdistance = station[0].first;
			ans =getAns(station,distance,tank,milespg,tank-nexdistance/milespg,0);
		}
		ans+=cost;
		cout<<"Data Set #"<<ds++<<ENDL;
		cout<<fixed<<setprecision(2)<<"minimum cost = $"<<ans<<ENDL;
	}
    return 0;
}
