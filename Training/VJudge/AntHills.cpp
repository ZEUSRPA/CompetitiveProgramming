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
vector<int> low;
vector<int> tin;
set<int> articulations;
int timer;

void getAns(int node, int parent){
	visited[node]=true;
	tin[node]=low[node]=timer++;
	int childs=0;
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
    int t,n,m,a,b;
    cin>>t;
    int cas=1;
    while(t--){
    	cin>>n>>m;
    	n++;
    	g=vector<vector<int>>(n);
    	visited=vector<bool>(n,false);
    	low=tin=vector<int>(n,-1);
    	timer=0;
    	fore(i,0,m){
    		cin>>a>>b;
    		g[a].pb(b);
    		g[b].pb(a);
    	}
    	articulations.clear();
    	fore(i,1,n){
    		if(!visited[i]){
    			getAns(i,-1);
    		}
    	}
    	cout<<"Case "<<cas++<<": "<<articulations.size()<<ENDL;
    }
    return 0;
}
