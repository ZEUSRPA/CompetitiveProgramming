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

vector<int> pages;
vector<vector<int>> g;
vector<int> degree;

int getAns(int node){
	int ans = 0;
	for(auto x:g[node]){
		ans+=getAns(x);
	}
	ans+=pages[node];
	return ans;
}

int main() {_ 
	int n,m,a,b;
	cin>>n>>m;
	n++;
	pages = degree = vector<int>(n,0);
	g=vector<vector<int>>(n);
	fore(i,1,n){
		cin>>pages[i];
	}
	fore(i,0,m){
		cin>>a>>b;
		g[b].pb(a);
		degree[a]++;
	}
	vector<int> ans;
	fore(i,1,n){
		if(degree[i]==0){
			ans.pb(getAns(i));
		}
	}
	sort(ALL(ans));
	cout<<ans[0]+ans[1]<<ENDL;
    return 0;
}
