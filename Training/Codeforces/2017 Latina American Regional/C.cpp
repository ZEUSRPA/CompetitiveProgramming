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

int main() {_
	int k,n;
	cin>>k>>n;
	vector<int> nums(k+1);
	fore(i,0,n){
		cin>>a;
		nums[a]++;
	}
	unordered_map<int,vector<int>> aux;
	fore(i,1,k+1){
		aux[nums[i]].pb(i);
	}
	string ans = "";
	if(aux.size()>3){
		aux="*";
	}else{
		for(auto x:aux){
			
		}
	}
    return 0;
}
