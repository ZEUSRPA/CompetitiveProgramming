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

const int MAXN=1e5;

lli dp[MAXN];

lli getAns(vector<pair<int,string>> &targets,int mask){
	if(dp[mask]!=-1){
		return dp[mask];
	}
	lli ans=LLONG_MAX;
	bool si=false;
	fore(i,0,targets.size()){
		if((mask&(1<<i))==0){
			si=true;
			int cost = targets[i].first;
			fore(j,0,targets.size()){
				if((mask&(1<<j))){
					if(targets[j].second[i]!='0'){
						int tmpcost = targets[i].first/(targets[j].second[i]-'0');
						if(targets[i].first%(targets[j].second[i]-'0')){
							tmpcost++;
						}
						cost=min(cost,tmpcost);
					
					}
				}
			}
			ans = min(getAns(targets,(mask|(1<<i)))+cost,ans);
		}
	}
	if(!si)ans=0;
	dp[mask]=ans;
	return dp[mask];
}


int main() {_ 
	lli t,n;
	cin>>t;
	int cas=1;
	while(t--){
		cin>>n;
		memset(dp,-1,sizeof(dp));
		vector<pair<int,string>> targets(n);
		fore(i,0,n){
			cin>>targets[i].first;
		}
		fore(i,0,n){
			cin>>targets[i].second;
		}
		lli ans = getAns(targets,0);
		cout<<"Case "<<cas++<<": "<<ans<<ENDL;
	}
    return 0;
}
