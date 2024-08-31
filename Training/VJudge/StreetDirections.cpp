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
vector<int> low,tin;
int timer;
set<pair<int,int>> streets;

void getAns(int node, int parent){
	visited[node]=true;
	tin[node]=low[node]=timer++;
	for(auto x:g[node]){
		if(x==parent)continue;
		if(visited[x]){
			low[node]=min(low[node],tin[x]);
			if(tin[node]>tin[x]){
				streets.insert({node,x});
			}else{
				streets.insert({x,node});
			}
		}else{
			getAns(x,node);
			low[node]=min(low[node],low[x]);
			if(low[x]>tin[node]){
				streets.insert({node,x});
				streets.insert({x,node});
			}else{
				streets.insert({node,x});
			}
		}
	}
}

int main() {_ 
	int n,m,a,b;
	int cas=1;
	while(cin>>n>>m){
		if(n==0)break;
		n++;
		g=vector<vector<int>>(n);
		visited=vector<bool>(n,false);
		tin=low=vector<int>(n,-1);
		streets.clear();
		timer=0;
		fore(i,0,m){
			cin>>a>>b;
			g[a].pb(b);
			g[b].pb(a);
			
		}
		fore(i,1,n){
			if(!visited[i]){
				getAns(i,-1);
			}
		}
		cout<<cas++<<ENDL<<ENDL;
		for(auto x:streets){
			cout<<x.first<<" "<<x.second<<ENDL;
		}
		cout<<"#"<<ENDL;
	}    
    return 0;
}
