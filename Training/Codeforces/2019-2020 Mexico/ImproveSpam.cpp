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
#define sz(s) int(s.size())
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
using namespace std;
typedef long double ld;
typedef long long lli;
typedef pair<lli,lli> ii;
typedef vector<lli> vi;


const lli mod=1e9+7;
const lli MAXN=1e4;
set<int> ans;
lli dp[MAXN];

lli getAns(vector<vector<lli>>& lists,lli current,lli l){
	if(current>l){
		ans.insert(current);
		return 1;
	}
	if(dp[current]!=-1){
		return dp[current];
	}
	lli ans=0;
	for(auto x:lists[current]){
		ans=((ans%mod)+(getAns(lists,x,l)%mod))%mod;
	}
	
	dp[current]=ans%mod;
	return dp[current];
	
}

int main() {_ 
    lli n,l,x,a;
    cin>>n>>l;
    vector<vector<lli>> lists(l+1,vector<lli>());
    ans.clear();
    memset(dp,-1,sizeof(dp));
    fore(i,1,l+1){
    	cin>>x;
    	fore(j,0,x){
    		cin>>a;
    		lists[i].pb(a);
    	}
    }
    lli res=getAns(lists,1,l);
    cout<<res<<" "<<ans.size() <<ENDL;
    
    return 0;
}
