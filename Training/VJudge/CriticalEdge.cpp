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

int timer;
vector<bool> visited;
vector<int> tin;
vector<int> low;
vector<pair<int,int>> bridges;

void getAns(vector<vector<int>> &g,int node, int parent){
	visited[node]=true;
	tin[node]=low[node]=timer++;
	for(auto x:g[node]){
		if(x==parent)continue;
		if(visited[x]){
			low[node]=min(low[node],tin[x]);
		}else{
			getAns(g,x,node);
			low[node]=min(low[node],low[x]);
			if(low[x]>tin[node]){
				bridges.pb({min(x,node),max(x,node)});
			}
		}
	}
}


int main() {_ 
	int t,n,m,a,b;
	cin>>t;
	int current=1;
	while(t--){
		cin>>n>>m;
		vector<vector<int>> g(n+1);
		visited=vector<bool>(n,false);
		low = vector<int> (n+1,-1);
		tin = vector<int> (n+1,-1);
		bridges.clear();
		timer=0;
		fore(i,0,m){
			cin>>a>>b;
			g[a].pb(b);
			g[b].pb(a);
		}
		fore(i,1,n+1){
			if(!visited[i]){
				getAns(g,i,-1);
			}
		}
		sort(ALL(bridges));
		cout<<"Caso #"<<current++<<ENDL;
		if(bridges.size()){
			cout<<bridges.size()<<ENDL;
			fore(i,0,bridges.size()){
				cout<<bridges[i].first<<" "<<bridges[i].second<<ENDL;
			}
		
		}else{
			cout<<"Sin bloqueos"<<ENDL;
		}
	}
    return 0;
}
