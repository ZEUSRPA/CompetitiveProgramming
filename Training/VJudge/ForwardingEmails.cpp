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
bool cycle;

int dfs(vector<vector<int>> &g, vector<int> &dp, int node,int cont){
	if(dp[node]>0){
		return dp[node];
	}
	if(dp[node]==-2){
		cycle=true;
		dp[node]=cont-1;
		return dp[node];
	}
	dp[node]=-2;
	int ans=1;
	for(auto x:g[node]){
		ans+=dfs(g,dp,x,cont+1);
		if(cycle){
			ans--;
		}
	}
	dp[node]=ans;
	return dp[node];
}


int main() {_ 
	int t,n,a,b;
	cin>>t;
	int cas=1;
	while(t--){
		cin>>n;
		n++;
		vector<vector<int>> g(n);
		vector<int> dp(n,-1);
		fore(i,1,n){
			cin>>a>>b;
			g[a].pb(b);
		}
		int ans=0;
		int pos;
		fore(i,1,n){
			cycle=false;
			int current=dfs(g,dp,i,1);
			if(current>ans){
				ans=current;
				pos=i;
			}
		}
		cout<<"Case "<<cas++<<": "<<pos<<ENDL;
		
	}
    return 0;
}
