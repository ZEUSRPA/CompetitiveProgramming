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

vector<vector<int>> g;
vector<bool> visited;
vector<int> height;

int getHeight(int node){
	visited[node]=true;
	int h=1;
	for(auto x:g[node]){
		if(!visited[x]){
			h+=getHeight(x);
		}
	}
	height[node]=h;
	return height[node];
	
}

int getAns(int node,int total){
	int ans=0;
	visited[node]=true;
	for(auto x:g[node]){
		if(!visited[x]){
			ans=max(getAns(x,total),height[x]*(total-height[x]));		
		}
	}
	return ans;
}

int main() {_ 
	int n,a,b;
	cin>>n;
	n++;
	g=vector<vector<int>>(n);
	visited=vector<bool>(n,false);
	height=vector<int>(n,-1);
	fore(i,0,n-1){
		cin>>a>>b;
		g[a].pb(b);
		g[b].pb(a);
	}
	getHeight(1);
	visited=vector<bool>(n,false);
	deb(height[1]);
	cout<<getAns(1,height[1])<<ENDL;
    return 0;
}
