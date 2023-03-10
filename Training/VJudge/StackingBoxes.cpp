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

bool cmp(vector<int> &a,vector<int> &b){
	fore(i,0,a.size()){
		if(a[i]>=b[i])return false;
	}
	return true;
}

unordered_map<int,vector<int>> dp;


vector<int> getAns(vector<vector<int>> &boxes,int mask,int pos){
		if(dp.count(pos)){
			return dp[pos];
		}
		
		vector<int> ans;
		vector<int> tmp;

		fore(i,0,boxes.size()){
			if(cmp(boxes[pos],boxes[i])){
				tmp = getAns(boxes,mask,i);
				if(tmp.size()>ans.size()){
					ans=tmp;
				}
			}
		}
		tmp.clear();
		tmp.pb(pos);
		for(auto x:ans){
			tmp.pb(x);
		}
		dp[pos]=tmp;
		return dp[pos];
}

int main() {_ 
	int n,k;
	
	while(cin>>n>>k){
		vector<vector<int>> boxes(n,vector<int>(k));
		dp.clear();
		fore(i,0,n){
			fore(j,0,k){
				cin>>boxes[i][j];
			}
			sort(ALL(boxes[i]));
		}
		vector<int> order;
		vector<int> best;
		fore(i,0,boxes.size()){
			order = getAns(boxes,0,i);	
			if(order.size()>best.size()){
				best=order;
			}	
		}
		cout<<best.size()<<ENDL;
		fore(i,0,best.size()-1){
			cout<<best[i]+1<<" ";
		}
		cout<<best.back()+1<<ENDL;
		
		
	}
	
    return 0;
}
