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

void getAns(int node,string& ans){
	queue<int> nex;
	nex.push(node);
	while(nex.size()){
		int current=nex.front();
		nex.pop();
		ans[current-1]='B';
		for(auto x:g[current]){
			if(!visited[x]){
				visited[x]=true;
				nex.push(x);
			}
		}
	}
}

int main() {_ 
	int n,m,a,b;
	cin>>n>>m;
	n++;
	g=vector<vector<int>>(n);
	visited=vector<bool>(n,false);
	fore(i,0,m){
		cin>>a>>b;
		g[a].pb(b);
		g[b].pb(a);
		
	}
	string ans(n-1,'A');
	ans[n-2]='A';
	ans[n-3]='B';
	visited[n-1]=true;
	visited[n-2]=true;
	getAns(n-2,ans);
	cout<<ans<<ENDL;
    return 0;
}
