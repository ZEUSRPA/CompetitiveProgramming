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

vector<vector<int>> g;
vector<vector<bool>> visited;


void solve(int current,string &currents,int tot){
	if(tot==8){
		cout<<currents<<ENDL;
		return;
	}
	for(auto x:g[current]){
		if(visited[current][x]==false){
			visited[current][x]=true;
			visited[x][current]=true;
			currents+=to_string(x);
			solve(x,currents,tot+1);
			currents.pop_back();
			visited[current][x]=false;
			visited[x][current]=false;
		}
	}
}

int main() {_ 
    g = vector<vector<int>>(6,vector<int>());
    visited = vector<vector<bool>>(6,vector<bool>(6,false));
    g[1].pb(2);
    g[1].pb(3);
    g[1].pb(5);
    
    g[2].pb(1);
    g[2].pb(3);
    g[2].pb(5);
    
    g[3].pb(1);
    g[3].pb(2);
    g[3].pb(4);
    g[3].pb(5);
    
    g[4].pb(3);
    g[4].pb(5);
    
    g[5].pb(1);
    g[5].pb(2);
    g[5].pb(3);
    g[5].pb(4);
    string currents="1";
    solve(1,currents,0);
    return 0;
}
