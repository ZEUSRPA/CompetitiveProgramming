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

vector<bool> visited;
vector<int> tin;
vector<int> low;
int timer;
set<int> articulation;

void getAns(vector<vector<int>> &g, int node, int parent){
		visited[node]=true;
		tin[node]=low[node]=timer++;
		int childs=0;
		for(auto x:g[node]){
			if(x==parent)continue;
			if(visited[x]){
				low[node] = min(low[node],tin[x]);
			}else{
				getAns(g,x,node);
				low[node] = min(low[node],low[x]);
				if(low[x]>=tin[node] && parent!=-1){
					articulation.insert(node);
				}
				childs++;
			}
		}
		if(parent==-1 && childs>1){
			articulation.insert(node);
		}
		
}

vector<int> split(string s, char lim){
	vector<int> ans;
	string current = "";
	for(auto x:s){
		if(x==lim){
			ans.pb(stoi(current));
			current="";
		}else{
			current+=x;
		}
	}
	if(current.size()){
		ans.pb(stoi(current));
	}
	
	return ans;
}

int main() {_ 
    int n,node,m,y;
    string s;
    vector<int> vals;
    while(getline(cin,s)){
    	vals= split(s,' ');
    	n=vals[0];
    	if(n==0)break;
    	vector<vector<int>> g(n+1);
    	low = tin = vector<int>(n+1,-1);
    	visited = vector<bool>(n+1,false);
    	timer=0;
    	articulation.clear();
    	while(getline(cin,s)){
    		vals = split(s,' ');
    		if(vals[0]==0)break;
    		node = vals[0];
    		fore(i,1,vals.size()){
    			g[node].pb(vals[i]);
    			g[vals[i]].pb(node);
    		}
    	}
    	fore(i,1,n+1){
    		if(!visited[i]){
    			getAns(g,i,-1);
    		}
    	}
    	cout<<articulation.size()<<ENDL;
    }
    return 0;
}
