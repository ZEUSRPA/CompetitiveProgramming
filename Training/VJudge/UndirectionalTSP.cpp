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

unordered_map<int,unordered_map<int,pair<int,vector<int>>>> dp;
vector<ii> steps={{-1,1},{0,1},{1,1}};

pair<int,vector<int>> getAns(vector<vector<int>> &matrix,int row,int col){
	if(col>=matrix[0].size()){
		return {0,{}};
	}
	if(dp.count(row) && dp[row].count(col)){
		return dp[row][col];
	}
	int ans = INT_MAX;
	vector<int> route;
	for(auto x:steps){
		int a=(row+x.first+matrix.size())%matrix.size();
		int b=col+x.second;
		auto tmp= getAns(matrix,a,b);
		if(tmp.first<ans){
			ans = tmp.first;
			route=tmp.second;
		}else if(tmp.first==ans){
			if(tmp.second<route){
				route=tmp.second;
			}
		}	
		
	}
	ans+=matrix[row][col];
	route.insert(route.begin(),row+1);
	dp[row][col]={ans,route};
	return dp[row][col];
	
}

int main() {_ 
	int n,m;
	while(cin>>n>>m){
		vector<vector<int>> matrix(n,vector<int>(m));
		dp.clear();
		fore(i,0,n){
			fore(j,0,m){
				cin>>matrix[i][j];
			}
		}
		int ans=INT_MAX;
		vector<int> bestRoute;
		fore(i,0,n){
			auto tmp = getAns(matrix,i,0);
			if(tmp.first<ans){
				ans=tmp.first;
				bestRoute=tmp.second;
			}
		}
		fore(i,0,bestRoute.size()-1){
			cout<<bestRoute[i]<<" ";
		}
		cout<<bestRoute.back()<<ENDL;
		cout<<ans<<ENDL;
	
	}
	
	
    return 0;
}
