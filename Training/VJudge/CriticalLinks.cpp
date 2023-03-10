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

set<pair<int,int>> bridges;
vector<bool> visited;
vector<int> low;
vector<int> tin;
vector<vector<int>> g;
int timer;

void getAns(int node, int parent){
	visited[node]=true;
	low[node]=tin[node]=timer++;
	for(auto x:g[node]){
		if(x==parent)continue;
		if(visited[x]){
			low[node]=min(low[node],tin[x]);
		}else{
			getAns(x,node);
			low[node]=min(low[node],low[x]);
			if(low[x]>tin[node]){
				bridges.insert({min(node,x),max(node,x)});
			}
		}
	}
}

int main() {_ 
    int t,n,u,v;
    cin>>t;
    string s;
    int cas=1;
    while(t--){
    	cin>>n;
    	g=vector<vector<int>>(n);
    	visited = vector<bool>(n,false);
    	tin=low=vector<int>(n,-1);
    	timer=0;
    	bridges.clear();
    	fore(i,0,n){
    		cin>>u;
    		cin>>s;
    		string aux="";
    		fore(j,1,s.size()-1){
    			aux+=s[j];
    		}
    		int nodes = stoi(aux);
    		fore(j,0,nodes){
    			cin>>v;
    			g[u].pb(v);
    			g[v].pb(u);
    		}
    	}
    	fore(i,0,n){
    		if(!visited[i]){
    			getAns(i,-1);
    		}
    	}
    	cout<<"Case "<<cas++<<":"<<ENDL;
    	cout<<bridges.size()<<" critical links"<<ENDL;
    	for(auto x:bridges){
    		cout<<x.first<<" - "<<x.second<<ENDL;
    	}
    	
    }
    return 0;
}
