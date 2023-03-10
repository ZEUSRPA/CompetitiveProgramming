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
vector<int> tin,low;
int timer;
set<int> articulations;

void getAns(int node, int parent){
	visited[node] = true;
	tin[node]=low[node]=timer++;
	int childs = 0;
	for(auto x:g[node]){
		if(x==parent)continue;
		if(visited[x]){
			low[node]=min(low[node],tin[x]);
		}else{
			getAns(x,node);
			low[node]=min(low[node],low[x]);
			if(parent!=-1 && low[x]>=tin[node]){
				articulations.insert(node);
			}
			childs++;
		}
	}
	if(parent==-1&&childs>1){
		articulations.insert(node);
	}
}



int main() {_ 
	int n,m,a,b;
	while(cin>>n>>m){
		if(n==0)break;
		n++;
		g = vector<vector<int>>(n);
		tin=low=vector<int>(n,-1);
		visited=vector<bool>(n,false);
		timer=0;
		articulations.clear();
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
		cout<<articulations.size()<<ENDL;

		
	}	
    return 0;
}
